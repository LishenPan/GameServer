////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/07/09
// Describe:������н�ɫѡ����Ϣ
////////////////////////////////////////////////////////////////////////
#ifndef _MSGROLESELECTHANDLER_H_
#define _MSGROLESELECTHANDLER_H_

#include "MsgHandler.h"

class CMsgRoleSelectHandler : public IMsgHandler
{
public:
	CMsgRoleSelectHandler();
	virtual void Process(CMsgNetwork* pMsgNetwork);
private:
	static CMsgRoleSelectHandler s_Handler;
};

#endif	//end of define _MSGROLESELECTHANDLER_H_