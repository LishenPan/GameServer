////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/26
// Describe:ZMQʵ�ֵ���Ϣ�ܵ��ӿ���
////////////////////////////////////////////////////////////////////////
#ifndef _MESSAGEPIPE_H_
#define _MESSAGEPIPE_H_

#include <vector>
#include <string>
#include <map>
#include "zmq.h"
#include "juce_core/juce_core.h"

typedef struct MessagePipeInfo_s
{
	std::string strMyThreadName;
	std::vector<std::string> vecOtherThreadNames;
}
MessagePipeInfo_t;

//��Ϣ�ܵ���������
//ֻ��zmq_context�ĵ�����װ
//��һ�ε��ñ��������߳�
class CMessagePipeContext
{
public:
	CMessagePipeContext();
	~CMessagePipeContext();
public:
	juce_DeclareSingleton_SingleThreaded(CMessagePipeContext, true);
	void* GetContext() { return m_pContext; }
private:
	void* m_pContext;
};

class CMessagePipe
{
public:
	CMessagePipe();
	virtual ~CMessagePipe();
public:
	void Release() { delete this; }
	static CMessagePipe* CreateNew() { return new CMessagePipe; }
	bool Create(MessagePipeInfo_t* pInfo);
	zmq_msg_t* GetPipeMessage();
	void ReleasePipeMessage();
	bool SendPipeMessage(const char* szThreadName, zmq_msg_t* pMsg);
	void Shutdown();
	bool Startup();

private:
	void* QuerySocket(const char* szThreadName);

private:
	//��Ϊzmq_poll()���ܵĲ��������飬�������ﲻ��vector
	zmq_pollitem_t* m_arrPollItems;
	typedef std::map<std::string, void*> SOCKET_MAP;
	SOCKET_MAP m_mapSockets;
	int m_nPollIndex;
	int m_nSocketNum;
	zmq_msg_t m_stMessage;
	std::string m_strName;
};

#endif	//end of define _MESSAGEPIPE_H_