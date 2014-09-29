/***********************************************************************************
*              Copyright 2007 - 2010, Megaeyes. Co., Ltd.
*                           ALL RIGHTS RESERVED
* FileName: vs_save.c
* Description: main model.
*
* History:
* Version   Date              Author        DefectNum    Description
* 1.0       2007-10-16     sx                 NULL       Create this file.
***********************************************************************************/

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#include <stdlib.h>         /*  for malloc() */
#include <string.h>         /*  for memcpy() */
#include <dirent.h>         /* for opendir() */
#include <sys/vfs.h>        /* for statfs() */

#include <stdio.h>          /* for sprintf() */

#include <sys/stat.h>        /* for stat() */
#include <unistd.h>
#include <sys/types.h>       /* for mkdir() */
#include <sys/wait.h>
#include <fcntl.h>          /* for open */

#include <errno.h>           /* errno */
#include <pthread.h>
#include <time.h>

#include "vs_save.h"
#include "config.h"
#include "logger.h"
#include "rtv.h"
#include "vs_socket.h"
#include "sm_routine.h"
#include "sem.h"

GSaveAllData g_save_alldata;
extern AllConfig g_config;
extern int g_deling;
s_syn_ctrl syn_ctrl_dosfsck;
extern int g_dosfscking;

int open_fail_counter_chn_0;
int open_fail_counter_chn_1;

// ��ӡ�ļ�����������Ϣ
int vs_fs_print_err()
{
    switch (errno)
    {
    case EROFS :
        logger(TLOG_NOTICE, "��д����ļ�������ֻ���ļ�ϵͳ��\n");
        break;
    case EFAULT  :
        logger(TLOG_NOTICE, "����pathnameָ�볬���ɴ�ȡ�ڴ�ռ�\n");
        break;
    case ENAMETOOLONG  :
        logger(TLOG_NOTICE, "����pathname̫��\n");
        break;
    case ENOMEM  :
        logger(TLOG_NOTICE, "�����ڴ治��\n");
        break;
    case ELOOP  :
        logger(TLOG_NOTICE, "����pathname�й��������������\n");
        break;
    case EIO   :
        logger(TLOG_NOTICE, "I/O ��ȡ����\n");
        break;
    default :
        logger(TLOG_NOTICE, "��������errno=%d", errno);
        break;
    }

    return 0;
}


// ��ȡ����ʣ��ռ�
int get_xx_free(char *path, long *size_sum, long *size_useable, int *percent_useable)
{
    struct statfs stat;

    statfs(path,&stat);
    *size_useable = stat.f_bsize * stat.f_bfree;
    *size_sum = stat.f_bsize * stat.f_blocks;
    *percent_useable = 0;
    if ( stat.f_blocks > 0 )
    {
        *percent_useable = stat.f_bfree * 100 / stat.f_blocks;
    }

    g_config.store.sd_total_size.var = (int)(*size_sum / 1024 / 1024);
    g_config.store.sd_used_size.var = (int)((*size_sum - *size_useable) / 1024 / 1024);

#if 0
    printf("f_type    �ļ�ϵͳ���� = %ld\n", stat.f_type );
    printf("f_bsize   �����Ż��Ĵ�����С = %ld\n", stat.f_bsize );
    printf("f_blocks  �ļ�ϵͳ���ݿ����� = %ld\n", stat.f_blocks );
    printf("f_bfree   ���ÿ��� = %ld\n", stat.f_bfree );
    printf("f_bavail  �ǳ����û��ɻ�ȡ�Ŀ��� = %ld\n", stat.f_bavail );
    printf("f_files   �ļ�������� = %ld\n", stat.f_files );
    printf("f_ffree   �����ļ������ = %ld\n", stat.f_ffree );
    printf("f_namelen �ļ�������󳤶� = %ld\n", stat.f_namelen );
#endif
    return 0;
}

int xx_space_get(long *size_useable, long *size_sum, int *percent_useable){

	if(g_config.store.sd_status.var == 1){
        get_xx_free(ROOT_SD, size_sum, size_useable, percent_useable);
    }
	else{
        get_xx_free(ROOT_HD, size_sum, size_useable, percent_useable);
    }

    return 0;
}

/* ���̿ռ����
   percent_del  : ִ��ɾ���ٷֱȣ�����ʣ��ռ�ٷֱ�<=percent_del,�����ɾ������
   percent_alarm: ִ�и澯�ٷֱȣ�����ʣ��ռ�ٷֱ�<=percent_alarm,����и澯����
   ����Ϊ�˷�����㣬�ٷֱȶ�������*100
*/
int vs_space_manager(int percent_del, int percent_alarm)
{
    long size_useable;
    long size_sum;
    int percent_useable;
    int status;
    static int percent_useable_old = 0;

    xx_space_get(&size_useable, &size_sum, &percent_useable);

    if (percent_useable<=percent_alarm && percent_useable != percent_useable_old)
    {
        // ���ⷢ�ʹ��̿ռ�澯
//        rt_alarm_disk_set_req(NULL);
        alert_send_start(1);
        percent_useable_old = percent_useable;
//        logger(TLOG_WARNING, "disk space need free! useable percent=%d\%\n", percent_useable);
    }


    if (1 == g_config.store.auto_cover_older.var)
    {
        if (percent_useable<=percent_del)
        {
            int yymmdd, hhmmss;
            char cmd[256];
            memset(cmd, 0, 256);
            // ���ⷢ��ipcɾ������¼��ͼƬ�ļ�
//            rt_alarm_disk_set_req(NULL);
            alert_send_start(1);

//			vs_get_save_timename(&yymmdd, &hhmmss);
//			sprintf(cmd, "rm -fr /ipc/ipc_data/*; mkdir -p %s%d%s%s; mkdir -p %s%d%s%s",
//				DIR_ROOT_FTP, yymmdd, "/", "1", DIR_ROOT_FTP, yymmdd, "/", "2");

//			sprintf(cmd, "mkdir -p %s%d%s%s; mkdir -p %s%d%s%s",
//				DIR_ROOT_FTP, yymmdd, "/", "1", DIR_ROOT_FTP, yymmdd, "/", "2");

//			sprintf(cmd, "rm -fr /ipc/ipc_data/*");

            logger(TLOG_WARNING, "disk space full, force to clean file!");
            file_del_start();
//			call_rm_exe();
        }
    }

    return 0;
}

// ���ݵ�ǰʱ�䣬��VSP 3.0Э�� 8.2�½ڣ����ɴ洢�ļ�����
int vs_get_save_timename( int *yymmdd, int *hhmmss )
{
    time_t timep;
    struct tm *p;
    time(&timep);
    p=gmtime(&timep);


    *yymmdd = (1900+p->tm_year) * 10000 + (1 + p->tm_mon) * 100 + p->tm_mday;
    *hhmmss = p->tm_hour * 10000 + p->tm_min * 100 + p->tm_sec;

    return 0;
}


int dir_constrcut()
{
    char cmd_name_0[64]; 			// mkdir -p /ipc/ipc_data/20091208/1
    char cmd_name_1[64];
    int yymmdd, hhmmss;

    memset(cmd_name_0, 0, 64);
    memset(cmd_name_1, 0, 64);
    vs_get_save_timename(&yymmdd, &hhmmss);
    sprintf(cmd_name_0, "%s%s%d%s%s", "mkdir -p ", DIR_ROOT_FTP, yymmdd, "/", "1");
    sprintf(cmd_name_1, "%s%s%d%s%s", "mkdir -p ", DIR_ROOT_FTP, yymmdd, "/", "2");
    logger(TLOG_NOTICE, "dir contruct:%s, %s\n", cmd_name_0, cmd_name_1);
    system(cmd_name_0);
    system(cmd_name_1);

    return 0;
}



int chmod_777(char *file_name)
{
    char cmd_name[64];

    memset(cmd_name, 0, 64);
    sprintf(cmd_name, "%s%s", "chmod 777 ", file_name);
    system(cmd_name);
    return 0;
}

int file_name_construct(char *file_name, int yymmdd, int hhmmss, int pic_type, int channel )
{
    sprintf(file_name, "%s%d/%d/%02d%s",
            DIR_ROOT_FTP, yymmdd, channel,  hhmmss/10000, EXT_NAME);
//	logger(TLOG_NOTICE, "file_name_construct:%s,\n", file_name);

    return 0;
}


// ��һ֡����д���ļ�
int ipc_savefile(char *buf, int len, int channel, int pic_type, int percent_alarm, int percent_del)
{
    int ret;
    int fp;
    int curr_day =0;
    int curr_time = 0;
    char file_name[256];            // ͼƬ������ļ���������·��
    static int sync_count = 200;

    vs_space_manager(percent_del, percent_alarm);

    if (1 == g_deling)              // ��������ɾ��������������д������
    {
//        logger(TLOG_NOTICE, "ipc_save: g_deling ...");
        return 0;
    }
        

    if (1 == g_dosfscking)   // ���ڽ���dosfsck�������Ͳ����к���д�̲�����
    {
//        logger(TLOG_NOTICE, "ipc_save: dosfscking ...");
        return 0;
    }

    memset(file_name, 0, 256);
    vs_get_save_timename(&curr_day, &curr_time);
    file_name_construct(file_name, curr_day, curr_time, pic_type, channel);

    fp = open( file_name, O_WRONLY|O_CREAT|O_APPEND );

	if(fp == -1){
        logger(TLOG_ERROR, "ipc_save:file %s open failed, abort write, %d-%s", file_name, errno, strerror(errno));
        if (errno == 2)
        {
            dir_constrcut();
            return -1;
        }

        if(errno == 30)
		{
			logger(TLOG_NOTICE, "ipc_save: fat will repaired...");
			thread_syn_flag_set(&syn_ctrl_dosfsck.mutex_r, &syn_ctrl_dosfsck.cond_r, &syn_ctrl_dosfsck.flag_r);
			return -1;
        }

        /* 20100120 pgh bug:
           LOG:2010-01-19 11:44:49  ERRORR # ipc_save:file /ipc/ipc_data/20100119/1/11.jpg
           open failed, abort write, 30-Read-only file system
           �����ļ���������д
           ����Ӳ����д�ָ�����
           Ŀǰ����֪����ʲôԭ�����ļ�ϵͳΪֻ��

           �������: 1. �ļ�openʧ������10�κ�ipcֹͣ��
                        ��ʱRTU���ղ���������Ӧ����������Ӳ��
                     2. ����IPC֪ͨ RTU,RTU��������Ӳ��
        */
        if (1 == channel)
            open_fail_counter_chn_0++;
        else
            open_fail_counter_chn_1++;
        if (10 < open_fail_counter_chn_0)
        {
            logger(TLOG_ERROR, "ipc_save:channel %d open file failed times > 10, RTU should restart hardware!", channel);
            alarm_error_set(MSG_ALARM_ERR_FILE_OPT_ID, "channel 1 open file failed times > 10, RTU should restart hardware!");
            alert_send_start(4);

			g_config.sys_quit.flag.var = 0;
			sys_quit();
		
            return -1;
        }
        if (10 < open_fail_counter_chn_1)
        {
            logger(TLOG_ERROR, "ipc_save:channel %d open file failed times > 10, RTU should restart hardware!", channel);
            alarm_error_set(MSG_ALARM_ERR_FILE_OPT_ID, "channel 2 open file failed times > 10, RTU should restart hardware!");
            alert_send_start(4);

			g_config.sys_quit.flag.var = 0;
			sys_quit();

			return -1;
		}
		
		return -1;
    }
    write(fp, buf, len);
    close(fp);
    open_fail_counter_chn_0 = 0;
    open_fail_counter_chn_1 = 0;

    return 0;
}

int cache_savefile(unsigned char *buf, int len, int channel, int pic_type, int percent_alarm, int percent_del)
{
    int fp;
    int curr_day = (int)(((struct frame_t *)buf)->date);
    int curr_time = (int)(((struct frame_t *)buf)->time);
    char file_name[256];            // ͼƬ������ļ���������·��

    static int sync_count = 200;

    vs_space_manager(percent_del, percent_alarm);

    if (1 == g_deling)              // ��������ɾ��������������д������
    {
 //       logger(TLOG_NOTICE, "cache_save:g_deling ...");
        return 0;
    }
        

    if (1 == g_dosfscking)   // ���ڽ���dosfsck�������Ͳ����к���д�̲�����
    {
//        logger(TLOG_NOTICE, "cache_save:dosfscking ...");
        return 0;
    }

    memset(file_name, 0, 256);
    file_name_construct(file_name, curr_day, curr_time, pic_type, channel);

    fp = open( file_name, O_WRONLY|O_CREAT|O_APPEND );
	if(fp == -1){
        logger(TLOG_ERROR, "cache_save:file %s open failed, abort write, %d-%s", file_name, errno, strerror(errno));
        if (errno == 2)
        {
            dir_constrcut();
            return -1;
        }

		if(errno == 30)
		{
			logger(TLOG_NOTICE, "cache_save: fat will repaired...");
			thread_syn_flag_set(&syn_ctrl_dosfsck.mutex_r, &syn_ctrl_dosfsck.cond_r, &syn_ctrl_dosfsck.flag_r);
			return -1;
        }
			
        if (1 == channel)
            open_fail_counter_chn_0++;
        else
            open_fail_counter_chn_1++;
        if (10 < open_fail_counter_chn_0)
        {
            logger(TLOG_ERROR, "cache_save:channel %d open file failed times > 10, RTU should restart hardware!", channel);
            alarm_error_set(MSG_ALARM_ERR_FILE_OPT_ID, "channel 1 open file failed times > 10, RTU should restart hardware!");
            alert_send_start(4);

			g_config.sys_quit.flag.var = 0;
			sys_quit();

			return -1;
        }
        if (10 < open_fail_counter_chn_1)
        {
            logger(TLOG_ERROR, "cache_save:channel %d open file failed times > 10, RTU should restart hardware!", channel);
            alarm_error_set(MSG_ALARM_ERR_FILE_OPT_ID, "channel 2 open file failed times > 10, RTU should restart hardware!");
            alert_send_start(4);

			g_config.sys_quit.flag.var = 0;
			sys_quit();

			return -1;
        }

        return -1;
    }
    write(fp, buf, len);
    close(fp);
    open_fail_counter_chn_0 = 0;
    open_fail_counter_chn_1 = 0;

    return 0;
}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */






