#ifndef __DEBUG_H__
#define __DEBUG_H__

#include "stdio.h"
#include "trace.h"
#include <arpa/inet.h>
#include "global.h"

#include "pthread.h"
extern pthread_mutex_t thread_print_lock;
// Debug Message -- format:
// [File:Line:Func]():Msg
// if(0/1) Toggle
#define _debug_(...) \
  do {                 \
    if(1){           \
      pthread_mutex_lock(&thread_print_lock); \
      long time_time_print_debug=get_current_time();\
      fprintf(stderr, "(DEBUG) [%ld] [%-20s: %-4d: %-22s] \t", time_time_print_debug, __FILE__, \
                __LINE__, __func__); \
      fprintf(stderr, __VA_ARGS__);             \
    pthread_mutex_unlock(&thread_print_lock);}\
  } while (0)


#define _trace_(...) \
  do {                 \
    if(1){           \
      pthread_mutex_lock(&thread_print_lock); \
      long time_time_print_debug=get_current_time();\
      fprintf(stderr, "(TRACE) [%ld] [%-20s: %-4d: %-22s] \t", time_time_print_debug, __FILE__, \
                __LINE__, __func__); \
      fprintf(stderr, __VA_ARGS__);             \
    pthread_mutex_unlock(&thread_print_lock);}\
  } while (0)

#define _ip_port_(tju_addr) \
  do{ \
  uint32_t ip = tju_addr.ip; \
  uint32_t s1 = (ip & 0xFF000000) >> 24; \
  uint32_t s2 = (ip & 0x00FF0000) >> 16; \
  uint32_t s3 = (ip & 0x0000FF00) >> 8; \
  uint32_t s4 = (ip & 0x000000FF) >> 0; \
  ip = s1 | (s2<<8) | (s3<<16) | (s4<<24); \
  struct in_addr net; \
  net.s_addr = ip; \
  _debug_("addr %s:%d\n" ,inet_ntoa(net),tju_addr.port); \
}while(0)

#endif //__DEBUG_H__


