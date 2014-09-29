#ifndef __VS_SAVE_H__
#define __VS_SAVE_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#include <stdio.h>
#include <time.h>

#define ROOT_SD                 "/ipc/ipc_data"
#define ROOT_HD                 "/"

#define DIR_ROOT_FTP            "/ipc/ipc_data/"        // ftp��Ŀ¼               
#define DIR_HTV                 "htv/"              // ��ʷ��Ƶ��Ŀ¼
#define DIR_PIC                 "pic/"              // ץ��ͼƬ��Ŀ¼
#define EXT_NAME                ".jpg"              // ͼƬ�ļ���չ��
#define PIC_TYPE_HTV                    0
#define PIC_TYPE_CAP                    1

typedef struct tagGSaveAllData
{
    char        save_cap_base_folder[256];        // ����ͼƬ�Ļ���Ŀ¼
    long        delete_min_space;   // ��Сɾ���Ŀռ�
    int         delete_min_percent; // ��Сɾ���Ĵ��̰ٷֱ�

    int         auto_delete_cap_day;    // �Զ�ɾ��������ǰ��ͼƬ�ļ�
    int         is_auto_delete;         // �Ƿ��Զ�ɾ��
} GSaveAllData;

int ipc_savefile(char *buf, int len, int channel, int pic_type, int percent_alarm, int percent_del);
int xx_space_get(long *size_useable, long *size_sum, int *percent_useable);
int dir_constrcut();
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __VS_SAVE_H__ */


/* --------------------------------------------------------
����һ��¼����ҪЩʲô���Ĳ�������
[save_video_param]
A. �����������ͷ
save_camera_type = "1230"      // ��Щ��ȡʲô����
   // 0: ��ʾ������ 1,2,3�ֱ��ʾ����1,2,3

[save_video_param_0]
[save_video_param_1]
[save_video_param_2]
[save_video_param_3]
B. ���ĳ������ͷ

����1��
    ������¼��
����2��
    ÿ�춨�㿪ʼ¼��ÿ��¼һ��ʱ��. ��Ϊ4��ʱ���
    ͬʱ��������ܼ�����һ�졣
����3��
    �ƻ�������¼��,ÿ��Сʱ�ж�һ�Σ�ÿ��һ��Сʱ.�е��񲼷�ʱ��
��Ա�����
    ����ʱ�Ĳ���������

����������£�
// ������1ʱ�������ر����

// ������2ʱ
save_week = "0101010"  // �ܼ���Ч
save_hour1 = "10:15:30" // ÿ��Ķ���ʱ��
save_hour2 = "10:15:30" // ÿ��Ķ���ʱ��
save_hour2 = "10:15:30" // ÿ��Ķ���ʱ��
save_hour3 = "10:15:30" // ÿ��Ķ���ʱ��
save_timelen = 60      // �������

// ������3ʱ
save_allweek = "1100100010101010100101010100101010101001010101011001" //ÿ�ܵ��ܼƻ������㲼��





-------------------------------------------------------- */







