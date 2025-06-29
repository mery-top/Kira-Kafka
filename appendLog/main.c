#include <stdio.h>
#include "../partitioning/include/broker.h"
#include "include/logger.h"

int main(){
    Broker* broker = create_broker();
    add_topic(broker, "orders",1);

    Topic *topic = get_topic(broker, "orders");
    Partition *p0 = &topic->partitions[0];

    append_message_to_log(p0, "Order#1001 - product X");
    append_message_to_log(p0, "Order#1002 - product Y");
    append_message_to_log(p0, "Order#1003 - product Z");

    printf("Message written to disk based kafka log.\n");

    return 0;

}