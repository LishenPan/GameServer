////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/07/15
// Describe:
////////////////////////////////////////////////////////////////////////
#include "UserMgr.h"
#include "MsgNetwork.pb.h"
#include "StrDef.h"
#include "GameKernel.h"
#include "MemRecordset.h"

juce_ImplementSingleton_SingleThreaded(CUserMgr);


CUserMgr::CUserMgr()
{

}

CUserMgr::~CUserMgr()
{
	for (USER_FKMAP::CIterator it = m_mapOnlineUsers.Begin(); it != m_mapOnlineUsers.End(); ++it)
	{
		USER_FKMAP::FKMapValueType_t* pValueType = *it;
		if (pValueType == NULL)
		{
			continue;
		}
		SAFE_RELEASE(pValueType->pObject);
	}

	for (USER_FKMAP::CIterator it = m_mapOfflineUsers.Begin(); it != m_mapOfflineUsers.End(); ++it)
	{
		USER_FKMAP::FKMapValueType_t* pValueType = *it;
		if (pValueType == NULL)
		{
			continue;
		}
		SAFE_RELEASE(pValueType->pObject);
	}
}

bool CUserMgr::Create()
{
	return true;
}

CUser* CUserMgr::CreateUser(const UserParm_t& rUserParm)
{
	CUser* pUser = CUser::CreateNew();
	IF_NOT(pUser && pUser->Create(rUserParm))
	{
		SAFE_RELEASE(pUser);
		return NULL;
	}

	return pUser;
}

void CUserMgr::ReadyToLoginUser(const UserParm_t& rUserParm)
{
	CHECK(rUserParm.idAccount);
	CHECK(rUserParm.idUser);
	CHECK(rUserParm.idPeer);
	CHECK(!rUserParm.strIP.empty());

	//ͬһ��PeerId
	CUser* pUser = this->QueryOnlineUserByPeerId(rUserParm.idPeer);
	if (pUser)
	{
		//����������������ϳ������߼������ˣ�����ɫ�ǳ�����ɫѡ�񣬷���ѡ�˻�������̣�
		IF_NOT (pUser->GetID() == rUserParm.idUser)
		{
			this->SendErrorMsgByPeerId(rUserParm.idPeer, ERRACT_LOGIN_FAILED, STRDEF_REPEAT_LOGIN);
			this->KickoutUserByPeerId(rUserParm.idPeer);
		}
		return;
	}

	//TO-DO:ͬһ���˺��б�Ľ�ɫ��¼���ȽϿ��ܵ�����Ǳ������ˣ����ɽ�ɫ�������߼��ϣ��ɵ����ӹرյ�
	pUser = this->QueryOnlineUserByAccountId(rUserParm.idAccount);
	if (pUser)
	{
		this->KickoutUser(pUser->GetID());
		this->DeleteOnlineUser(pUser->GetID());

		return;
	}

	//��������ߣ��ߵ���ǰ��Ҳ����������
	pUser = this->QueryOnlineUser(rUserParm.idUser);
	if (pUser)
	{
		this->SendErrorMsgByPeerId(pUser->GetPeerID(), ERRACT_LOGIN_FAILED, STRDEF_REPEAT_LOGIN);
		this->KickoutUserByPeerId(pUser->GetPeerID());
		pUser->SetPeerID(rUserParm.idPeer);
		pUser->SetIP(rUserParm.strIP);
		this->LoginUser(pUser);
		
		return;
	}

	//��������ߣ����ڻ����У�����ҽ�������Ҽ���
	pUser = this->QueryOfflineUser(rUserParm.idUser);
	if (pUser)
	{
		pUser->SetPeerID(rUserParm.idPeer);
		pUser->SetIP(rUserParm.strIP);
		this->LoginUser(pUser);

		return;
	}

	//�ڴ���û�У�Ҫ��DBKernel��������
	CMsgNetwork msg;
	CMsgInproc* pMsgInproc = msg.mutable_msginproc();
	pMsgInproc->set_naction(INPROCACT_DB_LOAD_USER);
	pMsgInproc->set_idrole(rUserParm.idUser);
	pMsgInproc->add_u64data(rUserParm.idAccount);
	pMsgInproc->add_u64data(rUserParm.idPeer);
	pMsgInproc->add_strdata(rUserParm.strIP);

	CGameKernel::getInstance()->SendPipeMessage(THREAD_INDEX_DATABASE, &msg);
}

CUser* CUserMgr::QueryOnlineUser(OBJID idUser)
{
	return m_mapOnlineUsers.GetObjectByKey1(idUser);
}

CUser* CUserMgr::QueryOfflineUser(OBJID idUser)
{
	return m_mapOfflineUsers.GetObjectByKey1(idUser);
}

CUser* CUserMgr::QueryOfflineUserByAccountId(OBJID64 idAccount)
{
	return m_mapOfflineUsers.GetObjectByKey3(idAccount);
}

CUser* CUserMgr::QueryOnlineUserByAccountId(OBJID64 idAccount)
{
	return m_mapOnlineUsers.GetObjectByKey3(idAccount);
}

CUser* CUserMgr::QueryOnlineUserByName(std::string strName)
{
	return m_mapOnlineUsers.GetObjectByKey2(strName);
}

CUser* CUserMgr::QueryOfflineUserByName(std::string strName)
{
	return m_mapOfflineUsers.GetObjectByKey2(strName);
}

CUser* CUserMgr::QueryOnlineUserByPeerId(OBJID64 idPeer)
{
	return m_mapOnlineUsers.GetObjectByKey4(idPeer);
}

CUser* CUserMgr::QueryOfflineUserByPeerId(OBJID64 idPeer)
{
	return m_mapOfflineUsers.GetObjectByKey4(idPeer);
}

void CUserMgr::KickoutUser(OBJID64 idUser)
{
	CHECK(idUser);
	CUser* pUser = this->QueryOnlineUser(idUser);
	CHECK(pUser);

	OBJID64 idPeer = pUser->GetPeerID();
	this->KickoutUserByPeerId(idPeer);
}

void CUserMgr::KickoutUserByPeerId(OBJID64 idPeer)
{
	CHECK(idPeer);

	CMsgNetwork msg;
	msg.add_idpeer(idPeer);
	CMsgInproc* pMsgInproc = msg.mutable_msginproc();
	CHECK(pMsgInproc);

	pMsgInproc->set_naction(INPROCACT_SS_CLOSE_CONNECTION);
	CGameKernel::getInstance()->SendPipeMessage(THREAD_INDEX_SERVER_SOCKET, &msg);
}

void CUserMgr::SendErrorMsg(OBJID64 idUser, uint32_t nAction, const char* szReason, uint32_t nErrorCode /*= 0*/)
{
	CHECK(idUser);
	CUser* pUser = this->QueryOnlineUser(idUser);
	CHECK(pUser);

	OBJID64 idPeer = pUser->GetPeerID();
	this->SendErrorMsgByPeerId(idPeer, nAction, szReason, nErrorCode);
}

void CUserMgr::SendErrorMsgByPeerId(OBJID64 idPeer, uint32_t nAction, const char* szReason, uint32_t nErrorCode /*= 0*/)
{
	CHECK(idPeer);
	CHECK(nAction != ERRACT_NONE);

	CMsgNetwork msg;
	msg.add_idpeer(idPeer);
	CMsgError* pMsgError = msg.mutable_msgerror();
	CHECK(pMsgError);
	pMsgError->set_naction(nAction);
	pMsgError->set_strreason(szReason);
	if (nErrorCode != 0)
	{
		pMsgError->set_nerrorcode(nErrorCode);
	}

	CGameKernel::getInstance()->SendPipeMessage(THREAD_INDEX_SERVER_SOCKET, &msg);
}

bool CUserMgr::CreateNewUser(const UserParm_t& rParm)
{
	CHECK_RETURN(rParm.idUser, false);

	CUser* pUser = this->CreateUser(rParm);
	IF_NOT(pUser)
	{
		SAFE_RELEASE(pUser);
		CMemRecordset::getInstance()->ReleaseRecordset(rParm.idUser);
		return false;
	}
	
	return this->LoginUser(pUser);
}

bool CUserMgr::LoginUser(CUser* pUser)
{
	this->DeleteOfflineUser(pUser->GetID());
	this->AddOnlineUser(pUser);

	pUser->CreateOK();
	CMemRecordset::getInstance()->ReleaseRecordset(pUser->GetID());

	pUser->SendUserInfo();

	return true;
}

void CUserMgr::DeleteOnlineUser(OBJID idUser)
{
	CHECK(idUser);

	CUser* pUser = this->QueryOnlineUser(idUser);
	if (pUser == NULL)
	{
		return;
	}

	m_mapOnlineUsers.DelObjectByKey1(idUser);
	this->AddOfflineUser(pUser);
}

void CUserMgr::DeleteOnlineUserByAccountId(OBJID idAccount)
{
	CHECK(idAccount);

	m_mapOnlineUsers.DelObjectByKey3(idAccount);
}

bool CUserMgr::AddOnlineUser(CUser* pUser)
{
	CHECK_RETURN(pUser, false);

	return m_mapOnlineUsers.AddObject(pUser->GetID(), pUser->GetName(), pUser->GetAccountID(), pUser->GetPeerID(), pUser);
}

void CUserMgr::AddOfflineUser(CUser* pUser)
{
	CHECK(pUser);

	m_mapOfflineUsers.AddObject(pUser->GetID(), pUser->GetName(), pUser->GetAccountID(), pUser->GetPeerID(), pUser);
}

void CUserMgr::BroadcastMsg(CMsgNetwork* pMsgNetwork)
{
	CHECK(pMsgNetwork);

	pMsgNetwork->set_bbroadcast(true);

	CGameKernel::getInstance()->SendPipeMessage(THREAD_INDEX_SERVER_SOCKET, pMsgNetwork);
}

void CUserMgr::DeleteOfflineUser(OBJID idUser)
{
	CHECK(idUser);

	CUser* pUser = this->QueryOfflineUser(idUser);
	if (pUser == NULL)
	{
		return;
	}

	m_mapOfflineUsers.DelObjectByKey1(idUser);
}

void CUserMgr::OnTimer()
{
	for (USER_FKMAP::CIterator it = m_mapOnlineUsers.Begin(); it != m_mapOnlineUsers.End(); ++it)
	{
		USER_FKMAP::FKMapValueType_t* pValueType = *it;
		if (pValueType == NULL)
		{
			continue;
		}

		if (pValueType->pObject == NULL)
		{
			continue;
		}

		pValueType->pObject->OnTimer();
	}

	for (USER_FKMAP::CIterator it = m_mapOfflineUsers.Begin(); it != m_mapOfflineUsers.End(); ++it)
	{
		USER_FKMAP::FKMapValueType_t* pValueType = *it;
		if (pValueType == NULL)
		{
			continue;
		}

		if (pValueType->pObject == NULL)
		{
			continue;
		}

		pValueType->pObject->OnTimer();
	}
}
