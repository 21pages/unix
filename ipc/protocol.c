/***********************************************************************************
*              Copyright 2007 - 2010, Megaeyes. Co., Ltd.
*                           ALL RIGHTS RESERVED
* FileName: hi_server.c
* Description: main model .
*
* History:
* Version   Date              Author        DefectNum    Description
* 1.1       2007-08-22   q60002125     NULL            Create this file.
***********************************************************************************/




#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#include "protocol.h"
#include "sm_routine.h"
#include "logger.h"
#include "vs_config_cmd_id_auto.h"
#include "vs_config_cmd_auto.h"



/* ������ID���handler��Ӧ������ƥ�����鵥Ԫ��  */
int handler_get(int cmd_id)
{
	int i;
	for(i=0; cmd2Handler[i].handler!= NULL; i++)
		if(cmd_id == cmd2Handler[i].cmd_id)
			return i;
	return -1;
}

/* ���ݲ�ͬ����ID��ţ�����handler��Ӧ���õ�������ڣ����øú���*/
int sm_handler(int cmd_id, void *handler_para)
{
	fun_handler handler;
	int ret;
	int num_match;
	
	handler = 0;

	num_match = handler_get(cmd_id);
	if(num_match < 0)   
	{
	    logger(TLOG_NOTICE, "sm_handler cmd_id do not match, cmd_id=%d", cmd_id);
	    rountin_common_flag(CMD_ID_ERR_FORMAT_RES, MSG_RES_FLAG_ERR_FORMAT_CMD, 0, *(int *)handler_para);
		return -1;
    }
	
	handler = cmd2Handler[num_match].handler;
	ret = handler(handler_para);
	
	return 0;
}

/* �����ֽ���ת: 100  x86Ϊ: 64 00 00 00  ppcΪ00 00 00 64, 
   p_intָ��Ҫת���������׵�ַ    */
int sequence_convert_int(char *p_int)
{   
    int i;
    char *p_loc;
    char tmp_int[4];

    p_loc = p_int;
    memcpy(tmp_int, p_loc, 4);

    for(i=0; i<4; i++)
    {
        *p_loc = tmp_int[3 - i];
        p_loc++;    
    }

    return 0;  
}

// Э��ͷ�ֽ���ת��, ת�������������ε��ֽ���
int sm_header_sequence_convert(char *cmd_header, int num)
{
    int i = 0;
    char *p_int;

    p_int = cmd_header;
    while(i < num)
    {
        sequence_convert_int(p_int);
        p_int += 4;
        i++;
    }

    return 0;
}



#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

