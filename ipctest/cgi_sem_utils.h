#ifndef __CGI_UTILS_H__
#define __CGI_UTILS_H__

#include <sys/sem.h> 
#include <sys/ipc.h> 
#include "sem.h"
#include "logger.h"

//�����ź��� 
int sem_creat(key_t key) 
{ 
    union semun sem; 
    int semid; 
    sem.val = 0; 
    semid = semget(key,1,IPC_CREAT |0777); 

    if (-1 == semid){ 
        printf("create semaphore error\n"); 
        return -1; 
    } 
    semctl(semid,0,SETVAL,sem); 
    return semid; 
} 

//ɾ���ź��� 
void del_sem(int semid) 
{ 
	union semun sem; 
	sem.val = 0; 
	semctl(semid,0,IPC_RMID,sem); 
} 

//�����ź��� 
int new_sem(key_t key) 
{ 
	union semun sem; 
	int semid; 
	sem.val = 0; 
	semid = semget(key,0,0); 

	if (-1 == semid)
	{ 
		printf("create semaphore error\n"); 
		return-1; 
	} 

	return semid; 
} 


//p ����
int p(int semid) 
{ 
    struct sembuf sops={0, -1,0}; 
    return (semop(semid,&sops,1)); 
} 

//v ����
int v(int semid) 
{ 
    struct sembuf sops={0,1,0}; 
    return (semop(semid,&sops,1)); 
} 

//p ����
void wait_v(int semid) 
{ 
    struct sembuf sops={0,-1,0}; 
    semop(semid,&sops,1); 
} 

//v ����
void post_v(int semid) 
{ 
    struct sembuf sops={0,1,0}; 
    semop(semid,&sops,1); 
} 

#endif


