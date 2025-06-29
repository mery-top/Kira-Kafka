CC = gcc
SRC = main.c \
src/mapper.c

OUT = kafka_mmap

$(OUT): $(SRC)
	$(CC) $(SRC) -o $(OUT)

run:
	./$(OUT)
	
clean:
	rm -f $(OUT)