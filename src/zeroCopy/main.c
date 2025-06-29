#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../partitioning/include/broker.h"
#include "../partitioning/include/producer.h"
#include "include/server.h"

int main(){
    Broker *broker = create_broker();
    add_topic(broker, "orders",2);

    produce_message(broker, "orders", "Order#101");
    produce_message(broker, "orders", "Order#102");
    produce_message(broker, "orders", "Order#103");

    FILE *fp = fopen("orders-part0.log", "w");
    if (fp){
        fprintf(fp, "Order#101\n");
        fprintf(fp, "Order#102\n");
        fprintf(fp, "Order#103\n");
        fclose(fp);
    }

    start_server("orders-part0.log", 8080); 
}