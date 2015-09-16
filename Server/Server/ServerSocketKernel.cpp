////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/29
// Describe:
////////////////////////////////////////////////////////////////////////
#include <vector>
#include "ServerSocketKernel.h"
#include "time.h"
#include "GameServerDef.h"
#include "INIReader.h"
#include "MsgHandler.h"

juce_ImplementSingleton_SingleThreaded(CServerSocketKernel);

CServerSocketKernel::CServerSocketKernel() : IKernel(THREAD_INDEX_SERVER_SOCKET)
{
	m_pIntfPeer = NULL;
	m_bufMsg = NULL;
}

CServerSocketKernel::~CServerSocketKernel()
{
	for (CLIENT_MAP::iterator it = m_mapClient.begin(); it != m_mapClient.end(); ++it)
	{
		SAFE_RELEASE(it->second);
	}

	if (m_pIntfPeer)
	{
		RakPeerInterface::DestroyInstance(m_pIntfPeer);
	}

	SAFE_DELETE(m_bufMsg);

	CServerSocketKernel::clearSingletonInstance();
}

void CServerSocketKernel::OnTimer()
{

}

void CServerSocketKernel::OnTimeTrigger(const TimeTrigger_t& pTrigger)
{

}

bool CServerSocketKernel::Create()
{
	bool bSucc = IKernel::Create();
	CHECK_RETURN(bSucc, false);

	m_bufMsg = new char[MSGBUF_SIZE];
	CHECK_RETURN(m_bufMsg, false);

	m_pIntfPeer = RakPeerInterface::GetInstance();
	CHECK_RETURN(m_pIntfPeer, false);

	INIReader objIni(CONFIG_FILE_NAME);
	int nMaxClient = objIni.GetInteger(GAME_SERVER_SOCKET_SECTION, GAME_SERVER_SOCKET_MAXCLIENT, 0);
	int nPort = objIni.GetInteger(GAME_SERVER_SOCKET_SECTION, GAME_SERVER_SOCKET_PORT, 0);

	CHECK_RETURN(nMaxClient > 0 && nPort > 0, false);

	m_pIntfPeer->Startup(nMaxClient, &RakNet::SocketDescriptor(nPort, NULL), 1);
	m_pIntfPeer->SetMaximumIncomingConnections(nMaxClient);

	return true;
}

bool CServerSocketKernel::RecvClientMessage()
{
	CHECK_RETURN(m_pIntfPeer, false);
	Packet* pPacket = m_pIntfPeer->Receive();
	if (pPacket)
	{
		if (pPacket->length > 0)
		{
			//ʹ��protobuf�����յ��ı��ģ�����ܽ����ɹ���˵�����Զ�������ݰ����������RakNet��Ԥ�����
			CMsgNetwork msgNetwork;
			if (msgNetwork.ParseFromArray(pPacket->data, pPacket->length))
			{
				//�����Ϣ���ĸ��ͻ��˷�����
				OBJID64 idClient = pPacket->guid.g;
				CClient* pClient = this->QueryClient(idClient);
				if (pClient)
				{
					pClient->SendPipeMsg(&msgNetwork);
				}
				else
				{
					ASSERT2(0, idClient);
				}
			}
			else
			{
				uint8_t u8MsgId = pPacket->data[0];
				switch (u8MsgId)
				{
				case ID_NEW_INCOMING_CONNECTION:
				{
					this->AddClient(pPacket);
				}
				break;
				case ID_CONNECTION_LOST:
				{
					//TO-DO:֪ͨ�����̣߳����Ӷ�ʧ
					this->NotifyClientDisconnected(pPacket->guid.g);
					this->CloseConnection(pPacket->guid.g);
				}
				break;
				default:
					break;
				}
			}
		}
		m_pIntfPeer->DeallocatePacket(pPacket);
	}

	return true;
}

void CServerSocketKernel::OnRun()
{
DEBUG_TRY
	//�������հ�
	this->RecvClientMessage();

	//����Ϣ�ܵ��հ�
	this->RecvPipeMessage();
DEBUG_CATCH
}

CClient* CServerSocketKernel::QueryClient(OBJID64 idClient)
{
	MAP_FIND_IMPL(m_mapClient, idClient, CLIENT_MAP::iterator);
}

void CServerSocketKernel::RemoveClient(OBJID64 idClient)
{
	CHECK(idClient);

	CClient* pClient = this->QueryClient(idClient);
	if (pClient == NULL)
	{
		return;
	}

	SAFE_RELEASE(pClient);
	m_mapClient.erase(idClient);
}

void CServerSocketKernel::Release()
{
	CServerSocketKernel::deleteInstance();
}

bool CServerSocketKernel::RecvPipeMessage()
{
	if (m_pPipe == NULL)
	{
		return false;
	}

	zmq_msg_t* pMsg = m_pPipe->GetPipeMessage();
	if (pMsg == NULL)
	{
		return false;
	}

	CMsgNetwork msgNetwork;
	bool bSucc = msgNetwork.ParseFromArray(zmq_msg_data(pMsg), zmq_msg_size(pMsg));
	if (bSucc)
	{
		//������ڲ�ͨ����Ϣ���������������ת�����ͻ���
		if (msgNetwork.has_msginproc())
		{
			IMsgHandler::ProcessMessage(&msgNetwork);
		}
		else
		{
			::google::protobuf::RepeatedField< ::google::protobuf::uint64 > idPeers(msgNetwork.idpeer());
			bool bBroadcast = msgNetwork.bbroadcast();
			//����ǰ���ѿͻ��˲���Ҫ����Ϣ�����
			msgNetwork.clear_idpeer();
			msgNetwork.clear_bbroadcast();

			IF_NOT(msgNetwork.SerializeToArray(m_bufMsg, MSGBUF_SIZE))
			{
				return false;
			}

			if (bBroadcast)
			{
				m_pIntfPeer->Send(m_bufMsg, msgNetwork.ByteSize(), MEDIUM_PRIORITY, RELIABLE_ORDERED, 0, UNASSIGNED_SYSTEM_ADDRESS, true);
			}
			else
			{
				for (int i = 0; i < idPeers.size(); ++i)
				{
					CClient* pClient = this->QueryClient(idPeers.Get(i));
					if (pClient == NULL)
					{
						continue;
					}

					m_pIntfPeer->Send(m_bufMsg, msgNetwork.ByteSize(), MEDIUM_PRIORITY, RELIABLE_ORDERED, 0, pClient->GetSystemAddr(), false);
				}
			}
		}
	}

	m_pPipe->ReleasePipeMessage();

	return true;
}

bool CServerSocketKernel::AddClient(RakNet::Packet* pPacket)
{
	CHECK_RETURN(pPacket, false);
	CHECK_RETURN(this->QueryClient(pPacket->guid.g) == NULL, false);

	CClient* pClient = CClient::CreateNew();
	IF_NOT(pClient && pClient->Create(pPacket))
	{
		SAFE_RELEASE(pClient);

		return false;
	}

	m_mapClient.insert(std::make_pair(pClient->GetID(), pClient));

	return true;
}

void CServerSocketKernel::CloseConnection(OBJID64 idClient)
{
	CHECK(idClient);

	m_pIntfPeer->CloseConnection(RakNet::RakNetGUID(idClient), true);
	this->RemoveClient(idClient);
}

void CServerSocketKernel::NotifyClientDisconnected(OBJID64 idClient)
{
	CHECK(idClient);

	CClient* pClient = this->QueryClient(idClient);
	CHECK(pClient);

	//��δ��¼��GameKernel���Ͳ���֪ͨ��
	if (pClient->GetIdxThreadSendTo() != THREAD_INDEX_GAME)
	{
		return;
	}

	CMsgNetwork msgNetwork;
	CMsgInproc* pMsgInproc = msgNetwork.mutable_msginproc();
	CHECK(pMsgInproc);
	pMsgInproc->set_naction(INPROCACT_GAME_USER_DISCONNECTED);

	pClient->SendPipeMsg(&msgNetwork);
}

