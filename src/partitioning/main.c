#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/broker.h"
#include "include/consumer.h"
#include "include/producer.h"

#define NUM_THREADS 4

int main(){
    Broker *broker = create_broker();
    add_topic(broker, "orders",2);
    add_topic(broker, "logs",2);

    produce_message(broker, "orders", "Order1");
    produce_message(broker, "logs", "Login");
    produce_message(broker, "orders", "Order2");
    produce_message(broker, "logs", "SignUp");
    produce_message(broker, "orders", "Order3");
    produce_message(broker, "logs", "Logout");


    pthread_t threads[NUM_THREADS];
    ConsumerArgs args[NUM_THREADS];

    for(int i=0; i<NUM_THREADS;i++){
        args[i].broker = broker;
        args[i].topic_name= (i < 2) ? "orders" : "logs";
        args[i].partition_id = i%2;
        args[i].thread_id = i;

        pthread_create(&threads[i], NULL, consume_messages, &args[i]);
    }

    for(int i=0; i<NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }

    return 0;
}
