/******************************************************************************

  Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_thread.h
  Version       : Initial Draft
  Author        : 
  Created       : 
  Last Modified :
  Description   : hi_thread.c header file
  Function List :
  History       :
  1.Date        : 
    Author      : Monster
    Modification: Created file

******************************************************************************/


#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */



#define LENGTH_BYTE_32                          32


#define MAX_LEN_USRENAME                        8
#define MAX_LEN_PASSWORD                        8
#define MAX_LEN_RULE_NAME                       16
#define MAX_LEN_RULE_IP                         16
#define LEN_RULE_MAC                            18

// ��Ϣͷ�汾��100:��ͨ��Ϣ��101:������Ϣ
#define CMD_VERSION_NORMAL                      100
#define CMD_VERSION_ENCRYPT                     101

// ������
#include "vs_config_cmd_id_auto.h"
#define CMD_ID_ERR_FORMAT_RES        1020


// ����ȶ���
#define HEAD_REQ_4                              4
#define HEAD_RES_5                              5

#define MAX_LEN_SERIAL_PARSER                   1024 * 64

typedef int(*fun_handler)(void *data);
typedef struct tag_cmd2Handler          /*  ������ţ�handler��Ӧ��   */
{
	int cmd_id;
	void *handler;
} s_cmd2Handler;


/*  ���� ����ͷ ����  */
typedef struct tag_cmd_req_head
{
    int version;                            /* �汾��       */
    int length;                             /* ָ���     */
    int ID;                                 /* ָ����     */
    int srandID;                            /* ָ�����     */
} s_cmd_req_head;

/*  ��������ͷ ����  */
typedef struct tag_cmd_res_head
{
    int version;                            /* �汾��       */
    int length;                             /* ָ���     */
    int ID;                                 /* ָ����     */
    int srandID;                            /* ָ�����     */
    int flag;                               /* �ɹ���־     */
} s_cmd_res_head;

#include "vs_config_rt_h_auto.h"
int sm_parser_init();
int vs_get_headtype(int head);
//int thread_parser_main();
int sm_scp_parser(char *buf, int len);
int sm_header_sequence_convert(char *cmd_header, int num);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __VS_THREAD_H__ */
