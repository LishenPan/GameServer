////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/08/18
// Describe:������ض���
////////////////////////////////////////////////////////////////////////
#ifndef _MAGICDEF_H_
#define _MAGICDEF_H_

#include <vector>
#include "BaseDefine.h"
#include "GameObject.h"
#include "ozcollide/vec3f.h"

using namespace ozcollide;

using juce::WeakReference;

class CRole;

struct MagicCastInfo
{
	CRole* pCasterRole;	//ʩ����
	OBJID idTargetRole;	//Ŀ���ɫID
	OBJECT_TYPE eObjectType; //Ŀ���ɫ����
	Point3f ptTargetPos;	//Ŀ��ص�

	void Clear()
	{
		pCasterRole = NULL;
		idTargetRole = ID_NONE;
		ptTargetPos = ZEROVEC3F;
		eObjectType = OBJ_NONE;
	}

	MagicCastInfo()
	{
		this->Clear();
	}	
};

//����ʩ������
enum MAGIC_CAST_TYPE
{
	MAGIC_CAST_TYPE_NONE				= 0,	//����ʩ����˲����
	MAGIC_CAST_TYPE_SING				= 1,	//����

	MAGIC_CAST_TYPE_MAX
};

//������������
enum MAGIC_COST_TYPE
{
	MAGIC_COST_TYPE_NONE				= 0,	//������
	MAGIC_COST_TYPE_MP_VALUE			= 1,	//MPֵ
	MAGIC_COST_TYPE_MP_PERCENT		= 2,	//MP�ٷֱ�
	MAGIC_COST_TYPE_HP_VALUE			= 3,	//HPֵ
	MAGIC_COST_TYPE_HP_PERCENT		= 4,	//HP�ٷֱ�

	MAGIC_COST_TYPE_MAX
};

//����Ŀ�����ͣ�������ӷ�ʽ
enum MAGIC_TARGET_TYPE
{
	MAGIC_TARGET_TYPE_NONE			= 0,	//��Ч
	MAGIC_TARGET_TYPE_MONSTER		= 0x1,	//�Թ�
	MAGIC_TARGET_TYPE_GROUND			= 0x2,	//�Ե�
	MAGIC_TARGET_TYPE_PLAYER			= 0x4,	//�����
	MAGIC_TARGET_TYPE_SELF			= 0x8,	//���Լ�
	MAGIC_TARGET_TYPE_EUDEMON		= 0x10,	//�Ի���

	MAGIC_TARGET_TYPE_MAX,
};

//���ܷ�Χ����
enum MAGIC_RANGE_TYPE
{
	MAGIC_RANGE_TYPE_SINGLE			= 0,	//����
	MAGIC_RANGE_TYPE_LINE				= 1,	//����
	MAGIC_RANGE_TYPE_SPHERE			= 2,	//����

	MAGIC_RANGE_TYPE_MAX,
};

typedef std::vector<CRole*> TARGET_ROLE_VEC;

#endif	//end of define _MAGICDEF_H_