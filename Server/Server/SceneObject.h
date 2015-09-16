////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/05/18
// Describe:��������
////////////////////////////////////////////////////////////////////////
#ifndef _SCENEOBJECT_H_
#define _SCENEOBJECT_H_

#include <map>
#include "ozcollide/Vec3f.h"
#include "ozcollide/box.h"
#include "TimerMgr.h"
#include "GameObject.h"

using namespace ozcollide;

class CScene;
class COctree;
class CRegion;

//�����ڵ㣬��Ҫ���볡���е����嶼��Ҫ�̳�
class CSceneObject : public CGameObject
{
protected:
	CSceneObject(OBJECT_TYPE eType);
	virtual ~CSceneObject();
public:
	virtual bool Create(CScene* pScene, const Point3f& ptPos);
	virtual bool IsMovable();
	//�Ƿ�ɱ�����
	virtual bool IsTeleportable();

public:
	/** Determines if the center of this node is within the given box
	*/
	virtual bool IsIn(Box &box);

	/** Returns the local bounding box of this OctreeNode.
	@remarks
	This is used to render the bounding box, rather then the global.
	*/
	virtual Box& GetLocalBox()
	{
		return m_LocalBox;
	};

	virtual const Point3f& GetPosition();
	virtual void SetPosition(const Point3f& ptPos);

	virtual void OnTimer();
	virtual void OnTimeTrigger(const TimeTrigger_t& pTrigger);
	virtual CScene* GetScene() { return m_pScene; }
	virtual CRegion* GetRegion() { return m_pRegion; }
	virtual OBJID32 GetSceneID();
	virtual OBJID32 GetRegionID();

	virtual bool TravelToRegion(CRegion* pTargetRegion);
	virtual bool TeleportTo(OBJID idScene, const Point3f& ptTargetPos);

	virtual bool LeaveScene();
	virtual bool EnterScene();
	virtual void OnEnterScene();
	virtual	void OnLeaveScene();

protected:
	CScene* m_pScene;

	///local bounding box
	Box m_LocalBox;

	///Region this node is attached to.
	CRegion* m_pRegion;
};

typedef std::map<OBJID, CSceneObject*> SCENE_OBJECT_MAP;

#endif	//end of define _SCENEOBJECT_H_