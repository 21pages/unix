#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#include <string.h>
#include <stdlib.h>   		// for malloc()
#include <unistd.h>         // for sleep()
#include <sys/time.h>         // for setitimer()
#include <time.h>
#include <signal.h>         // for signal()

//#include "vs_main_rountin.h"
//#include "vs_config.h"
#include "vs_timer.h"
#include "logger.h"

s_timer_chain_node  g_timer_chain_node_root;
s_timer_manager_data g_timer_manager_data;
// timer_t IDList[20]; //use to save timer id;

int     g_quit_timer = 0;    // ��1 ʱ�˳�timer_main �߳�


// ��ȡ����ǰʱ������������ʱ�������
int timer_next_hour_get(time_t time, int *second)
{
    int ret;
    struct tm *p;

    ret = timer_hour_judge(time);
    if(0 == ret)
    {
        *second = 0;
        return 0;
    }

    p = gmtime( &time );
    *second =(60 - p->tm_min -1) * 60 + (60 - p->tm_sec);
    return 0;
}

// �жϸ�����time�Ƿ�Ϊ���� ����ֵ 0, ���� 1,������
int timer_hour_judge(time_t time)
{   
    int ret;
    struct tm *p;
    
    p = gmtime( &time );  
    ret = p->tm_min;
    if(0 != ret)
        return 1;
    ret = p->tm_sec;
    if(0 != ret)
        return 1;
        
    return 0;
}


// ��ӡ��ǰtimer���еĽڵ��
int vs_printf_timer_queue()
{
    s_timer_chain_node *ptimer_node;            // timer�ڵ�ָ��

//    logger(TLOG_NOTICE, "*** ��ǰtimer���нڵ�:");
    
    ptimer_node = g_timer_chain_node_root.next;   
    while(NULL != ptimer_node)
    {
//        logger(TLOG_NOTICE, "%d, ", ptimer_node->timer_usr_data.tm_id);
        ptimer_node = ptimer_node->next;
    }
//    logger(TLOG_NOTICE, "\n");

    return 0;
}

int timer_flag_wait_set()
{
    pthread_mutex_lock(&g_timer_manager_data.mutex_wait);
    g_timer_manager_data.flag_wait= 1;
    pthread_cond_signal(&g_timer_manager_data.cond_wait);
    pthread_mutex_unlock(&g_timer_manager_data.mutex_wait);
    return 0;
}

int timer_flag_wait_clear()
{
    pthread_mutex_lock(&g_timer_manager_data.mutex_wait);
    g_timer_manager_data.flag_wait= 0;
    pthread_cond_signal(&g_timer_manager_data.cond_wait);
    pthread_mutex_unlock(&g_timer_manager_data.mutex_wait);
    return 0;
}

// ��ȡ��һ���ڵ�ĵȴ�ʱ�� = ��һ���ڵ�ĵ���ʱ�� - ��ǰϵͳʱ��
int timer_get_frist_node_wt(time_t *time_wait)
{
    time_t time_current; 
    s_timer_chain_node *timer_chain_node_frist;
    
    timer_chain_node_frist = g_timer_chain_node_root.next;

    // �ж�timer�����Ƿ�Ϊ�ա�ǰ�����������Ӧ��ʹ�ø�������ᷢ����
    if(timer_chain_node_frist == NULL)
    {
        logger(TLOG_ERROR, "��һ���ڵ�Ϊ��,�޷���ȡ��һ���ڵ�ĵȴ�ʱ��\n");
        return 1;
    }
 
    time_current = time((time_t *)NULL);
    *time_wait = timer_chain_node_frist->timer_usr_data.tm_first- time_current;

    return 0;
}


int timer_usr_data_cp(s_timer_chain_node *timer_chain_node_new,s_timer_usr_data *timer_usr_data)
{
    timer_chain_node_new->timer_usr_data.mode = timer_usr_data->mode;
    timer_chain_node_new->timer_usr_data.tm_first = timer_usr_data->tm_first;
    timer_chain_node_new->timer_usr_data.tm_id = timer_usr_data->tm_id;
    timer_chain_node_new->timer_usr_data.tm_intervel = timer_usr_data->tm_intervel;
    timer_chain_node_new->timer_usr_data.timer_handler = timer_usr_data->timer_handler;
    timer_chain_node_new->timer_usr_data.timer_handler_data = timer_usr_data->timer_handler_data;
    
    return 0;
}


void timer_sinal_timer_handler()
{
#ifdef debug_printf_timer
//    logger(TLOG_NOTICE, "�����źŵ�timer����\n");
#endif

    return ;
}

// ���һ����ʱ�����źŵ�timer
// �˺������ڲ�����½ڵ��ڵ�һ���ڵ�֮ǰ��ʱ�򣬵��ô˺�������һ��n���timer��
// ��timer�������ڣ����ӵ�timerģ��������С���ʱ����alarm�źţ����ж���timer�߳�
// �ô˺����Ǹ�Ȩ��֮�ƣ�����Ӧ���ڲ�����½ڵ��ڵ�һ���ڵ�֮ǰ��ʱ��ֱ�ӷ���alarm�źţ����ж���timer�߳�
// ���ǣ�Ŀǰ��֪����ôֱ�ӷ����ź�
int timer_add(int it_sec, CallBack_operation_timer handler)
{
    struct itimerval value;

    signal(SIGALRM, handler);//timer_sinal_timer_handler);   
    //value.it_interval.tv_sec = it_sec;
    value.it_interval.tv_sec = 0;
    value.it_interval.tv_usec = 0;
    value.it_value.tv_sec = it_sec;
    value.it_value.tv_usec = 0;
    setitimer(ITIMER_REAL, &value, NULL);

    return 0;
}

int timer_signal_timer_add(int it_sec)
{
    struct itimerval value;

    signal(SIGALRM, timer_sinal_timer_handler);   
    //value.it_interval.tv_sec = it_sec;
    value.it_interval.tv_sec = 0;
    value.it_interval.tv_usec = 0;
    value.it_value.tv_sec = it_sec;
    value.it_value.tv_usec = 0;
    setitimer(ITIMER_REAL, &value, NULL);

    return 0;
}

// ��timer�ȴ�����������һ��timer,�˺����ṩ���ⲿģ����á�
int timer_chain_node_add(s_timer_usr_data *timer_usr_data)
{
    timer_chain_node_instert(timer_usr_data);
    
    return 0;
}


// ���timer����ӦsxҪ��ר���ṩ�˺�����������ǿ���Ƴ�ǰ��free���нڵ� ; pgh ,�����ǿ����ֹ����ʱ�ǵõ��ô˺���
int timer_chain_free()
{
    s_timer_chain_node *p_timer_chain_node_cur;             // ��ǰ�ڵ�
    s_timer_chain_node *p_timer_chain_node_pre;
    s_timer_chain_node *p_timer_chain_node_next;

    p_timer_chain_node_cur = g_timer_chain_node_root.next;
    if(p_timer_chain_node_cur == NULL)
        return 0;

    while(p_timer_chain_node_cur != NULL)
    {
        p_timer_chain_node_pre = p_timer_chain_node_cur->pre;
        p_timer_chain_node_next = p_timer_chain_node_cur->next;
        if(p_timer_chain_node_next != NULL)
        {
            p_timer_chain_node_next->pre = p_timer_chain_node_pre;
        }
       
        p_timer_chain_node_pre->next = p_timer_chain_node_next;
        g_timer_manager_data.node_num--;
        free(p_timer_chain_node_cur);

        p_timer_chain_node_cur = p_timer_chain_node_next;
    }

    return 0;
}


// ��timer�ȴ�������ɾ��һ��timer,�˺����ṩ���ⲿģ����á�
// ��ɾ���Ľڵ�Ϊ��һ���ڵ��ʱ�򣬷��ź�, ʹtimer���߳��ж�sleep  timer_signal_timer_add(1);    
// ����ֵ: 0, δ�ҵ�ƥ��id, 1: ƥ�䣬���Ѿ�ɾ��
int timer_chain_node_del_by_timerid(int timer_id)
{
    int match;                              // �Ƿ��ҵ�timer_id��ͬ�Ľڵ�

    match = 0;
    s_timer_chain_node *p_timer_chain_node_cur;             // ��ǰ�ڵ�
    s_timer_chain_node *p_timer_chain_node_pre;
    s_timer_chain_node *p_timer_chain_node_next;
    
    p_timer_chain_node_cur = g_timer_chain_node_root.next;

    if(p_timer_chain_node_cur == NULL)
    {
#ifdef debug_printf_timer
        logger(TLOG_ERROR, "��ǰtimer���пգ��޷�ɾ��ָ��timer��timer_id=%d\n", timer_id);
#endif
        return match;
    }    
    
    // ���ҽڵ㣬��ɾ��
    while(p_timer_chain_node_cur != NULL)
    {
        if(p_timer_chain_node_cur->timer_usr_data.tm_id != timer_id)
        {
            p_timer_chain_node_cur = p_timer_chain_node_cur->next;
        }
        else
        {
            match = 1;

            // ��Ҫɾ���Ľڵ�Ϊ��һ���ڵ��ʱ�򣬷��ź�, ʹtimer���߳��ж�sleep  
            if(p_timer_chain_node_cur == g_timer_chain_node_root.next)
                timer_signal_timer_add(1);
        
            p_timer_chain_node_pre = p_timer_chain_node_cur->pre;
            p_timer_chain_node_next = p_timer_chain_node_cur->next;
            if(p_timer_chain_node_next != NULL)
            {
                p_timer_chain_node_next->pre = p_timer_chain_node_pre;
            }
           
            p_timer_chain_node_pre->next = p_timer_chain_node_next;
            g_timer_manager_data.node_num--;
            free(p_timer_chain_node_cur);

#ifdef debug_printf_timer
            logger(TLOG_NOTICE, "timer_chain_node_del_by_timerid(),������ֱ��ɾ���ڵ�ɹ�,�ڵ��=%d\n",timer_id);       
#endif
#ifdef debug_printf_timer_queue
            vs_printf_timer_queue();
#endif

            // ���timer���գ����õȴ���־
            if(g_timer_chain_node_root.next == NULL)
                timer_flag_wait_set();
            
            break; 
        }                
    }

    if(0 == match)
    {
#ifdef debug_printf_timer
            logger(TLOG_NOTICE, "��ǰtimer���в��գ������Ҳ���ָ��timer��timer_id=%d\n", timer_id);  
#endif
    }


    return match;
}

// ��timer���в���һ���ڵ�
// timer�������ڵ�ʱ���Ⱥ�˳������
// ������Ľڵ��ڵ�һ���ڵ�ǰ��ʱ����Ҫ���źţ�ʹtimer���߳��ж�sleep
int timer_chain_node_instert(s_timer_usr_data *timer_usr_data)
{
    s_timer_chain_node *p_timer_chain_node_new;             // Ҫ����Ľڵ�ָ��
    s_timer_chain_node *p_timer_chain_node_cur;             // timer������ʱ��ÿ���ڵ��ָ��
    s_timer_chain_node *p_timer_chain_node_pre;             // ��ǰ�ڵ��ǰһ���ڵ�
    int nofind;

    // ��Ϊ���ڶ����timer,��Ҫ��ɾ���ڵ�ǰ����һ�������ڵ㣬����Ϊ�˼򻯣�����ʹ�����ֵ-1
    if((g_timer_manager_data.node_num + 1) == MAX_TIMER_NODE_NUM)
    {
        logger(TLOG_NOTICE, "����timerʧ�ܣ�timer�����Ѿ��ﵽ����ֵ\n");
        return 1;
    }
    
    // ����ռ�
    p_timer_chain_node_new = (s_timer_chain_node *)malloc(sizeof(s_timer_chain_node));
    if(p_timer_chain_node_new == NULL)
    {
        logger(TLOG_NOTICE, "����timerʧ�ܣ��ڴ����ʧ��\n");
        return 1;
    }

    // ���timer_id
    timer_usr_data->tm_id = g_timer_manager_data.timer_id;  
    g_timer_manager_data.timer_id++;
    
    // ��������
    timer_usr_data_cp(p_timer_chain_node_new,timer_usr_data);      
    p_timer_chain_node_new->pre = NULL;
    p_timer_chain_node_new->next = NULL;
   
    // ����timer��������ڵ㡣
    // timer����expire_time��ʱ���Ⱥ�˳������Ŀǰ����˳��Ϊ��ǰ��󣬽���Ż��ɸĳɴӺ���ǰ��
    nofind = 1;
    p_timer_chain_node_cur = g_timer_chain_node_root.next;
  
    // ��p_timer_chain_node_cur�ڵ�ǰ�����½ڵ�,�������Ϊ������ֱ�Ӳ��뵽����
    // ���ʱ��timer�߳�Ӧ�����ڱ�����ס����������sleep,���Բ���Ҫ���ź����ж�sleep
    if(p_timer_chain_node_cur == NULL)
    {
        p_timer_chain_node_new->next = NULL;
        g_timer_chain_node_root.next = p_timer_chain_node_new;
        p_timer_chain_node_new->pre = &g_timer_chain_node_root;  

        // ���ź�, ʹtimer���߳��ж�sleep
        //timer_signal_timer_add(1);
    }
    else
    {     
        while(nofind && (p_timer_chain_node_cur != NULL))   // ���ҵ�һ���ڵ�:�ڵ㵽��ʱ�� >= �½ڵ㵽��ʱ��
        {
            
            if(p_timer_chain_node_cur->timer_usr_data.tm_first < p_timer_chain_node_new->timer_usr_data.tm_first)
            {
                p_timer_chain_node_pre = p_timer_chain_node_cur;
                p_timer_chain_node_cur = p_timer_chain_node_cur->next;
            }
            else
            {
                nofind = 0;
                break;
            }     
        }

        // �ҵ��ڵ�ĵ���ʱ����������ڵ㣬���½ڵ���뵽p_timer_chain_node_cur�ڵ�֮ǰ
        // ��������½ڵ��ڵ�һ���ڵ�֮ǰ��ʱ�򣬷��źţ��ж�timer�߳�sleep  
        if(nofind == 0)         // �ҵ�һ���ڵ㣬�½ڵ���뵽�ýڵ�֮ǰ
        {
            // �����½ڵ㵽��ǰ�ڵ�֮ǰ
            p_timer_chain_node_pre = p_timer_chain_node_cur->pre;   
            p_timer_chain_node_new->next = p_timer_chain_node_cur;
            p_timer_chain_node_cur->pre = p_timer_chain_node_new;
            p_timer_chain_node_pre->next = p_timer_chain_node_new;
            p_timer_chain_node_new->pre = p_timer_chain_node_pre;

            // ��ǰ�ڵ�Ϊ��һ���ڵ��ʱ�򣬷��ź�, ʹtimer���߳��ж�sleep
            timer_signal_timer_add(1);
            
        }
        else                    // û�ҵ��ڵ㣬��ǰ�ڵ��Ѿ����գ����½ڵ����p_timer_chain_node_pre֮��
        {
            p_timer_chain_node_new->next = NULL;
            p_timer_chain_node_pre->next = p_timer_chain_node_new;
            p_timer_chain_node_new->pre = p_timer_chain_node_pre;
            
        }
    }

    // ����ȴ���־
    timer_flag_wait_clear();  
    
    g_timer_manager_data.node_num++;
    //g_timer_manager_data.node_num = g_timer_manager_data.node_num % MAX_TIMER_NODE_NUM;

#ifdef debug_printf_timer
//    logger(TLOG_NOTICE, "�Ѿ�����һ���ڵ㣬��ǰ�ڵ�����=%d\n",g_timer_manager_data.node_num);
#endif
  
    return 0;
}

// ��timer����ɾ����һ���ڵ�
int timer_chain_node_delete()
{
    s_timer_chain_node *p_timer_chain_node_first;
    s_timer_chain_node *p_timer_chain_node_second;

    if(g_timer_chain_node_root.next == NULL)
    {
//        logger(TLOG_NOTICE, "timer����գ�����ɾ����һ���ڵ�\n");
#ifdef debug_printf_timer_queue
        vs_printf_timer_queue();
#endif
        return 1;
    }
    

    p_timer_chain_node_first = g_timer_chain_node_root.next;
#ifdef debug_printf_timer
logger(TLOG_NOTICE, "timer_chain_node_delete()����ɾ����һ���ڵ㣬�ڵ��=%d\n", p_timer_chain_node_first->timer_usr_data.tm_id);
#endif
    p_timer_chain_node_second = p_timer_chain_node_first->next;
    if(p_timer_chain_node_second == NULL)
    {
#ifdef debug_printf_timer
 //       logger(TLOG_NOTICE, "timer����ֻ��һ���ڵ�, ");
#endif
        g_timer_chain_node_root.next = NULL;
    }
    else
    {
        g_timer_chain_node_root.next = p_timer_chain_node_second;
        p_timer_chain_node_second->pre = &g_timer_chain_node_root;
    }

    free(p_timer_chain_node_first);

    // ���timer���գ����õȴ���־
    if(g_timer_chain_node_root.next == NULL)
        timer_flag_wait_set();
    
    g_timer_manager_data.node_num--;
    
#ifdef debug_printf_timer_queue
            vs_printf_timer_queue();
#endif

    return 0;
}

// ��õȴ����еĵ�һ���ڵ㣬���ڣ���ִ����Ӧ����,������ϣ��ӵȴ�������ɾ���˽ڵ㣬����0
//                           δ���ڣ��򷵻���Ҫ����Ҫ�ȴ�������,����ֵ>0
int timer_chain_node_handler()
{
    int ret;
    int timer_id;                                   // �˴ν��е���timer��������timer_id
    time_t time_wait;                                                   // ��timer�ĵȴ�����
    s_timer_chain_node *timer_chain_node_frist;
	s_timer_usr_data timer_usr_data;


    // timerʱ�䵽�����ǣ���ʱ��timer�Ѿ���ֱ�ӴӶ�����ɾ�����ˡ�
    // �����ʱ����Ϊ�գ���ֱ�����õȴ�ʱ��Ϊ1��
    // �����ʱ���в��գ��������һ���ڵ㡣��ʱ���ܷ�������������������һ���ڵ��ֱ�ӴӶ�����ɾ���Ľڵ�ĵ���ʱ���磬
    // Ҳ���ǣ��ڴ˿̣��µĽڵ�����Ѿ����ڣ���ֱ�Ӵ���
    // �ϸ�˵��������ȵ�һ���ڵ㵽��ʱ����Ľڵ��ʱ��Ӧ��ֹͣsleep,����������sleep��ʱ�䣬�����������
    if(g_timer_chain_node_root.next == NULL)
    {
        time_wait = 1;
        return time_wait;
    }
    
    // ��ȡ��һ���ڵ�ĵȴ�ʱ�� = ��һ���ڵ�ĵ���ʱ�� - ��ǰϵͳʱ��
    timer_get_frist_node_wt(&time_wait);
    
#ifdef debug_printf_timer
//    logger(TLOG_NOTICE, "��һ���ڵ�ĵȴ�ʱ��=%d\n", time_wait);
#endif

    // ����˽ڵ�δ���ڣ��򷵻ػ���ȴ�������
    if(time_wait > 0)
    {
        return time_wait;
    }

    timer_chain_node_frist = g_timer_chain_node_root.next;

    // �������timerΪ�ظ���timer,��Ҫ�����ظ���timer���뵽�ȴ�������
    if(timer_chain_node_frist->timer_usr_data.mode != 1)
    {
        
        // �����ظ��ͣ�����mode = 0 ; �����,����mode = mode -1;
        if(timer_chain_node_frist->timer_usr_data.mode == 0)
            timer_usr_data.mode = 0;
        else
            timer_usr_data.mode--;
        
        timer_usr_data.timer_handler = timer_chain_node_frist->timer_usr_data.timer_handler;
        timer_usr_data.timer_handler_data = timer_chain_node_frist->timer_usr_data.timer_handler_data;
        timer_usr_data.tm_first = timer_chain_node_frist->timer_usr_data.tm_first + timer_chain_node_frist->timer_usr_data.tm_intervel;
        timer_usr_data.tm_intervel = timer_chain_node_frist->timer_usr_data.tm_intervel;
        
        pthread_mutex_lock(&g_timer_manager_data.mutex_chain_opt);
        timer_chain_node_add(&timer_usr_data);
        pthread_mutex_unlock(&g_timer_manager_data.mutex_chain_opt);
    }
 
    // ִ�иýڵ�ĵ���ִ�к���, ִ�к������غ�ɾ���ýڵ�
//    pthread_mutex_lock(&g_timer_manager_data.mutex_chain_opt);            // ע�⣬���������л������Ϊtimerִ�к�����Ҳ���ô˺�����������������Ǿ�Ȼ�ܿ���Ƶ�����!
    timer_id = timer_chain_node_frist->timer_usr_data.tm_id;
#ifdef debug_printf_timer
    logger(TLOG_NOTICE, "ִ��timer���ڴ�������timer_id=%d\n",timer_chain_node_frist->timer_usr_data.tm_id);
#endif
    timer_chain_node_frist->timer_usr_data.timer_handler(timer_chain_node_frist->timer_usr_data.timer_handler_data);
    pthread_mutex_lock(&g_timer_manager_data.mutex_chain_opt);

    /************************************************************************
     *** ����ԭ������timer_chain_node_delete() �� ���ڵ���timer_chain_node_del_by_timerid()
     *** ��Ϊ����main_rountine�е����������У�������timer֮ǰ��ɾ����timer, ��Ϊ���ǵ����ʱ��timer���ܻ�û�е��ڣ�
               ����������ʱ���timer�����ˣ���ִ���괦�����󣬼���ɾ����ǰ��һ���ڵ������ظ�ɾ����
         �ʣ�Ŀǰ��Ϊɾ��ָ��timer_id�ŵĽڵ㡣

    **************************************************************************/
    //ret = timer_chain_node_delete();                                  
    ret = timer_chain_node_del_by_timerid(timer_id);

    pthread_mutex_unlock(&g_timer_manager_data.mutex_chain_opt);
        
    return 0;
}


// ��ʼ��timer�����������ڵ�
int vs_timer_chain_init()
{
    g_timer_chain_node_root.timer_usr_data.tm_first = 0;
    g_timer_chain_node_root.timer_usr_data.tm_intervel = 0;
    g_timer_chain_node_root.timer_usr_data.mode  = 0;
    g_timer_chain_node_root.timer_usr_data.timer_handler = NULL;
    g_timer_chain_node_root.pre = NULL;
    g_timer_chain_node_root.next = NULL;

    pthread_mutex_init(&g_timer_manager_data.mutex_chain_opt,NULL);
    pthread_mutex_init(&g_timer_manager_data.mutex_wait,NULL);   
	pthread_cond_init(&g_timer_manager_data.cond_wait,NULL);
	g_timer_manager_data.node_num = 0;
	g_timer_manager_data.timer_id = 0;
	timer_flag_wait_set();
    
    return 0;
} 

/*
// �����Ե�ǰʱ��Ϊ����1����timer,�˽ӿ�Ŀǰר�Ÿ�����ʹ��
int vs_timer_add(int second, int mode,int *timer_id ) 
{
    s_timer_usr_data timer_usr_data;
     
    timer_usr_data.mode = mode;
    timer_usr_data.timer_handler = rountin_sigroutine;
    timer_usr_data.timer_handler_data = NULL;
    timer_usr_data.tm_first = time(NULL) + second; 

    pthread_mutex_lock(&g_timer_manager_data.mutex_chain_opt);
    timer_chain_node_add(&timer_usr_data);
    pthread_mutex_unlock(&g_timer_manager_data.mutex_chain_opt);

    *timer_id = timer_usr_data.tm_id;

#ifdef debug_printf_timer
    logger(TLOG_NOTICE, "vs_timer_add()����һ��timer�ڵ�ɹ����ڵ��=%d\n", *timer_id);
#endif

#ifdef debug_printf_timer_queue
        vs_printf_timer_queue();                            // ��ӡtimer���нڵ��
#endif

    return 0;
}
*/

/****************************************************************************************************************
��    ��:�����뵱ǰʱ�����second�뵽�ڵ�timer

�������:  mode          : timer���ظ�������0: ������timer   1: ������timer����n:�ظ�n����timer
           second        : ��ǰʱ�����second����
           tm_intervel   : �ظ���timer�ļ��ʱ��
           timer_handler : timer��Ӧ�Ĵ�����
           handler_data  : timer��Ӧ�Ĵ���������������timer�в����������ݸ�timer��Ӧ�Ĵ�����
           
�������:  tm_id         : timer id�Ͷ����е�timerһһ��Ӧ�������ظ������ߡ������߽�����ʹ��id����ɾ����û���ڵ�timer

�� �� ֵ:
*****************************************************************************************************************/
int vs_timer_add2(int mode,time_t second, int tm_intervel, void *handler, void *handler_data,int *timer_id)
{

    s_timer_usr_data timer_usr_data;
     
    timer_usr_data.mode = mode;
    timer_usr_data.tm_first = time(NULL) + second;
    timer_usr_data.tm_intervel = tm_intervel;
    timer_usr_data.timer_handler = handler;
    timer_usr_data.timer_handler_data = handler_data;
    //timer_usr_data.timer_handler_data = NULL;

    pthread_mutex_lock(&g_timer_manager_data.mutex_chain_opt);
    timer_chain_node_add(&timer_usr_data);
    pthread_mutex_unlock(&g_timer_manager_data.mutex_chain_opt);
    
    *timer_id = timer_usr_data.tm_id;

#ifdef debug_printf_timer
    logger(TLOG_NOTICE, "vs_timer_add2()****����һ��timer�ڵ�ɹ����ڵ��=%d\n", *timer_id);
#endif

#ifdef debug_printf_timer_queue
    vs_printf_timer_queue();                            // ��ӡtimer���нڵ��
#endif

    return 0;
}

// ɾ��timer_id��Ӧ��timer
int vs_timer_del(int timer_id)
{
    int ret;

    pthread_mutex_lock(&g_timer_manager_data.mutex_chain_opt);
    ret = timer_chain_node_del_by_timerid(timer_id);
    pthread_mutex_unlock(&g_timer_manager_data.mutex_chain_opt);
    if(0 == ret)
    {
#ifdef debug_printf_timer
logger(TLOG_NOTICE, "vs_timer_del****����ɾ��һ��timer�ڵ�ʧ�ܣ�δ�ҵ�ƥ��ڵ㣬�ڵ��=%d\n ", timer_id);
#endif
      
#ifdef debug_printf_timer_queue
vs_printf_timer_queue();                            // ��ӡtimer���нڵ��
#endif
        return ret;        
    }

#ifdef debug_printf_timer
logger(TLOG_NOTICE, "vs_timer_del****����ɾ��һ��timer�ڵ�ɹ����ڵ��=%d\n", timer_id);
#endif
    
#ifdef debug_printf_timer_queue
vs_printf_timer_queue();                            // ��ӡtimer���нڵ��
#endif

    return ret;
}
    
int thread_timer_main()
{
   
    int ret;
	time_t time_wait;     
    time_wait = 0;
    
    while(!g_quit_timer)
    {
        // �ȴ�����timer������û�нڵ��ʱ�����õȴ���־��timer�����߳����������������в���ڵ��ʱ������ȴ���־
        pthread_mutex_lock(&g_timer_manager_data.mutex_wait);
        while(g_timer_manager_data.flag_wait)
            pthread_cond_wait(&g_timer_manager_data.cond_wait,&g_timer_manager_data.mutex_wait);
        pthread_mutex_unlock(&g_timer_manager_data.mutex_wait);

        // �ж�timer�����Ƿ�Ϊ�ա�ǰ�����������Ӧ��ʹ�ø�������ᷢ����
        if(g_timer_chain_node_root.next == NULL)
        {
            logger(TLOG_ERROR, "��������timer,timer����գ����ش���timer�������³�ʼ��!\n");
            vs_timer_chain_init();
            continue;        
        }

        while(!time_wait)
            time_wait = timer_chain_node_handler();
            
        // �ȴ���һ���ڵ㵽��
#ifdef debug_printf_timer
//        logger(TLOG_NOTICE, "timer�̵߳ȴ�%d����\n", time_wait);
#endif

        ret = sleep(time_wait);
        time_wait = 0;
        
#ifdef debug_printf_timer
        if(0 == ret)
        {
 //           logger(TLOG_NOTICE, "��һ��timer�ڵ㵽��\n");
        }
        else
        {
            logger(TLOG_NOTICE, "��һ��timer�ڵ�δ���ڣ��нڵ���뵽��һ���ڵ�ǰ�����յ�SIGALRM, sleep�жϣ�sleepʣ��ʱ��=%d\n",ret);
        }
#endif        

        
#if 0
        struct sigaction sysact;
        // ����timer
        sigemptyset(&sysact.sa_mask);
        sysact.sa_flags = SA_SIGINFO;
        sysact.sa_sigaction = timer_chain_node_frist->timer_usr_data->timer_handler;
        sigaction(SIGMYTIMER, &sysact, NULL);
        timer_id = SetTimer(time_wait*1000, 0);
#endif
        
    }
    
//    logger(TLOG_NOTICE, "�߳�thread_timer_main()�Ѿ��˳�\n");
    return 0;
}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

