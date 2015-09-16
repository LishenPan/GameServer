////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/05/18
// Describe:������س�������
////////////////////////////////////////////////////////////////////////
#ifndef _SCENEDEF_H_
#define _SCENEDEF_H_

#include "ozcollide/vec3f.h"

using namespace ozcollide;

#define SCENE_SCREEN_SIZE				2048.0f			//һ����Ļ��ռ�Ĵ�С

#define SCENE_OCTREE_MAX_DEPTH			6				//�˲���������

#define SCENE_OBJECT_CLIENT_MOVE_RANGE	200				//�ͻ����ƶ�ÿ��4��

#define SCENE_MOVE_DISTANCE_TOLERANCE	200				//�ƶ�������������ڵ����

#define SCENE_REGION_SIZE				Vec3f(SCENE_SCREEN_SIZE, SCENE_SCREEN_SIZE, SCENE_SCREEN_SIZE)

#endif	//end of define _SCENEDEF_H_