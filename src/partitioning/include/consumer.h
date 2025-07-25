#pragma once
#include "broker.h"

typedef struct{
    Broker* broker;
    char* topic_name;
    int partition_id;
    int thread_id;
}ConsumerArgs;

void* consume_messages(void *args);