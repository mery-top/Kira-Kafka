#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "include/threadmap.h"

#define CORES 3

int main(){
    pthread_t threads[CORES];
    int core_id[CORES] = {0,1,2};

    pthread_create(&threads[0], NULL, network_io_thread, &core_id[0]);
    pthread_create(&threads[1], NULL, log_flush_thread, &core_id[1]);
    pthread_create(&threads[2], NULL, consumer_thread, &core_id[2]);

    for(int i=0; i< CORES; i++){
        pthread_join(threads[i], NULL);
    }

}