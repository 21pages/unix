#include "cgic.h"
#include "cgi_types.h"
#include "cgi_sem_utils.h"
#include "cgi_html_utils.h"

/* ��web server������ݣ��������������ڴ���
�������: ��
�������: p_cgi_login_action
*/
int cgi_login_action(char *p_shm)
{	
	char name[48];
	char password[48];

	memset(name,0,48);
	memset(password,0,48);

	s_cgi_login_action* p_cgi_login_action;


	if ( NULL == p_shm ) 
	{
		puts("get null struct ");
		return -1;
	}  

	cgiFormString("cnname", name, 48);
	cgiFormString("cnpwd", password, 48);

	*(int *)(p_shm + sizeof(int)) = 0;
	*(int *)(p_shm + sizeof(int)*2) = 0;

	p_cgi_login_action = (s_cgi_login_action *)(p_shm + sizeof(int)*3);
	strcpy(p_cgi_login_action->username,name);
	strcpy(p_cgi_login_action->password,password);

	printf("p_cgi_login_action->username=%s\n", p_cgi_login_action->username);
	printf( "p_cgi_login_action->password=%s\n", p_cgi_login_action->password);

	//web server to do
	//fputs(name,stdout);
	//fputs(password,stdout);
	return 0;
}

int cgi_login_puts()
{
//	char *content="<span class='tle2'>ab������</span><br><input class='button' type='button' value='go��' />		come<input class='filestyle'  type='file' />		<input class='button3' type='button' value='go��' />";
	
//	cgiHeaderContentType("text/html; charset=gb2312");
	cgiHeaderLocation("cgi_rtv_set?flag=1");
/*
	CGI_HTML_HEAD_PUT("Hi");
	CGI_HTML_BODY_LOGO_MENU_PUT;
	CGI_HTML_BODY_CONTENT_PUT(content);
	CGI_HTML_BODY_COPYRIGHT_PUT;
	CGI_HTML_TAIL_PUT;
*/
	return 0;
}

int cgiMain(void) 
{    
	int ret;
	key_t key; 
	key_t key_cgi;

	int shm_id,sem_id, sem_id_cgi; 
	char *shm; 

	// ���������������ڴ�
	key       = ftok("./vs_shm",0); 
	key_cgi  = ftok("./vs_shm_cgi",0); 
	shm_id  = shmget(key,SEGSIZE,0); 
	if(-1 == shm_id)
	{
		cgiHeaderContentType("text/html; charset=gb2312");
		puts("<html><head><title>share memeroy error</title><h1><font color='red'>create shared memory error</f><h1><html><head>"); 
		return -1; 
	} 

	shm = (char *)shmat(shm_id,0,0);
	if (-1 == (int)shm)
	{ 
		cgiHeaderContentType("text/html; charset=gb2312");
		puts(" attach shared memory error\n"); 
		return -1; 
	} 

	// ����������
	sem_id     = sem_creat(key);                      // vs������������ڴ��ź���
	sem_id_cgi = sem_creat(key_cgi);                  // �ⲿ����cgi���������ڴ��ź���
 
	cgi_login_action(shm);       
	v(sem_id);             
	p(sem_id_cgi);


	ret = *(int *)shm;
	if(0 != ret )                           // ���󷵻�
	{
		char temp[32];
		//         
		sprintf(temp,"error is %d\n",ret);
		cgiHeaderContentType("text/html; charset=gb2312");
		puts("<html><head><title>login error</title><h1><font color='red'>wrong username or password</f><h1>"); 
		puts(temp);
		//post_v(sem_id);
		return -1;    
	}

	// vs��¼��֤�����ȷ,����ʵʱ��Ƶҳ��
	cgi_login_puts();

	/**************************************/  


	shmdt(shm); 
	//del_sem(sem_id); 
	//del_sem(sem_id_cgi);

	return 0; 
	// gcc -o shmc shmC.c -g 
} 


