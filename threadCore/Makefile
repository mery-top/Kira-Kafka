CC = gcc
SRC = main.c \
src/threadmap.c

OUT = kafka_threadCore

$(OUT): $(SRC)
	$(CC) $(SRC) -o $(OUT)

run:
	./$(OUT)
	
clean:
	rm -f $(OUT)