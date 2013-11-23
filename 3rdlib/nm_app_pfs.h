/*
* Copyright (C) 2012-2014 www.56.com email: jingchun.zhang AT renren-inc.com; jczhang AT 126.com ; danezhang77 AT gmail.com
* 
* 56VFS may be copied only under the terms of the GNU General Public License V3
*/
#ifndef __NM_APP_PFS_H__
#define __NM_APP_PFS_H__

#include "c_api.h"

#define NM_INT_PFS_BASE 0x04001000
#define NM_INC_PFS_BASE 0x05001000
#define NM_STR_PFS_BASE 0x08001000

#define PFS_STR_OPENFILE_E NM_STR_PFS_BASE+1   /*���ļ�����*/
#define PFS_STR_CONNECT_E NM_STR_PFS_BASE+2   /*���ӶԶ˴���*/

#define PFS_STR_MD5_E  NM_STR_PFS_BASE+3    /*MD5У�����*/
#define PFS_WRITE_FILE NM_STR_PFS_BASE+4    /**/
#define PFS_MALLOC NM_STR_PFS_BASE+5    /**/
#define PFS_TASK_COUNT NM_STR_PFS_BASE+6    /**/
#define PFS_TASK_MUTEX_ERR NM_STR_PFS_BASE+7  /*���ڿ��ͬ������*/

#define PFS_INT_TASK_ALL NM_INT_PFS_BASE+1  /*��ǰ��������������*/
#define PFS_INC_TASK_OVER NM_INT_PFS_BASE+2 /*�����������*/
#define PFS_TASK_COUNT_INT NM_INT_PFS_BASE+3    /**/

#define PFS_TASK_DEPTH_BASE NM_INT_PFS_BASE+10  /*TASK_DEPTH_BASE max 32 queue*/

#define PFS_RE_EXECUTE_INC NM_INC_PFS_BASE
#define PFS_ABORT_INC NM_INC_PFS_BASE+1

/*
 * CDC
 */
#define NM_STR_CDC_BASE NM_STR_PFS_BASE+1000
#define CDC_NORMAL_ERR NM_STR_CDC_BASE /*CDC open file , link file , open dir etc error*/
#define CDC_TOO_MANY_IP NM_STR_CDC_BASE+1 /*CDC too many ip one file*/
#define CDC_ADD_NODE_ERR NM_STR_CDC_BASE+2  /*CDC add node err*/
#define CDC_SHM_INIT_ERR NM_STR_CDC_BASE+3  /*CDC shm init err*/

#endif
