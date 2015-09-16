////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/07/13
// Describe:���ݿ����
////////////////////////////////////////////////////////////////////////
#ifndef _DBTABLEDEF_H_
#define _DBTABLEDEF_H_

#define GAME_SERVER_TABLE_PREFIX			"gs_"

#define DEFINE_TABLE(szTblName)			GAME_SERVER_TABLE_PREFIX##szTblName

//DBKernel�첽�������ݵ�����
enum DB_LOAD_DATA_TYPE
{
	DB_LOAD_USER_DATA,								//�����������
};


#define TBL_CONFIG				DEFINE_TABLE("config")
#define TBL_ROLE_TYPE				DEFINE_TABLE("role_type")
#define TBL_SCENE					DEFINE_TABLE("scene")
#define TBL_USER					DEFINE_TABLE("user")
#define TBL_MAGIC_TYPE			DEFINE_TABLE("magic_type")
#define TBL_MAGIC					DEFINE_TABLE("magic")

#endif	//end of define _DBTABLEDEF_H_