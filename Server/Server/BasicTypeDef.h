////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/07/16
// Describe:�������Ͷ���
////////////////////////////////////////////////////////////////////////
#ifndef _BASICTYPEDEF_H_
#define _BASICTYPEDEF_H_

#include <string>
#include <set>
#include "BaseDefine.h"
#include "TimeFormatter.h"
#include "GameObject.h"

#define ACCOUNT_USER_AMOUNT_LIMIT		5

#define CLIENT_INFO_TIMEOUT_PERIOD		60

typedef struct ClientInfo_s
{
	OBJID64 idAccount;			//�˺�ID
	OBJID64 idUser;				//��¼���ID
	std::set<OBJID> setRoleIds;	//��ɫID
	OBJID64 idPeer;				//�Զ˵�GUID
	std::string strIP;			//IP��ַ
	bool bVerified;				//�˷��Ƿ�����֤
	time_t tCreateTime;			//����ʱ��
	std::string strSessionId;	//SessionID

	ClientInfo_s()
	{
		idAccount = ID_NONE;
		idPeer = ID_NONE;
		bVerified = false;
		tCreateTime = CTimeFormatter::TimeGet(TIME_SECOND);
	}

	bool IsValidRoleId(OBJID idRole)
	{
		return setRoleIds.find(idRole) != setRoleIds.end();
	}

	bool IsTimeOut()
	{
		if (tCreateTime + CLIENT_INFO_TIMEOUT_PERIOD <= CTimeFormatter::TimeGet(TIME_SECOND))
		{
			return true;
		}

		return false;
	}
}ClientInfo_t;

typedef struct UserParm_s
{
	OBJID64 idAccount;
	OBJID idUser;
	OBJID64 idPeer;
	std::string strIP;
}UserParm_t;

class CUser;
typedef std::set<CUser*> USER_SET;

#endif	//end of define _BASICTYPEDEF_H_