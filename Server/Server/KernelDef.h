////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/29
// Describe:
////////////////////////////////////////////////////////////////////////
#ifndef _KERNELDEF_H_
#define _KERNELDEF_H_

#include <string>

enum THREAD_INDEX
{
	THREAD_INDEX_MAIN,					//���߳�
 	THREAD_INDEX_SERVER_SOCKET,			//�ͻ������ӵķ�����SOCKET�߳�
	THREAD_INDEX_AS_SOCKET,				//�˷�����SOCKET�߳�
	THREAD_INDEX_LOGIN,					//��¼Ԥ�����̣߳��൱��ԭ����WORLD_KERNEL��
	THREAD_INDEX_DATABASE,				//���ݿ��̣߳���¼���ݵ��첽���أ�
 	THREAD_INDEX_GAME,					//��Ϸ�����̣߳�������Ϸҵ���߼���

	//------�µ��߳�����ڴ�֮��-----------
	THREAD_INDEX_MAX,					//���������ֱ��ʹ��
};

extern const std::string g_stThreadInfos[THREAD_INDEX_MAX];

#endif	//end of define _KERNELDEF_H_