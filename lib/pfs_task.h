/*
* Copyright (C) 2012-2014 www.56.com email: jingchun.zhang AT renren-inc.com; jczhang AT 126.com ; danezhang77 AT gmail.com
* 
* 56VFS may be copied only under the terms of the GNU General Public License V3
*/
#ifndef _PFS_TASK_H_
#define _PFS_TASK_H_

/*
 */

#include "list.h"
#include "pfs_api.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>
#include <pthread.h>

enum {OPER_IDLE, OPER_GET_REQ, OPER_GET_RSP, OPER_SYNC_2_DOMAIN, OPER_PUT_REQ, OPER_PUT_RSP};  

enum {TASK_Q_DELAY = 0, TASK_Q_WAIT, TASK_Q_WAIT_TMP, TASK_Q_WAIT_SYNC, TASK_Q_WAIT_SYNC_IP, TASK_Q_WAIT_SYNC_DIR, TASK_Q_WAIT_SYNC_DIR_TMP, TASK_Q_SYNC_DIR, TASK_Q_SYNC_DIR_TMP, TASK_Q_RUN, TASK_Q_FIN, TASK_Q_CLEAN, TASK_Q_HOME, TASK_Q_SEND, TASK_Q_RECV, TASK_Q_SYNC_POSS, TASK_Q_SYNC_DIR_REQ, TASK_Q_SYNC_DIR_RSP, TASK_Q_UNKNOWN}; /*�������*/  

enum {OVER_UNKNOWN = 0, OVER_OK, OVER_E_MD5, OVER_PEERERR, TASK_EXIST, OVER_PEERCLOSE, OVER_UNLINK, OVER_TIMEOUT, OVER_MALLOC, OVER_SRC_DOMAIN_ERR, OVER_SRC_IP_OFFLINE, OVER_E_OPEN_SRCFILE, OVER_E_OPEN_DSTFILE, OVER_E_IP, OVER_E_TYPE, OVER_SEND_LEN, OVER_TOO_MANY_TRY, OVER_DISK_ERR, OVER_LAST};  /*�������ʱ��״̬*/

enum {GET_TASK_Q_ERR = -1, GET_TASK_Q_OK, GET_TASK_Q_NOTHING};  /*��ָ������ȡ����Ľ��*/

enum {TASK_DST = 0, TASK_SOURCE, TASK_SRC_NOSYNC, TASK_SYNC_ISDIR, TASK_SYNC_VOSS_FILE}; /*���������Ƿ���Ҫ��ͬ�����ͬ�� */

extern const char *task_status[TASK_Q_UNKNOWN]; 
extern const char *over_status[OVER_LAST]; 
typedef struct {
	char filename[256];
	char tmpfile[256];
	char retfile[256];
	unsigned char filemd5[17];  /*change md5 for more efficiency*/
	uint32_t dstip;    /*��������Ŀ��ip����GET����PUT_FROMʱ����ip�Ǳ���ip*/
	time_t starttime;
	time_t mtime;
	off_t fsize;
	uint8_t type;         /*�ļ��任���ͣ�ɾ����������*/
	uint8_t retry;     /*����ִ��ʧ��ʱ�����������Ƿ�ִ�����·��������Ѿ����Դ��������ܳ����趨���Դ���*/
	uint8_t overstatus; /*����״̬*/
	uint8_t bk;
}t_task_base;

typedef struct {
	off_t processlen; /*��Ҫ��ȡ���߷��͵����ݳ���*/
	off_t lastlen; /*��һ������ ����ĳ��ȣ���ʼ��Ϊ0 */
	time_t   lasttime; /*�ϸ�����ʱ���*/
	time_t   starttime; /*��ʼʱ���*/
	time_t	 endtime; /*����ʱ���*/
	char peerip[16];  /*�Զ�ip*/
	uint8_t oper_type; /*�Ǵ�FCS GET�ļ���������ͬ��CS  GET�ļ� */
	uint8_t need_sync; /*TASK_SOURCE����������Դͷ��TASK_DST����������Ŀ��֮һ */
	uint8_t sync_dir;  /**/
	uint8_t bk;
}t_task_sub;

typedef struct {
	t_task_base base;
	t_task_sub  sub;
	void *user;
}t_pfs_taskinfo;

typedef struct {
	t_pfs_taskinfo task;
	list_head_t llist;
	list_head_t userlist;
	time_t last;
	uint8_t status;
	uint8_t flag;
	uint8_t bk[2];
} t_pfs_tasklist;

typedef struct {
	int d1;
	int d2;
	time_t starttime;
	time_t endtime; 
	char type;  
	char bk[3];
} t_pfs_sync_task;

typedef struct {
	t_pfs_sync_task sync_task;
	list_head_t list;
} t_pfs_sync_list;

typedef void (*timeout_task)(t_pfs_tasklist *task);

int pfs_get_task(t_pfs_tasklist **task, int status);

int pfs_set_task(t_pfs_tasklist *task, int status);

int init_task_info();

int scan_some_status_task(int status, timeout_task cb);

int get_task_count(int status);

void do_timeout_task();

void report_2_nm();

void dump_task_info (int logfd, char *from, int line, t_task_base *task);

void do_timeout_task();

#endif
