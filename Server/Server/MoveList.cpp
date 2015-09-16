////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/01
// Describe:
////////////////////////////////////////////////////////////////////////
#include <time.h>
#include "BaseDefine.h"
#include "MoveList.h"
#include "MoveAction.h"
#include "TimeFormatter.h"


CMoveList::CMoveList()
{

}

CMoveList::~CMoveList()
{
	this->ClearAllActions();
}

bool CMoveList::Create()
{
	return true;
}

bool CMoveList::AppendMoveAction(CMoveAction* pMoveAction)
{
	CHECK_RETURN(pMoveAction, false);

	if (m_lstActions.empty())
	{
		m_lstActions.push_back(pMoveAction);

		return true;
	}

	//׷�ӵĶ�����Ӧ���������
	CMoveAction* pLastAction = m_lstActions.back();
	if (pLastAction && (pLastAction->GetStartTime() > pMoveAction->GetStartTime()))
	{
		return false;
	}

	//����µĶ�������ʱ��ǰһ��������δ��������ô��������ǰһ�������Ľ���ʱ��ͽ���λ��
	if (pLastAction->GetEndTime() > pMoveAction->GetStartTime())
	{
		pLastAction->SetEndTime(pMoveAction->GetStartTime());
		pLastAction->SetEndPos(pMoveAction->GetStartPos());
	}

	m_lstActions.push_back(pMoveAction);

	return true;
}

bool CMoveList::HasPendingMove()
{
	if (m_lstActions.empty())
	{
		return false;
	}

	clock_t tCurrMS = CTimeFormatter::TimeGet(TIME_MILLISECOND);

	CMoveAction* pAction = m_lstActions.back();
	if (pAction && (pAction->GetEndTime() > tCurrMS))
	{
		return true;
	}

	return false;
}

bool CMoveList::RunActions(Point3f& ptEndPos)
{
	if (m_lstActions.empty())
	{
		return false;
	}

	clock_t tCurrMS = CTimeFormatter::TimeGet(TIME_MILLISECOND);

	MOVELIST_ITERATOR it = m_lstActions.begin();
	for (; it != m_lstActions.end(); ++it)
	{
		CMoveAction* pAction = *it;
		if (pAction == NULL)
		{
			continue;
		}

		//������δ��������ֹ
		if (pAction->GetStartTime() > tCurrMS)
		{
			break;
		}

		//�����Ѿ�������ֱ��ȡ����λ��
		if (pAction->GetEndTime() <= tCurrMS)
		{
			ptEndPos = pAction->GetEndPos();
			SAFE_RELEASE(pAction);
		}
		else //���������У����㵱ǰʵ��λ��
		{
			clock_t tDeltaTime = tCurrMS - pAction->GetStartTime();
			float fDistance = pAction->GetVelocity()*tDeltaTime;
			Vec3f v3Normal = (pAction->GetEndPos() - pAction->GetStartPos());
			v3Normal.normalize();
			ptEndPos = (pAction->GetStartPos() + v3Normal*fDistance);
			break;
		}
	}
	m_lstActions.erase(m_lstActions.begin(), it);

	return true;
}

void CMoveList::ClearAllActions()
{
	if (m_lstActions.empty())
	{
		return;
	}

	for (MOVELIST_ITERATOR it = m_lstActions.begin(); it != m_lstActions.end(); ++it)
	{
		CMoveAction* pAction = *it;
		if (pAction == NULL)
		{
			continue;
		}
		SAFE_RELEASE(pAction);
	}

	m_lstActions.clear();
}

void CMoveList::InterruptAllActions(Point3f& ptEndPos)
{
	if (m_lstActions.empty())
	{
		return;
	}

	this->RunActions(ptEndPos);
	this->ClearAllActions();
}

bool CMoveList::GetMoveAction(CMoveAction* pMoveAction)
{
	CHECK_RETURN(pMoveAction, false);

	if (m_lstActions.empty())
	{
		return false;
	}	

	Point3f ptEndPos;
	this->RunActions(ptEndPos);

	CMoveAction* pNextMoveAction = m_lstActions.front();
	if (pNextMoveAction == NULL)
	{
		return false;
	}

	pMoveAction->SetStartPos(pNextMoveAction->GetStartPos());
	pMoveAction->SetEndPos(pNextMoveAction->GetEndPos());
	pMoveAction->SetStartTime(pNextMoveAction->GetStartTime());
	pMoveAction->SetEndTime(pNextMoveAction->GetEndTime());
	pMoveAction->SetVelocity(pNextMoveAction->GetVelocity());

	return true;
}

bool CMoveList::GetCurMoveAction(CMoveAction* pMoveAction)
{
	return this->GetMoveAction(pMoveAction);
}

bool CMoveList::AppendMoveActionByInfo(MoveActionInfo_t* pInfo)
{
	CHECK_RETURN(pInfo, false);

	CMoveAction* pAction = CMoveAction::CreateNew();
	if (pAction == NULL || !pAction->Create(pInfo))
	{
		SAFE_RELEASE(pAction);
		return false;
	}

	if (this->AppendMoveAction(pAction))
	{
		SAFE_RELEASE(pAction);
		return false;
	}

	return true;
}

