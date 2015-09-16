////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/07/08
// Describe:��ɫ�Ļ���
////////////////////////////////////////////////////////////////////////
#ifndef _ROLE_H_
#define _ROLE_H_

#include "BaseDefine.h"
#include "SceneMovable.h"
#include "DbTableDef.h"
#include "RoleTypeSet.h"
#include "BasicTypeDef.h"

//�Ա�
enum ROLE_GENDER_TYPE
{
	GENDER_MALE = 0,//����
	GENDER_FEMALE = 1,//Ů��
};

//ְҵ
enum ROLE_PROFESSION_TYPE
{
	PROFESSION_NONE = 0,	//��Ч
	PROFESSION_WARRIOR = 1000,//սʿ
	PROFESSION_MAGE = 2000,//��ʦ
};

class CRole : public CSceneMovable
{
protected:
	CRole(OBJECT_TYPE eType);
	virtual ~CRole();
public:
	virtual OBJID32 GetRoleTypeId();
	virtual CRoleTypeData* GetRoleType();
	virtual int GetMaxLevel();
public:
	virtual const char* GetName() = 0;
	virtual float GetLength() = 0;
	virtual float GetWidth() = 0;
	virtual float GetHeight() = 0;
	virtual uint32_t GetFace() = 0;
	virtual uint32_t GetHair() = 0;
	virtual int GetLife() = 0;
	virtual void SetLife(int nLife) = 0;
	virtual void AddLife(int nAddLife) = 0;
	virtual int GetMaxLife() = 0;
	virtual int GetMana() = 0;
	virtual void SetMana(int nMana) = 0;
	virtual void AddMana(int nAddMana) = 0;
	virtual int GetMaxMana() = 0;
	virtual int GetLevel() = 0;
	virtual void SetLevel(int nLevel) = 0;
	virtual void UpLevel() = 0;
	virtual int64_t GetExp() = 0;
	virtual void SetExp(int64_t nExp) = 0;
	virtual void AwardExp(int64_t nExp) = 0;
	virtual void SendShow(CUser* pUser) = 0;
	virtual void SendShow(const USER_SET& setUsers) = 0;
	virtual bool IsInvulnerable() = 0;
	virtual bool IsBeAttackedEnable() = 0;
	virtual void OnTimer();
	virtual void OnEnterScene();
	virtual void OnLeaveScene();
protected:
	CRoleTypeData* m_pRoleTypeData;
};


#endif	//end of define _ROLE_H_