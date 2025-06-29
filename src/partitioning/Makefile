CC = gcc
SRC = main.c \
src/broker.c \
src/consumer.c \
src/producer.c 

OUT = kafka_sim

$(OUT): $(SRC)
	$(CC) $(SRC) -o $(OUT)

run:
	./$(OUT)
	
clean:
	rm -f $(OUT)