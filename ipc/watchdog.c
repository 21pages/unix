#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#include "config.h"
#include "vs_thread.h"
#include "watchdog.h"
#include "sem.h"
#include "vs_save.h"
#include "logger.h"
#include "rtv.h"

extern int g_deling;

s_watchdog_event g_watchdog_event[ID_EVENT_BUTT];
extern s_syn_ctrl syn_ctrl_watchdog;
extern struct vdIn videoIn[2];
extern AllConfig g_config; 

s_watchdog_idevent2idthread g_watchdog_idevent2idthread[ID_EVENT_BUTT]=
{
    {  ID_EVENT_RTV_0,    THREAD_RTV_0,  THREAD_RTV_SEND_0 },
    {  ID_EVENT_RTV_1,    THREAD_RTV_1,  THREAD_RTV_SEND_1 },
    {  -1            ,    -1            }
};

// ��ָ���¼�ι��
int watchdog_feed(int id_event)
{   
    pthread_mutex_lock(&g_watchdog_event[id_event].mutex);
    g_watchdog_event[id_event].event_counter++;
    pthread_mutex_unlock(&g_watchdog_event[id_event].mutex);
    return 0;
}

int watchdog_clear(int id_event)
{   
    pthread_mutex_lock(&g_watchdog_event[id_event].mutex);
    g_watchdog_event[id_event].event_counter= 0;
    pthread_mutex_unlock(&g_watchdog_event[id_event].mutex);
    return 0;
}

// rtv�߳�������Ӧ�õ��ô˺���ʹ�ܿ��Ź�
int watchdog_enable(int id_event)
{   
    pthread_mutex_lock(&g_watchdog_event[id_event].mutex);
    g_watchdog_event[id_event].event_enable = 1;
    pthread_mutex_unlock(&g_watchdog_event[id_event].mutex);
    return 0;
}

// rtv�߳�ֹͣ��Ӧ�õ��ô˺�����ֹ���Ź�
int watchdog_disable(int id_event)
{   
    pthread_mutex_lock(&g_watchdog_event[id_event].mutex);
    g_watchdog_event[id_event].event_enable = 0;
    pthread_mutex_unlock(&g_watchdog_event[id_event].mutex);
    return 0;
}

// rtv�߳�ÿ��ѭ������ι�����ú������м�顣 ����ֵ 0,��ʾ����ι��, 1��ʾ������, -1��ʾ�����������ȷ
int watchdog_checker_event(int id_event)
{
    int ret = 0;

    if((id_event<0) ||(id_event >= ID_EVENT_BUTT))
        return -1;
    
    pthread_mutex_lock(&g_watchdog_event[id_event].mutex);
    if(g_watchdog_event[id_event].event_counter == 0)
        ret = 1;
    else
    {   
        g_watchdog_event[id_event].event_counter = 0;
        ret = 0;
    }    
    pthread_mutex_unlock(&g_watchdog_event[id_event].mutex);
    
    return ret;
}

int id_event2id_thread(int id_event)
{
	int i;

	for(i=0; g_watchdog_idevent2idthread[i].id_event != -1; i++)
		if(id_event == g_watchdog_idevent2idthread[i].id_event)
			return i;
			
	return -1;

}

// δ����ι��ʱ�Ĳ���: ֹͣ��Ӧ�߳�
int watchdog_caller(int id_event)
{
    int ret;
    int num;
	
	pthread_mutex_lock(&g_watchdog_event[id_event].mutex);
	g_watchdog_event[id_event].event_enable = 0;
	pthread_mutex_unlock(&g_watchdog_event[id_event].mutex);
	
    num = id_event2id_thread(id_event);
    if(-1 == num)
        return -1;
    
    ret = thread_cancel(num);          // ֹͣ��Ӧ�߳�
    close_v4l(&videoIn[id_event]);
    if(-1 == ret)
        return 1;
   
        
    return 0;
}

// δ����ι��ʱ�Ĳ���: �����ӽ���
int watchdog_caller2(int id_event)
{
	logger(TLOG_ERROR, "rtv %d blocked! ipc will restart.", id_event);
	sys_quit();
        
    return 0;
}

int watchdog_checker()
{
    int i;
    int ret;

    for(i=0; i<ID_EVENT_BUTT; i++)
    {
        if(0 == g_watchdog_event[i].event_enable)
            continue;
            
        ret = watchdog_checker_event(i);    
        if(1 != ret) 
            continue;

			
        watchdog_caller(i);
    }
    return 0;
}

 


int thread_watchdog_main()
{
//	memset(buf, 1, 10240);
//	memset(buf1, 3, PGH);
    while ( !mapThreadID2Handler[THREAD_WATCHDOG].thread_quit_flag )
    {
        // �κ�rtv�߳������󣬶�Ӧ�����ÿ��Ź���־; ����rtv�߳��˳��󣬲���տ��Ź���־
//        thread_syn_wait(&syn_ctrl_watchdog.mutex_r, &syn_ctrl_watchdog.cond_r, &syn_ctrl_watchdog.flag_r);
		sleep(5);
        watchdog_checker();  
//	  if ((g_deling == 0))
//		ipc_savefile(buf,10240, 1, PIC_TYPE_CAP, g_config.store.percent_alarm.var, g_config.store.percent_del.var);		

    }
    
    return 0;
}


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
