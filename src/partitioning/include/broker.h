#pragma once
#include "topic.h"

typedef struct{
    Topic *topics;
    int topic_count;
} Broker;

Broker* create_broker();
Topic* get_topic(Broker* broker, char* name);
void add_topic(Broker *broker, char* name, int partition_count);