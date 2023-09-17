.POSIX:
CC := cc
CFLAGS := -Wall -Wextra -std=c11 -pedantic
CFLAGS += -g3 -DDEBUG
LIBS := -fsanitize=address

SRC := ../src

.PHONY: all
all: run

main.out: main.o fact.o ann.o
	$(CC) $(LIBS) -o $@ $^

main.o: $(SRC)/main.c $(SRC)/ann.h
	$(CC) $(CFLAGS) -c $<

fact.o: $(SRC)/fact.c $(SRC)/fact.h
	$(CC) $(CFLAGS) -c $<

ann.o: $(SRC)/ann.c $(SRC)/ann.h
	$(CC) $(CFLAGS) -c $<

.PHONY: run
run: main.out
	./main.out

.PHONY: clean
clean:
	rm *.o *.out
