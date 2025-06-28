CC = gcc
SRC = main.c \
../partitioning/src/broker.c \
../partitioning/src/producer.c \
src/server.c

OUT = kafka_sim

$(OUT): $(SRC)
	$(CC) $(SRC) -o $(OUT)

run:
	./$(OUT)
	
clean:
	rm -f $(OUT)