##############################################################
# Describe: ��ʼ�ύ
# Author: Fu Yan
##############################################################
DROP TABLE IF EXISTS `gs_config`;
CREATE TABLE `gs_config` (
	`id` INT(4) UNSIGNED NOT NULL AUTO_INCREMENT,				#���к�
	`type` INT(4) UNSIGNED NOT NULL DEFAULT 0,				#����
	`data1` INT(4) UNSIGNED NOT NULL DEFAULT 0,				#�Զ�������1
	`data2` INT(4) UNSIGNED NOT NULL DEFAULT 0,				#�Զ�������2
	`data3` INT(4) UNSIGNED NOT NULL DEFAULT 0,				#�Զ�������3
	`data4` INT(4) UNSIGNED NOT NULL DEFAULT 0,				#�Զ�������4
	`data5` INT(4) UNSIGNED NOT NULL DEFAULT 0,				#�Զ�������5
	`str` CHAR(255) NOT NULL DEFAULT '',						#�ַ���
	`desc`	CHAR(32) NOT NULL DEFAULT '',						#����������
    PRIMARY KEY (`id`)
) ENGINE=MyISAM;

DROP TABLE IF EXISTS `gs_role_type`;
CREATE TABLE `gs_role_type`  (
	`id` INT(4) UNSIGNED NOT NULL AUTO_INCREMENT,				#���к�
	`name` CHAR(16) NOT NULL DEFAULT '',						#����
	`gender` TINYINT NOT NULL DEFAULT 0,						#�Ա�
	`profession` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#ְҵ
	`base_level` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#�����ȼ�
	`max_level` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#���ȼ�
	`length` FLOAT NOT NULL DEFAULT 0,						#����
	`width` FLOAT NOT NULL DEFAULT 0,							#���
	`height` FLOAT NOT NULL DEFAULT 0,							#�߶�
	`base_life` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#��������ֵ
	`base_mana` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#��������ֵ
	`base_speed` FLOAT NOT NULL DEFAULT 0,					#�����ƶ��ٶ�
    PRIMARY KEY (`id`)
) ENGINE=MyISAM;

DROP TABLE IF EXISTS `gs_scene`;
CREATE TABLE `gs_scene` (
  `id` INT(4) UNSIGNED NOT NULL DEFAULT 0,					#��ͼID
  `name` CHAR(15) DEFAULT 'δ����',								#��ͼ��
  `mapdoc` INT(4) UNSIGNED NOT NULL DEFAULT 0,				#��ͼ��ʾģ��ID
  `type` BIGINT UNSIGNED NOT NULL DEFAULT 0,					#��ͼ���ͣ���λ���룩
  `type2` BIGINT UNSIGNED NOT NULL DEFAULT 0,					#��ͼ����2����λ���룩
  `sort` INT(4) UNSIGNED NOT NULL DEFAULT 0,					#��ͼ����
  `portal0_x` FLOAT NOT NULL DEFAULT 0,						#���0��X����
  `portal0_y` FLOAT NOT NULL DEFAULT 0,						#���0��Y����
  `portal0_z` FLOAT NOT NULL DEFAULT 0,						#���0��Z����
  `reborn_map` INT(4) UNSIGNED  DEFAULT 0,						#�����ͼID
  `link_map` INT(4) UNSIGNED  NOT NULL DEFAULT 0,				#���ӵ�ͼID
  `link_x` FLOAT NOT NULL DEFAULT 0,							#���ӵ�ͼ��X����
  `link_y` FLOAT NOT NULL DEFAULT 0,							#���ӵ�ͼ��Y����
  `link_z` FLOAT NOT NULL DEFAULT 0,							#���ӵ�ͼ��Z����
  `flag` INT(4) UNSIGNED NOT NULL DEFAULT 0,					#��־λ
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM;

DROP TABLE IF EXISTS `gs_user`;
CREATE TABLE `gs_user`  (
	`id` BIGINT UNSIGNED NOT NULL AUTO_INCREMENT,				#���к�
	`name` CHAR(16) NOT NULL DEFAULT '',						#����
	`account_id` BIGINT UNSIGNED NOT NULL DEFAULT 0,			#�˺�ID
	`role_type` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#��ɫ����
	`level` INT(4) UNSIGNED NOT NULL DEFAULT 0,				#�ȼ�
	`exp` BIGINT(4) UNSIGNED NOT NULL DEFAULT 0,				#����ֵ
	`length` FLOAT  NOT NULL DEFAULT 0,						#����
	`width` FLOAT NOT NULL DEFAULT 0,							#���
	`height` FLOAT NOT NULL DEFAULT 0,							#�߶�
	`scene_id` INT(4) NOT NULL DEFAULT 0,						#��ͼID
	`pos_x` FLOAT NOT NULL DEFAULT 0,							#x����
	`pos_y` FLOAT NOT NULL DEFAULT 0,							#y����
	`pos_z` FLOAT NOT NULL DEFAULT 0,							#z����
	`record_scene_id` INT(4) UNSIGNED NOT NULL DEFAULT 0,	#��¼��ͼID
	`record_x` FLOAT NOT NULL DEFAULT 0,						#��¼x����
	`record_y` FLOAT NOT NULL DEFAULT 0,						#��¼y����
	`record_z` FLOAT NOT NULL DEFAULT 0,						#��¼z����
	`life` INT(4) UNSIGNED NOT NULL DEFAULT 0,				#����ֵ
	`mana` INT(4) UNSIGNED NOT NULL DEFAULT 0,				#����ֵ
    PRIMARY KEY (`id`),
	UNIQUE INDEX(`name`)
) ENGINE=MyISAM;

/* DROP TABLE IF EXISTS `gs_magic_type`;
CREATE TABLE `gs_magic_type`  (
	`id` BIGINT UNSIGNED NOT NULL,								#���к�
	`name` CHAR(16) NOT NULL DEFAULT '',						#����
	`sort` INT(4) UNSIGNED NOT NULL DEFAULT 0,				#ʩ�����ͣ�˲���������������������ȣ�
	`begin_delay_ms` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#ǰҡ(����)
	`end_delay_ms` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#��ҡ(����)
	`cool_down_ms` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#��ȴʱ��(����)
	`hit_rate` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#������
	`cost_type1` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#������������1(hp��hp�ٷֱȣ�mp��mp�ٷֱȵ�)
	`cost_value1` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#��������ֵ1
	`cost_type2` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#������������2(hp��hp�ٷֱȣ�mp��mp�ٷֱȵ�)
	`cost_value2` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#��������ֵ2
	`target_type` INT(4) UNSIGNED  NOT NULL DEFAULT 0,		#Ŀ������(�Եأ��Խ�ɫ�����Լ�������ң��Թ֣��Կյ�)
	`range_type` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#��Χ����(���Σ����ͣ������)
	`range_data1` FLOAT NOT NULL DEFAULT 0,					#��Χ��ֵ1
	`range_data2` FLOAT NOT NULL DEFAULT 0,					#��Χ��ֵ2
	`damage_type1` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#�˺�����1������ħ������ʵ��
	`addition_type1` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#�˺��ӳ�����1(����ǿ�ȼӳɣ�ħ��ǿ�ȼӳ�)
	`damage_attr1` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#�˺�������1(hp��hp�ٷֱȣ�mp��mp�ٷֱȵ�)
	`damage_value1` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#�˺�ֵ1
	`damage_type2` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#�˺�����2������ħ������ʵ��
	`addition_type2` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#�˺��ӳ�����2(����ǿ�ȼӳɣ�ħ��ǿ�ȼӳ�)
	`damage_attr2` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#�˺�������2(hp��hp�ٷֱȣ�mp��mp�ٷֱȵ�)
	`damage_value2` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#�˺�ֵ2
	`atker_track` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#ʩ�����ƶ��켣
	`victim_track` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#�ܻ����ƶ��켣
	`status_id` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#����״̬ID
	`status_rate` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#����״̬�ĸ���
	`next_magic_type` INT(4) UNSIGNED NOT NULL DEFAULT 0,	#��������ID
	`next_magic_rate` INT(4) UNSIGNED NOT NULL DEFAULT 0,	#�������ܵĸ���
    PRIMARY KEY (`id`)
) ENGINE=MyISAM;

DROP TABLE IF EXISTS `gs_status_type`;
CREATE TABLE `gs_status_type`  (
	`id` BIGINT UNSIGNED NOT NULL,								#���к�
	`name` CHAR(16) NOT NULL DEFAULT '',						#����
	`status_type` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#Ч��(��ѣ���Ի󣬳�Ĭ��������)
	`hit_rate`	INT(4) UNSIGNED NOT NULL DEFAULT 0,			#������
	`duration` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#״̬����ʱ��
	`hit_times` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#��������
	`power_type` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#������Ч������
	`power_value`	INT(4) UNSIGNED NOT NULL DEFAULT 0,		#������Ч����ֵ
	`power_add_type` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#Ч���ӳ�����
	`power_add_value` INT(4) UNSIGNED NOT NULL DEFAULT 0,	#Ч���ӳ���ֵ
	`next_status`	INT(4) UNSIGNED NOT NULL DEFAULT 0,		#������״̬
	`next_status_rate` INT(4) UNSIGNED NOT NULL DEFAULT 0,	#״̬��������
	`next_magic_type` INT(4) UNSIGNED NOT NULL DEFAULT 0,	#��������ID
	`next_magic_rate` INT(4) UNSIGNED NOT NULL DEFAULT 0,	#�������ܵĸ���
    PRIMARY KEY (`id`)
) ENGINE=MyISAM;

DROP TABLE IF EXISTS `gs_track_type`;
CREATE TABLE `gs_track_type`  (
	`id` BIGINT UNSIGNED NOT NULL,								#���к�
	`dir_type`	INT(4) UNSIGNED NOT NULL DEFAULT 0,			#�������ͣ���ԣ����ԣ�
	`dir_x` FLOAT NOT NULL DEFAULT 0,							#����X
	`dir_y` FLOAT NOT NULL DEFAULT 0,							#����Y
	`dir_z` FLOAT NOT NULL DEFAULT 0,							#����Z
	`speed` INT(4) UNSIGNED NOT NULL DEFAULT 0,				#�ƶ��ٶ�
	`duration` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#����ʱ��
	`next_track` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#�����Ĺ켣
	`next_track_rate` INT(4) UNSIGNED NOT NULL DEFAULT 0,	#�켣�����ĸ���
    PRIMARY KEY (`id`)
) ENGINE=MyISAM;

DROP TABLE IF EXISTS `gs_damage_type`;
CREATE TABLE `gs_damage_type`  (
	`id` BIGINT UNSIGNED NOT NULL,								#���к�
	`sort`	INT(4) UNSIGNED NOT NULL DEFAULT 0,				#�˺����ͣ�����ħ������ʵ�ȣ�
	`power_add_type` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#�˺��ӳ�����
	`power_add_value` INT(4) UNSIGNED NOT NULL DEFAULT 0,	#�˺��ӳ�ֵ
	`affect_attr` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#Ӱ�������
	`power_value` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#�˺�ֵ
	`next_damage` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#�������˺�ID
	`next_damage_rate` INT(4) UNSIGNED NOT NULL DEFAULT 0,	#�����˺��ĸ���
    PRIMARY KEY (`id`)
) ENGINE=MyISAM; */

DROP TABLE IF EXISTS `gs_magic_type`;
CREATE TABLE `gs_magic_type`  (
	`id` BIGINT UNSIGNED NOT NULL,								#���к�
	`name` CHAR(16) NOT NULL DEFAULT '',						#����
	`role_type` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#ѧϰ���ܵĽ�ɫ����
	`cast_type` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#ʩ�����ͣ�����,˲����
	`begin_delay_ms` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#ǰҡ(����)
	`end_delay_ms` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#��ҡ(����)
	`cool_down_ms` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#��ȴʱ��(����)
	`cost_type1` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#������������1(hp��hp�ٷֱȣ�mp��mp�ٷֱȵ�)
	`cost_value1` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#��������ֵ1
	`cost_type2` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#������������2(hp��hp�ٷֱȣ�mp��mp�ٷֱȵ�)
	`cost_value2` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#��������ֵ2
	`range_distance` FLOAT NOT NULL DEFAULT 0,				#���ܾ���
	`target_type` INT(4) UNSIGNED  NOT NULL DEFAULT 0,		#Ŀ������(�Եأ��Խ�ɫ�����Լ�������ң��Թ֣��Կյ�)
	`range_type` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#��Χ����(���Σ����ͣ������)
	`range_x` FLOAT NOT NULL DEFAULT 0,						#��Χx
	`range_y` FLOAT NOT NULL DEFAULT 0,						#��Χy
	`damage_id` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#�˺�ID
	`atker_distance` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#ʩ�����ƶ�����
	`atker_duration` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#ʩ�����ƶ�ʱ��
	`victim_distance` INT(4) UNSIGNED NOT NULL DEFAULT 0,	#�ܻ����ƶ�����
	`victim_duration` INT(4) UNSIGNED NOT NULL DEFAULT 0,	#�ܻ����ƶ�ʱ��
	`status_id` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#����״̬ID
	`status_rate` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#����״̬�ĸ���
    PRIMARY KEY (`id`)
) ENGINE=MyISAM;

DROP TABLE IF EXISTS `gs_magic`;
CREATE TABLE `gs_magic`  (
	`id` BIGINT UNSIGNED NOT NULL,								#���к�
	`owner_id` BIGINT UNSIGNED NOT NULL DEFAULT 0,			#ӵ����ID
	`magic_type` BIGINT UNSIGNED NOT NULL DEFAULT 0,			#magic_type_id
	`exp` INT(4) UNSIGNED NOT NULL DEFAULT 0,					#������
    PRIMARY KEY (`id`),
	INDEX (`owner_id`)
) ENGINE=MyISAM;

DROP TABLE IF EXISTS `gs_npc_magic`;
CREATE TABLE `gs_npc_magic`  (
	`id` BIGINT UNSIGNED NOT NULL,								#���к�
	`npc_type` BIGINT UNSIGNED NOT NULL DEFAULT 0,			#NPC����ID
	`magic_type` BIGINT UNSIGNED NOT NULL DEFAULT 0,			#magic_type_id
	`cast_rule` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#�ͷŹ���
	`cast_rule_data` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#�ͷŹ������
    PRIMARY KEY (`id`),
	INDEX (`npc_type`)
) ENGINE=MyISAM;

DROP TABLE IF EXISTS `gs_status_type`;
CREATE TABLE `gs_status_type`  (
	`id` BIGINT UNSIGNED NOT NULL,								#���к�
	`name` CHAR(16) NOT NULL DEFAULT '',						#����
	`status_type` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#Ч��(��ѣ���Ի󣬳�Ĭ��������)
	`hit_rate`	INT(4) UNSIGNED NOT NULL DEFAULT 0,			#������
	`duration` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#״̬����ʱ��
	`hit_times` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#��������
	`power_type` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#������Ч������
	`power_value`	INT(4) UNSIGNED NOT NULL DEFAULT 0,		#������Ч����ֵ
    PRIMARY KEY (`id`)
) ENGINE=MyISAM;

