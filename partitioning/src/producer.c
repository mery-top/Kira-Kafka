#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/producer.h"

void produce_message(Broker* broker, char* topic_name, char* message){
    Topic *topic = get_topic(broker, topic_name);
    if (!topic) {
        printf("Topic %s not found.\n", topic_name);
        return;
    }

    int index = topic->rr_index % topic->partition_count;
    Partition *p = &topic->partitions[index];

    if(p->count < MAX_MESSAGES){
        p->messages[p->count++] = strdup(message);
        printf("Message %s sent to topic %s, partition %d\n", message, topic_name, index);
        topic->rr_index = (topic->rr_index +1) % (topic->partition_count);
    }else{
        printf("Partition %d of topic %s is full", index,topic_name);
    }
}