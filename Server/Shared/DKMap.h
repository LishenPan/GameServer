////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/07/15
// Describe:������key��Map,DKMap is short for double keys map
////////////////////////////////////////////////////////////////////////
#ifndef _DKMAP_H_
#define _DKMAP_H_

#include <unordered_map>
#include <unordered_set>
#include "BaseDefine.h"

//˫Key Map������ͨ������key���ҵ���������UserMgr��Ҫͨ��id��name������CUser��������������
//Ϊ��ʵ�ַ����Ч�ʣ�ֻ��������ָ�룬���Ǵ���������벻Ҫ��ָ�롣���������������ͷ���Ҫ�������ⲿ����
//ʵ����ʹ��������map��һ��set����˲��ҺͲ���ʱ�����ֵ�����std::map
//������ʱ�����ֵ�����std::set
template<class K1, class K2, class T>
class CDKMap
{
public:
	typedef struct DKMapValueType_s
	{
		K1 k1;
		K2 k2;
		T* pObject;
	} DKMapValueType_t;
private:
	typedef std::unordered_map<K1, DKMapValueType_t*> K1MAP;
	typedef std::unordered_map<K2, DKMapValueType_t*> K2MAP;
	typedef std::unordered_set<DKMapValueType_t*> DKMAP_OBJECT_SET;

public:
	CDKMap();
	~CDKMap();
public:
	bool AddObject(K1 k1, K2 k2, T* pObject);
	bool DelObjectByKey1(K1 k1);
	bool DelObjectByKey2(K2 k2);
	T* GetObjectByKey1(K1 k1);
	T* GetObjectByKey2(K2 k2);

	typedef typename DKMAP_OBJECT_SET::iterator CIterator;

	CIterator Begin() { return m_setObjects.begin(); }
	CIterator End() { return m_setObjects.end(); }
private:
	DKMapValueType_t* GetValueTypeByKey1(K1 k1) { MAP_FIND_IMPL(m_mapK1, k1, K1MAP::iterator); }
	DKMapValueType_t* GetValueTypeByKey2(K2 k2) { MAP_FIND_IMPL(m_mapK2, k2, K2MAP::iterator); }
private:
	K1MAP m_mapK1;
	K2MAP m_mapK2;
	DKMAP_OBJECT_SET m_setObjects;
};

template<class K1, class K2, class T>
bool CDKMap<K1, K2, T>::DelObjectByKey2(K2 k2)
{
	DKMapValueType_t* pValueType = this->GetValueTypeByKey2(k2);
	CHECK_RETURN(pValueType, false);

	m_mapK1.erase(pValueType->k1);
	m_mapK2.erase(pValueType->k2);
	m_setObjects.erase(pValueType);
	SAFE_DELETE(pValueType);

	return true;
}

template<class K1, class K2, class T>
bool CDKMap<K1, K2, T>::DelObjectByKey1(K1 k1)
{
	DKMapValueType_t* pValueType = this->GetValueTypeByKey1(k1);
	if (pValueType == NULL)
	{
		return true;
	}

	m_mapK1.erase(pValueType->k1);
	m_mapK2.erase(pValueType->k2);
	m_setObjects.erase(pValueType);
	SAFE_DELETE(pValueType);

	return true;
}

template<class K1, class K2, class T>
T* CDKMap<K1, K2, T>::GetObjectByKey2(K2 k2)
{
	DKMapValueType_t* pValueType = this->GetValueTypeByKey2(k2);
	if (pValueType == NULL)
	{
		return NULL;
	}

	return pValueType->pObject;
}

template<class K1, class K2, class T>
T* CDKMap<K1, K2, T>::GetObjectByKey1(K1 k1)
{
	DKMapValueType_t* pValueType = this->GetValueTypeByKey1(k1);
	if (pValueType == NULL)
	{
		return NULL;
	}

	return pValueType->pObject;
}

template<class K1, class K2, class T>
bool CDKMap<K1, K2, T>::AddObject(K1 k1, K2 k2, T* pObject)
{
	CHECK_RETURN(pObject, false);

	DKMapValueType_t* pValueType = new DKMapValueType_t;
	CHECK_RETURN(pValueType, false);

	pValueType->k1 = k1;
	pValueType->k2 = k2;
	pValueType->pObject = pObject;

	m_mapK1.insert(std::make_pair(k1, pValueType));
	m_mapK2.insert(std::make_pair(k2, pValueType));

	m_setObjects.insert(pValueType);

	return true;
}

template<class K1, class K2, class T>
CDKMap<K1, K2, T>::CDKMap()
{

}

template<class K1, class K2, class T>
CDKMap<K1, K2, T>::~CDKMap()
{
	m_mapK1.clear();
	m_mapK2.clear();
	for (DKMAP_OBJECT_SET::iterator it = m_setObjects.begin(); it != m_setObjects.end(); ++it)
	{
		DKMapValueType_t* pValueType = *it;
		SAFE_DELETE(pValueType);
	}
	m_setObjects.clear();
}

#endif	//end of define _DKMAP_H_