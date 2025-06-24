#include <stdio.h>
#include <stdlib.h>
#include "../include/broker.h"

/*

typedef struct{
    Topic *topics;
    int topic_count;
} Broker;

typedef struct{
    char* messages[MAX_MESSAGES];
    int count;
} Partition;

typedef struct{
    char name[64];
    Partition partitions[MAX_PARTITIONS];
    int partition_count;
    int rr_index;
} Topic;

Broker* create_broker();
Topic* get_topic(Broker* broker, char* name);
void add_topic(Broker *broker, char* name, int partition_count);
*/

Broker* create_broker(){
    Broker* broker = malloc(sizeof(Broker));
    broker->topics = NULL;
    broker->topic_count =0;
    return broker;
}

Topic* get_topic(Broker* broker, char* name){
    for(int i=0; i<broker.topic_count; i++){
        if(strcmp(broker->topics[i].name, name) == 0){
            return &broker->topics[i];
        }
    }
    return NULL;
}

void add_topic(Broker* broker, char* name, int partition_count){
    broker->topics = realloc(broker->topics, sizeof(Topic) * (broker->topic_count +1));
    Topic *t = &broker->topics[broker->topic_count];
    strncpy(t->name, name, sizeof(t->name));
    t->partition_count = partition_count;
    for(int i =0; i<partition_count; i++){
        t->partitions[i].count =0;
    }

    broker->topic_count++;
}

