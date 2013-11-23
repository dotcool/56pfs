/*
* Copyright (C) 2012-2014 www.56.com email: jingchun.zhang AT renren-inc.com; jczhang AT 126.com ; danezhang77 AT gmail.com
* 
* 56VFS may be copied only under the terms of the GNU General Public License V3
*/
#ifndef __NM_C_API_DOG_H_
#define __NM_C_API_DOG_H_
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <math.h>
#include <stdint.h>
#include <ctype.h>
#include <stddef.h>

typedef struct
{
	int flag;  //flag = 0, pid ������ ����������flag = 1 ����pid�Ƿ���ڣ���������
	int intval;  //��������ʱ�䣬dog��ɱ������
	time_t last;  //�������ʱ���
	char cmd[256];  //����·������
	char argv[10][64];  //��������
}T_WATCH_DOG;

#ifdef __cplusplus
extern "C"
{
#endif
	int reg_process(pid_t pid, T_WATCH_DOG *dog);
	int update_process(pid_t pid, T_WATCH_DOG *dog);
	int touch_process();
#ifdef __cplusplus
}
#endif
#endif
