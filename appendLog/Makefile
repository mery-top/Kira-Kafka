CC = gcc
SRC = main.c \
../partitioning/src/broker.c \
src/logger.c

OUT = kafka_appendLog

$(OUT): $(SRC)
	$(CC) $(SRC) -o $(OUT)

run:
	./$(OUT)
	
clean:
	rm -f $(OUT)