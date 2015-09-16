////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/15
// Describe:��ʱ��������
////////////////////////////////////////////////////////////////////////
#ifndef _TIMERMGR_H_
#define _TIMERMGR_H_

#include <list>
#include <vector>
#include "Timer.h"

#define TIMER_LIST_MS_MIN_PERIOD		10	//10����
#define TIMER_LIST_SEC_MIN_PERIOD		1	//1��
#define TIMER_LIST_TIGGER_MIN_PERIOD	1	//1��

//��ʱ������ӿ��࣬������Ҫ������ʱ�����඼Ҫ�̳б��ӿ�
//���ĳ�����͵Ķ��󣬶�ʱ���������ȫ��ͬ����ô�����ö����manager�̳б��ӿڣ���manager��OnTimer�������ÿ��������ö�ʱ����������
//�������Լ���TimerMgr���涨ʱ�����еĳ��ȣ���CUser����ֻ����UserMgr�̳б��ӿڣ�Ȼ����OnTimer�б���ÿ��CUser����CUser::OnTimer����
class ITimerHandler
{
public:
	//ָ����ʱ���ľ��ȣ��ʹ����ļ��������ֻ�Ǵ���OnTimer�ļ����������ȡ���ֵ
	ITimerHandler(TIMER_PRECISION ePrecision, time_t tInterval, bool bPeriodic);
	//��ע�ᶨʱ��
	virtual ~ITimerHandler();

public:
	//��ʱ������ʱ�ص�
	virtual void OnTimer() = 0;
	//ʱ��㴥���ص�
	virtual void OnTimeTrigger(const TimeTrigger_t& pTrigger) = 0;
	virtual ITimer* GetTimer() = 0;
private:
	ITimer* m_pTimer;
};

//�������еĶ�ʱ�������败��
//û�дﵽ����ʱ����࣬�������OnTimer������������Ч�����˷���OnTimer�����ʱ��
class CTimerMgr
{
private:
	typedef std::list<ITimerHandler*> TIMER_LIST;
	typedef std::vector<ITimerHandler*> TIMER_VEC;
	CTimerMgr();
	~CTimerMgr();
public:
	static CTimerMgr* GetInstance();
	bool RegisterTimer(ITimerHandler* pNewTimerHandler);
	bool UnregisterTimer(ITimerHandler* pTimerHandler);
	void OnTimer();
private:
	TIMER_LIST* GetFitTimerList(ITimerHandler* pTimerHandler);
	void OnTimerPriv(TIMER_LIST& lstTimer);
	void OnTimeTrigger();
	void InitTimeTrigger();
	void FillTimeTrigger(TimeTrigger_t* pTrigger, tm* pTimeZone);
private:
	TIMER_LIST m_lstTimerMS;
	TIMER_LIST m_lstTimerSec;
	TimeTrigger_t m_stTrigger;
	CTimerMS m_tTimerMS;
	CTimer m_tTimerSec;
	CTimer m_tTimerTigger;
};

#endif	//end of define _TIMERMGR_H_
