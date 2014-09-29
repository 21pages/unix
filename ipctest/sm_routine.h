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


#ifndef __SM_ROUTINE_H__
#define __SM_ROUTINE_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

// IPC����������Ϣ���û���������
#define IPC_USERNAME                        "IPC"
#define IPC_PASSWORD                        "123456"

#define MSG_RES_FLAG_SUC                    0                // ��Ӧ��Ϣ���ɹ�
#define MSG_RES_FLAG_ERR_MALLOC             1                // ��Ӧ��Ϣ��ʧ�ܣ��ڴ����ʧ��
#define MSG_RES_FLAG_ERR_FILE               2                // ��Ӧ��Ϣ��ʧ�ܣ��ļ�����ʧ��
#define MSG_RES_FLAG_ERR_XML                3                // ��Ӧ��Ϣ��ʧ�ܣ�xml����
#define MSG_RES_FLAG_ERR_LOGIN_USR          4                // ��Ӧ��Ϣ��ʧ�ܣ���¼�û�������
#define MSG_RES_FLAG_ERR_LOGIN_PWD          5                // ��Ӧ��Ϣ��ʧ�ܣ���¼�������
#define MSG_RES_FLAG_ERR_LOGIN_NO           6                // ��Ӧ��Ϣ��ʧ�ܣ�û�е�¼
#define MSG_RES_FLAG_ERR_LOGIN_TIMEOUT      7                // ��Ӧ��Ϣ��ʧ�ܣ���¼��ʱ
#define MSG_RES_FLAG_ERR_PASSWORD           8                // ��Ӧ��Ϣ��ʧ�ܣ�����������֤ʧ��
#define MSG_RES_FLAG_ERR_FORMAT_STA         9                // ��Ӧ��Ϣ��ʧ�ܣ����յ�����Ϣ��ʼ�ֽڲ���ȷ
#define MSG_RES_FLAG_ERR_FORMAT_END         10               // ��Ӧ��Ϣ��ʧ�ܣ����յ�����Ϣ�����ֽڲ���ȷ
#define MSG_RES_FLAG_ERR_FORMAT_VER         11               // ��Ӧ��Ϣ��ʧ�ܣ����յ�����Ϣ�汾����ȷ
#define MSG_RES_FLAG_ERR_FORMAT_CMD         12               // ��Ӧ��Ϣ��ʧ�ܣ����յ�����Ϣ�汾ָ����벻��ȷ
#define MSG_RES_FLAG_ERR_IP                 13               // ��Ӧ��Ϣ��ʧ�ܣ����յ���IP��ַΪ��

#define MSG_RES_FLAG_ERR_PASSWD_FULL        14               // ��Ӧ��Ϣ��ʧ�ܣ��û��������������û�ʧ��
#define MSG_RES_FLAG_ERR_PASSWD_EMPTY       15               // ��Ӧ��Ϣ��ʧ�ܣ��û�δ�ҵ���ɾ���û�ʧ��
#define MSG_RES_FLAG_ERR_PASSWD_FRAIL       16               // ��Ӧ��Ϣ��ʧ�ܣ�������ǿ�Ȳ���

#define MSG_RES_FLAG_ERR_CHN                17               // ��Ӧ��Ϣ��ʧ�ܣ�channel�Ŵ���
#define MSG_RES_FLAG_ERR_PIC_NUM            18               // ��Ӧ��Ϣ��ʧ�ܣ�ץ�������ץ������<=0
#define MSG_RES_FLAG_ERR_DATETIME_FORMAT    19               // ��Ӧ��Ϣ��ʧ�ܣ�ʱ���ʽ����ȷ
#define MSG_RES_FLAG_ERR_ADMIN_NULL         20               // ��Ӧ��Ϣ��ʧ�ܣ�ϵͳ����Ա�û���������Ϊ��

// IPC�������������ش���澯����
#define MSG_ALARM_ERR_FILE_OPT_ID           1             // �ļ��������ش���Ŀǰ���¼���ļ�����ʱ�Ĵ�ʧ��

typedef struct tag_xml
{
    char *context;
    int len;
} s_xml;

/********************************** IPC begin *******************************************/
#define ROUNTINE_COMM_1(cmd_head_id, var_st, s_var_st, var_st_index, buf, outbuf, xml, srand_id, ret) do{ \
	memset((char *)&var_st, 0, sizeof(s_var_st));			\
    memset(outbuf, 0, 10240);                                                                             \
    srand_id_get(buf, &srand_id);                                                                        \
    xml_get(buf, &xml);                                                                                  \
	ret = xml2struct(xml.context, xml.len, (char *)&var_st, var_st_index, all_xml_find_desc);             \
	if(0 != ret){                                                                                         \
        rountin_common_flag(cmd_head_id, MSG_RES_FLAG_ERR_XML, srand_id, *(int *)buf);                                      \
        return ;                                                                                          \
    }	\
    ret = user_info_check(var_st.user_info.username, var_st.user_info.password);                                \
    if(-1 == ret){                                                                                         \
        rountin_common_flag(cmd_head_id, MSG_RES_FLAG_ERR_LOGIN_PWD, srand_id, *(int *)buf);                                \
        return ;                                                                                          \
    }                                                                                                     \
}while(0)

#define ROUNTINE_COMM_2(cmd_head_id, st, s_st, s_st_index, buf, outbuf, xml, srand_id, ret) do{ \
	memset((char *)&st, 0, sizeof(s_st));			\
    memset(outbuf,	 0, 10240);                                                                             \
    srand_id_get(buf, &srand_id);                                                                        \
    xml_get(buf, &xml);                                                                                  \
	ret = xml2struct(xml.context, xml.len, (char *)&st, s_st_index, all_xml_find_desc);             \
	if(0 != ret){                                                                                         \
        rountin_common_flag(cmd_head_id, MSG_RES_FLAG_ERR_XML, srand_id, *(int *)buf);                                      \
        return ;                                                                                          \
    }	\
    ret = user_info_check(st.username, st.password);                                \
    if(-1 == ret){                                                                                         \
        rountin_common_flag(cmd_head_id, MSG_RES_FLAG_ERR_LOGIN_PWD, srand_id, *(int *)buf);                                \
        return ;                                                                                          \
    }                                                                                                     \
}while(0)


// ���ͳɹ���Ӧ
#define ROUNTINE_COMM_RES_SUCCESS(cmd_id, srand_id, socket_id) do{								\
    rountin_common_flag(cmd_id, MSG_RES_FLAG_SUC, srand_id, socket_id);                                            \
}while(0)

// ����ʧ����Ӧ
#define ROUNTINE_COMM_RES_FAIL(cmd_id, flag, srand_id, socket_id) do{								\
    rountin_common_flag(cmd_id, flag, srand_id, socket_id);                                            \
}while(0)


// rt��������
#include "vs_config_rt_h_auto.h"

int rountin_common_flag(int cmd_head_ID, int success_flag, int link_type, int ret_socketid);
int rountin_common_res_data(int cmd_head_ID, char *data, int data_len, int flag, int link_type, int ret_socketid);
int rountin_common_req_data(int cmd_head_ID, char *data, int data_len, int link_type, int ret_socketid);
int limit_video_para();


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __VS_THREAD_H__ */

