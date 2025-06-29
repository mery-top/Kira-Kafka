/*
--------------------------------------------------------------
Note:
CAN ONLY RUN ON LINUX
DIRECT THREAD TO CORE SCHEDULER IS NOT AVAILABLE ON MAC
--------------------------------------------------------------
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sched.h>
#include <stdlib.h>
#include <time.h>
#include "../include/threadmap.h"

void bind_thread_to_core(int core_id){
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(core_id, &cpuset);

    pthread_t current = pthread_self();
    if(pthread_setaffinity_np(current, sizeof(cpu_set_t), &cpuset)!=0){
        perror("setaffinity error");
    }else{
        prinf("Thread %lu bound to core %d", current, core_id);
    }
}

void* network_io_thread(void *args){
    int core_id = *((int*) args);
    bind_thread_to_core(core_id);

    while(1){
        printf("[Net I/O Thread] simulating async socket I/O")
        sleep(1);
    }

    return NULL;
}

