CC=gcc
DEBUGGER=gdb
BIN=main
FLAGS=-Wall -Wextra -g -pthread

main: main.o quick.o merge.o utils.o
	$(CC) $(FLAGS) -o $(BIN) main.c quick.c merge.c utils.c

main.o: main.c
	$(CC) -c main.c

quick.o: quick.c quick.h
	$(CC) -c quick.c

merge.o: merge.c merge.h
	$(CC) -c merge.c

utils.o: utils.c utils.h
	$(CC) -c merge.c	

run: $(BIN)
	./$(BIN)

debug: $(BIN)
	$(DEBUGGER) $(BIN)

clean:
	rm *.o
	rm $(BIN)
