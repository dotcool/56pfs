/*
* Copyright (C) 2012-2014 www.56.com email: jingchun.zhang AT renren-inc.com; jczhang AT 126.com ; danezhang77 AT gmail.com
* 
* 56VFS may be copied only under the terms of the GNU General Public License V3
*/
#ifndef __PFS_SIG_SO_H
#define __PFS_SIG_SO_H
#include "list.h"
#include "global.h"
#include "pfs_init.h"
#include "md5.h"
#include "pfs_task.h"
#include "common.h"
#include <stdint.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <ctype.h>
#include <stropts.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <dirent.h>

#define SELF_ROLE ROLE_CS

enum SOCK_STAT {LOGOUT = 0, CONNECTED, LOGIN, IDLE, PREPARE_RECVFILE, RECVFILEING, SENDFILEING, LAST_STAT};

extern const char *sock_stat_cmd[] ;

typedef struct {
	list_head_t alist;
	int fd;
	int local_in_fd; /* ��cs���ܶԶ��ļ�����ʱ���򿪵ı��ؾ�� ��fd�ɲ���Լ����� */
	uint32_t hbtime;
	uint32_t ip;
	uint32_t headlen; /*��ǰ�����ļ���ͷ��Ϣ����*/
	uint8_t role;  /*FCS, CS, TRACKER */
	uint8_t sock_stat;   /* SOCK_STAT */
	uint8_t server_stat; /* server stat*/
	uint8_t mode;  /* active , passive */
	uint8_t close;
	uint8_t bk[3];
	md5_t ctx;
	t_pfs_tasklist *recvtask; /*��ǰ������·����ִ�е����ݽ������� */
	t_pfs_tasklist *sendtask; /*��ǰ������·����ִ�е����ݴ������� */
} pfs_cs_peer;

typedef struct {
	char username[64];
	char password[64];
	char host[32];
	int port;
} t_pfs_up_proxy;

#endif
