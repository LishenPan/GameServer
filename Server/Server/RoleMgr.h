////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/08/19
// Describe:��ɫ������
////////////////////////////////////////////////////////////////////////
#ifndef _ROLEMGR_H_
#define _ROLEMGR_H_

#include "BaseDefine.h"
#include "Role.h"

//��ɫ������
//����������������������ֻ��һ����������Ľӿ���
//�����ɫ����ʵ���ϻ��Ƿֲ��ڸ������͵Ľ�ɫ��ר�й������У���UserMgr,NpcMgr��
class CRoleMgr
{
private:
	CRoleMgr();
	~CRoleMgr();
public:
	juce_DeclareSingleton_SingleThreaded(CRoleMgr, true);
	bool Create();
	bool AddRole(CRole* pRole);
	CRole* QueryRole(OBJID idRole, OBJECT_TYPE eObjectType);
	void DelRole(CRole* pRole);
	void DelRole(OBJID idRole, OBJECT_TYPE eObjectType);
};

#endif	//end of define _ROLEMGR_H_