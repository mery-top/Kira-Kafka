#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "../include/consumer.h"

void* consume_messages(void *args){
    ConsumerArgs* cargs = (ConsumerArgs *)args;
    Broker* broker = cargs->broker;
    Topic* topic = get_topic(broker, cargs->topic_name);

    if(!topic){
        printf("Consumer %d Topic not found %s\n", cargs->thread_id, cargs->topic_name);
        return NULL;
    }

    Partition* p = &topic->partitions[cargs->partition_id];
    int last_read = 0;

    while(1){
        if(last_read < p->count){
            printf("Thread %d of Consumer Topic %s is reading [%s] from partition %d", 
            cargs->thread_id, cargs->topic_name, p->messages[last_read], cargs->partition_id);
            last_read++;
        }
        sleep(1);
    }
    return NULL;
}
