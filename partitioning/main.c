#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/broker.h"
#include "../include/consumer.h"
#include "../include/producer.h"

int main(){
    Broker *broker = create_broker();
    add_topic(broker, "orders",2);
    add_topic(broker, "logs",2);
}
