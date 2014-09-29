#ifndef __CGI_TYPES_H__
#define __CGI_TYPES_H__

#include "config.h"

/************************Global Define***********************/
//#define DEBUG 1

#define SEGSIZE 2048 //1024*2

#define CGI_SET_DATA 	0
#define CGI_GET_DATA 	1

#define ID_CGI_LOGIN_ACTION	0
#define ID_CGI_RTV_SET_ACTION	1
#define ID_CGI_NETWORK_SET_ACTION	2
#define ID_CGI_ALERT_SET_ACTION	3
#define ID_CGI_STORE_SET_ACTION	4
#define ID_CGI_USER_SET_ACTION	5
#define ID_CGI_SYS_SET_ACTION	6

// ��ҳ��ÿһ���ύ����Ӧһ��CGI,��Ӧһ��vs��CGI����������ǵ����ӹ�ϵ:
// cgi_data_DS -- id_cgi_data_DS    id_cgi_handler -- cgi_handler
// ֻҪ�����ڴ��˫����id_cgi_data_DS/id_cgi_handlerʹ����ͬ�ı�ţ�����ʵ���ύ��vs�������Ķ�Ӧ
typedef int(*cgi_CallBack_operation)(char *p_shm);
typedef struct tag_map_CGI_flag2Handler
{

	int id_cgi_handler;
	cgi_CallBack_operation cgi_handler;               // �����ӦCGI��handler
} s_map_CGI_flag2Handler;
/************************login**************************/

typedef struct tag_cgi_login_action   // ��¼ҳ�����ݽṹ
{
	char username[32];
	char password[32];
} s_cgi_login_action;

#endif

