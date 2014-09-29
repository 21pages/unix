#ifndef __VS_TIMER_H__
#define __VS_TIMER_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */


#include <time.h>
#include <stdio.h>
#include <signal.h>
#include <pthread.h>  

//#include "vs_def_videoProtocol_3.h"
//#include "vs_def_dataType.h"

#define SIGMYTIMER (SIGRTMAX)

#define MAX_TIMER_NODE_NUM     30           // timer�ȴ������нڵ��������: 0 ~ 30

typedef int(*CallBack_operation_timer)(void *data);

/***************************************************************************************************************
**** timer����ڵ�
**** 1. tm_first      :timer��һ�ε���ʱ��,2007.11.19 21:10:09
**** 2. tm_intervel   : �ظ���timer�ļ��ʱ��, ��ÿ300�����һ��ץ��
**** 3. mode          : timer���ظ�������0: ������timer   1: ������timer����n:�ظ�n����timer
                        ������timer: (1) ���ݵ�ǰʱ��͵���һ�ε���ʱ�̣�������Ҫ�ȴ�����������������timer
                        �ظ���timer: (1) ���ݵ�ǰʱ��͵�һ�ε���ʱ�̣�������Ҫ�ȴ�����������������timer
                                     (2) n = n-1;�������¼�����һ�εĵ���ʱ�̣����뵽�ȴ������У�ֱ����ɵ�����timer

**** 4. *timer_handler: timer��Ӧ�Ĵ�������ĿǰΪ��ͳһ����������ͬ�Ļص�������
***************************************************************************************************************/

typedef struct tag_timer_usr_data               // �ⲿ�û���Ҫ���͸�timer�ӿں���������
{
    int mode;                                   // timer���ظ�������0: ������timer   1: ������timer����n:�ظ�n����timer
    time_t tm_first;                            // timer��һ�ε���ʱ��
    int tm_intervel;                            // �ظ���timer�ļ��ʱ��    
    int tm_id;                                 // timer id�Ͷ����е�timerһһ��Ӧ�������ظ������ߡ������߽�����ʹ��id����ɾ����û���ڵ�timer
    CallBack_operation_timer timer_handler;                        // timer��Ӧ�Ĵ�����
    void *timer_handler_data;
} s_timer_usr_data;

typedef struct tag_timer_chain_node 
{
    s_timer_usr_data timer_usr_data;
    struct tag_timer_chain_node *pre;
    struct tag_timer_chain_node *next;   
} s_timer_chain_node;

// timer����ȫ�ֱ���
typedef struct tag_timer_manager_data
{
    int flag_wait;                              // timer�������߳��Ƿ�ȴ���־
    pthread_mutex_t mutex_chain_opt;            // ��timer��������Ļ�����
    pthread_mutex_t mutex_wait;                 // ���ڶ�д�̵߳�ͬ��
    pthread_cond_t cond_wait;
    int node_num;                               // �ȴ����еĽڵ���������ɾ���Ľڵ㡣�ڵ�����: 0 -- 100, ѭ��
    int timer_id;                               // ��timer_id,��Զֻ��������
}s_timer_manager_data;

/******************************************************************************************************************/
int vs_printf_timer_queue();
int timer_flag_wait_set();
int timer_flag_wait_clear();
int timer_chain_node_add(s_timer_usr_data *timer_usr_data);          // ��timer�ȴ�����������һ��timer,�˺����ṩ���ⲿģ����á�
int timer_chain_node_del_by_timerid(int timer_id);                   // ��timer�ȴ�������ɾ��һ��timer,�˺����ṩ���ⲿģ����á�    
int timer_usr_data_cp(s_timer_chain_node *timer_chain_node_new,s_timer_usr_data *timer_usr_data);
void timer_sinal_timer_handler();
int timer_signal_timer_add(int it_sec);
int timer_add(int it_sec, CallBack_operation_timer handler);
int timer_chain_node_instert(s_timer_usr_data *timer_usr_data);          // ��timer���в���һ���ڵ�
int timer_chain_free();
int timer_chain_node_delete();                                       // ��timer����ɾ����һ���ڵ�
int timer_get_frist_node_wt(time_t *time_wait);                            // ��ȡ��һ���ڵ�ĵȴ�ʱ�� = ��һ���ڵ�ĵ���ʱ�� - ��ǰϵͳʱ��                        
int timer_chain_node_handler();                                       // ��õȴ����еĵ�һ���ڵ㣬���ڣ���ִ����Ӧ����,������ϣ��ӵȴ�������ɾ���˽ڵ㣬����0,δ���ڣ��򷵻���Ҫ����Ҫ�ȴ�������,����ֵ>0
int vs_timer_chain_init();                                                  // ��ʼ��timer�����������ڵ�
int vs_timer_add(int second, int mode,int *timer_id );                   //�����뵱ǰʱ�����second�뵽�ڵ�1����timer
int vs_timer_add2(int mode,time_t second, int tm_intervel, void *handler, void *handler_data,int *timer_id);       
int vs_timer_del(int timer_id);                                             // ɾ��timer_id��Ӧ��timer
int thread_timer_main();

/******************************************************************************************************************/
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __VS_TIMER_H__ */

