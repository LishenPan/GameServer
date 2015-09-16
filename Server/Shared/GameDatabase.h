////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/07/07
// Describe:��Ϸ���ݿ�,����mysql++�ļ򵥷�װ
////////////////////////////////////////////////////////////////////////
#ifndef _GAMEDATABASE_H_
#define _GAMEDATABASE_H_

#include <string>
#include "BaseDefine.h"
#include "Timer.h"
#include "mysql++.h"
#include "GameObject.h"

#define GAMEDATABASE_PING_TIMER_PERIOD		3600	//ÿСʱPINGһ�Σ���ֹMYSQL����timeout

typedef struct DbConfig_s
{
	std::string strServer;
	std::string strUser;
	std::string strPassword;
	std::string strDatabase;
}DbConfig_t;

typedef mysqlpp::StoreQueryResult CGameRecordset;
typedef mysqlpp::Row CGameRecordRow;
typedef std::map<OBJID, CGameRecordset*> LOADED_USER_DATA_MAP;

#ifndef _DEBUG
#define DEBUGSQL(q) 
#else
#define DEBUGSQL(q) DebugSQL(q)
#endif

class CGameDatabase
{
private:
	CGameDatabase();
	~CGameDatabase();
public:
	//����һ�����ݿ�����˳�����ǰ�����ֶ��ͷ�
	static CGameDatabase* CreateGameDatabase(const char* szServer, const char* szUser, const char* szPassword, const char* szDb, unsigned int nPort = 0);
private:
	static CGameDatabase* CreateNew() { return new CGameDatabase; }
	bool Create(const char* szServer, const char* szUser, const char* szPassword, const char* szDb, unsigned int nPort = 0);
public:
	void Release() { delete this; }

	//��ѯ������Ĭ�Ͻ������Ч�ʽϸߣ�CRecordSet& res����ʹ��res[0][0]�ķ�ʽ���ʣ�Ҳ����ʹ������res[0]["id"]�ķ�ʽ���ʣ��ӿ�����vector
	//�������ʱ���ݣ�����ٴ�ִ��������ѯ��䣬��������ᱻ���ǵ�
	//���ֻ������������������������ʹ��const CRecordSet& rRes = Select(strSQL)����������Ҫ�����ݸ���һ��
	//�����Ҫ����Ĭ�Ͻ����������ֱ��ʹ��CRecordSet objRes = Select(strSQL)�����ƽ����������
	//�������Ҫ�����ͱ�������ݵĻ�������ʹ�ñ��ӿ�
	const CGameRecordset& Select(const SQLBUF& strSQL);

	//ִ��ָ����SQL��䣬����ִ�н��
	bool ExecuteSQL(const SQLBUF& strSQL);

	//ִ��SELECT��䣬������������浽������vector�����У�Ч�ʽ�const CRecordSet& Select(const SQLBUF& strSQL)Ҫ��
	//����T�Ƕ�Ӧ��CXXXData��
	//�����Ҫ������������ʹ�ñ��ӿڣ�������ʹ��const CRecordSet& Select(const SQLBUF& strSQL)
	template<class T>
	bool SelectAndSaveTo(const SQLBUF& strSQL, std::vector<T>& vecData);

	//ִ��Update������T�Ƕ�Ӧ��CXXXData��
	template<class T>
	bool Update(T& rData);

	//ִ��Update������T�Ƕ�Ӧ��CXXXData��
	template<class T>
	bool Update(T* pData);

	//�������ݣ�����T�Ƕ�Ӧ��CXXXData�࣬����ɹ��������insert_id�ֶε�ֵ
	template<class T>
	bool Insert(T& rData);

	//�������ݣ�����T�Ƕ�Ӧ��CXXXData�࣬����ɹ��������insert_id�ֶε�ֵ
	template<class T>
	bool Insert(T* pData);

	//ʹ��SQL���insert���ݣ����ز����¼��ID
	OBJID64 InsertBySQL(const SQLBUF& strSQL);

	//ɾ����¼������T�Ƕ�Ӧ��CXXXData��
	template<class T>
	bool Delete(T& rData);

	//ɾ����¼������T�Ƕ�Ӧ��CXXXData��
	template<class T>
	bool Delete(T* pData);

	//��ʱ�������������Ҫ�ϳ�ʱ�俪�ţ�Ϊ�˷�ֹMYSQL���ӿ��г�ʱ�������Ontimer
	//Ĭ����ÿ��һ��Сʱ��ִ��һ��ping����������
	void OnTimer();

	OBJID64 GetInsertedId();
private:
	void DebugSQL(mysqlpp::Query& objQuery);
private:
	mysqlpp::Connection m_objConn;
	CTimer m_tPingTimer;
	CGameRecordset m_res;
};

template<class T>
bool CGameDatabase::SelectAndSaveTo(const SQLBUF& strSQL, std::vector<T>& vecData)
{
	DEBUG_TRY
	bool bSucc = this->Select(strSQL);
	if (!bSucc)
	{
		return false;
	}

	for (int i = 0; i < m_res.size(); ++i)
	{
		vecData.push_back(m_res[i]);
	}

	m_res.clear();

	return true;
	DEBUG_CATCH

		return false;
}

template<class T>
bool CGameDatabase::Update(T& rData)
{
	DEBUG_TRY
	mysqlpp::Query objQuery = m_objConn.query();
	objQuery.update(rData);

	DEBUGSQL(objQuery);
	return objQuery.exec();
	DEBUG_CATCH

		return false;
}

template<class T>
bool CGameDatabase::Update(T* pData)
{
	CHECK_RETURN(pData, false);
	DEBUG_TRY
		mysqlpp::Query objQuery = m_objConn.query();
		objQuery.update(*pData);

		DEBUGSQL(objQuery);
		return objQuery.exec();
	DEBUG_CATCH

	return false;
}

template<class T>
bool CGameDatabase::Insert(T& rData)
{
DEBUG_TRY
	mysqlpp::Query objQuery = m_objConn.query();
	objQuery.insert(rData);

	DEBUGSQL(objQuery);
	bool bSucc = objQuery.exec();
	if (bSucc)
	{
		rData.set(objQuery.insert_id());
	}

	return bSucc;
DEBUG_CATCH

	return false;
}

template<class T>
bool CGameDatabase::Insert(T* pData)
{
	CHECK_RETURN(pData, false);
	DEBUG_TRY
		mysqlpp::Query objQuery = m_objConn.query();
		objQuery.insert(*pData);

		DEBUGSQL(objQuery);
		bool bSucc = objQuery.exec();
		if (bSucc)
		{
			pData->set(objQuery.insert_id());
		}

		return bSucc;
	DEBUG_CATCH

	return false;
}

template<class T>
bool CGameDatabase::Delete(T& rData)
{
	DEBUG_TRY
	mysqlpp::Query objQuery = m_objConn.query();
	objQuery << "DELETE FROM `" << rData.table() << "` WHERE " << rData.equal_list(true);

	DEBUGSQL(objQuery);
	return objQuery.exec();
	DEBUG_CATCH

		return false;
}

template<class T>
bool CGameDatabase::Delete(T* pData)
{
	CHECK_RETURN(pData, false);
	DEBUG_TRY
	mysqlpp::Query objQuery = m_objConn.query();
	objQuery << "DELETE FROM `" << pData->table() << "` WHERE " << pData->equal_list(true);

	DEBUGSQL(objQuery);
	return objQuery.exec();
	DEBUG_CATCH

		return false;
}


#endif	//end of define _GAMEDATABASE_H_