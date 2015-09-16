////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/16
// Describe:��Ϸ�ڶ���
////////////////////////////////////////////////////////////////////////
#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include <bitset>
#include "BaseDefine.h"

using std::bitset;

#define IPP_OF(x)	((void**)(&(x)))

#define OBJID_SERVER_ID_BITS		16
#define OBJID_REAL_ID_BITS		48
//����ID������Ǹ�16λΪ������ID����48λΪ��ʵID
typedef OBJID64 OBJID;

enum OBJECT_TYPE
{
	OBJ_NONE					= 0,	//��Ч����
	OBJ_USER					= 1,	//���
	OBJ_MONSTER				= 2,	//����
	OBJ_NPC						= 3,	//NPC
	OBJ_EUDEMON				= 4,	//����
	OBJ_ITEM					= 5,	//��Ʒ
	OBJ_SYNDICATE				= 6,	//����

	//!!!�µ���������ڱ���֮��
	OBJ_MAX,							//���������ֱ��ʹ��
};

//��������
//֧�ֶ��帴�����ͣ����ڶ����ռ���ʱ��ʹ��
class CObjectType
{
public:
	//���Զ��嵥������CObjectType(OBJ_USER)
	//Ҳ���Զ��帴������CObjectType(OBJ_USER, OBJ_MONSTER, OBJ_NONE)����Ϊ�ǿɱ���������һ������������OBJ_NONE�������ڶ����ռ��ȳ��Ϻ�����
	CObjectType(OBJECT_TYPE eType, OBJECT_TYPE eType1 = OBJ_NONE, ...);
	~CObjectType();
public:
	const OBJECT_TYPE GetType() const;
	bool IsType(const OBJECT_TYPE eType);
	bool IsContain(const OBJECT_TYPE eType);
	void AddType(const OBJECT_TYPE eType);
	bool operator==(const CObjectType& rOther);
	bool operator==(const OBJECT_TYPE eType);
	bool operator!=(const CObjectType& rOther);
	bool operator!=(const OBJECT_TYPE eType);
	CObjectType& operator=(const CObjectType& rOther);
	CObjectType& operator=(const OBJECT_TYPE eType);
private:
	bitset<OBJ_MAX> m_bsType;
};

//��Ϸ�и��ֶ���Ļ���
//������߲���ʱ�����ܳ����ظ��Ķ��󣬶�Ҫ�̳б���
//ʹ��ʱ��ע���ڴ�������ʱ��ָ����Ӧ������
class CGameObject
{
protected:
	CGameObject(OBJECT_TYPE eType);
	virtual ~CGameObject();
public:
	virtual void Release() { delete this; }

public:
	static OBJID16 GetServerID(OBJID idObject);
	static OBJID64 GetRealID(OBJID idObject);
	virtual OBJID GetID() = 0;
	OBJECT_TYPE GetType();
	virtual bool IsType(const CObjectType& eType);
	virtual bool QueryObject(OBJECT_TYPE eObjType, void** ppObj);
		
protected:
	CObjectType m_objType;
};

#endif	//end of define _GAMEOBJECT_H_