CC = gcc
SRC = main.c \
Kira-kafka/partitioning/include/broker.h \
Kira-kafka/partitioning/include/producer.h \
include/server.h

OUT = kafka_sim

$(OUT): $(SRC)
	$(CC) $(SRC) -o $(OUT)

run:
	./$(OUT)
	
clean:
	rm -f $(OUT)