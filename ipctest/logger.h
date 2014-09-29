#ifndef __LOGGER_H__
#define __LOGGER_H__

#include "lists.h"
#include "debug.h"

#define TLOG_NOTICE 0
#define TLOG_WARNING 1
#define TLOG_DEBUG 2
#define TLOG_ERROR 3

#define DEFAULT_UDP_PORT  515
#define TIMESTAMP_LEN 50

#define MAX_LOG_LINE        512            // һ��д����־����󳤶�

//#define MAX_LOG_BUFFER   1024 * 16
#define MAX_LOG_BUFFER   1024 * 1024
#define MAX_PACKET_LEN	1024

#define RED      "\E[31m\E[1m"
#define GREEN    "\E[32m\E[1m"
#define YELLOW   "\E[33m\E[1m"
#define BLUE     "\E[34m\E[1m"
#define NORMAL   "\E[m"

#define LOGFILE_1        "./ipc_1.log"
#define LOGFILE_2        "./ipc_2.log"

struct logmsg {
    int level;
    char timestamp[TIMESTAMP_LEN];
    char buf[MAX_PACKET_LEN];
    TGAP_LIST_ENTRY(logmsg) list;
};

void logger(int level, const char *fmt, ...);
int init_udp_server(int *port);
void close_logger();
int open_loger(int port);
int logger_printf(char *buf, int buf_len);
int logger_size_get(char *logfile);



#endif

