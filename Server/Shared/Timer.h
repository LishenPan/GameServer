////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/11
// Describe:��ʱ����ʵ��
////////////////////////////////////////////////////////////////////////
#ifndef _TIMER_H_
#define _TIMER_H_

#include <time.h>

//��ʱ������
enum TIMER_PRECISION
{
	TIMER_PRECISION_MS		= 1,		//1����
	TIMER_PRECISION_SECOND	= 1000,		//1��=1000����
};

//ʱ�䷢����Ծʱ����ʱ���Ƿ񲹳�����(��ʱ�������1��Сʱ���Ƿ�Ҫ����һ��Сʱ��ʱ�䲹������)
enum TIMER_COMPENSATION
{
	TIMER_COMPENSATION_FALSE	= 0,		//������
	TIMER_COMPENSATION_TRUE	= 1,		//����
};

enum TIMER_PERIODIC
{
	TIMER_PERIODIC_FALSE	= 0,
	TIMER_PERIODIC_TRUE	= 1,
};

typedef struct TimeTrigger_s
{
	int nYear;				//��ݣ�����+1900
	int nMonth;				//�·� 1-12
	int nMday;				//һ�����е����� 1-31
	int nWday;				//���ڼ� 1-7
	int nHour;				//Сʱ 0-23
	int nMinute;			//���� 0-59
}TimeTrigger_t;

//��ʱ���ӿ���
class ITimer
{
public:
	ITimer();
	ITimer(time_t tInterval, bool bPeriodic);
	virtual ~ITimer() {}
public:
	virtual bool IsValid();
	virtual bool StartTimer();
	virtual bool StartTimer(time_t tInterval, bool bPeriodic);
	virtual void StopTimer();
	virtual bool IsTimeEnd(bool bCompensation = TIMER_COMPENSATION_FALSE);
	virtual bool ResetTimer();
	virtual bool IsPeriodic();
	virtual time_t GetRemainTime();
	virtual time_t GetInterval();
	virtual time_t GetEndTime();
public:
	//��ö�ʱ���ľ�ȷ�ȣ���λ����
	virtual time_t GetPrecision() = 0;
protected:
	//��õ�ǰ��ʱ�����ȱ�ʾ�ĵ�ǰʱ��
	virtual time_t GetCurrTime() = 0;
protected:
	bool m_bPeriodic;		//�Ƿ����ڶ�ʱ��
	time_t m_tEndTime;		//���ν���ʱ��
	time_t m_tInterval;		//�������
};

//�뼶��ʱ��
class CTimer : public ITimer
{
public:
	CTimer();
	CTimer(time_t tInterval, bool bPeriodic);
public:
	//��ö�ʱ���ľ�ȷ�ȣ���λ����
	virtual time_t GetPrecision();
protected:
	//��õ�ǰ��ʱ�����ȱ�ʾ�ĵ�ǰʱ��
	virtual time_t GetCurrTime();
};

//���뼶��ʱ��
class CTimerMS : public ITimer
{
public:
	CTimerMS();
	CTimerMS(time_t tInterval, bool bPeriodic);
public:
	//��ö�ʱ���ľ�ȷ�ȣ���λ����
	virtual time_t GetPrecision();
protected:
	//��õ�ǰ��ʱ�����ȱ�ʾ�ĵ�ǰʱ��
	virtual time_t GetCurrTime();
};


#endif	//end of define _TIMER_H_