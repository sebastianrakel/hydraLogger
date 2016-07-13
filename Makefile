CC=gcc
CFLAGS=-g -Wall

LIBS=-lpaho-mqtt3c -ljansson -lpq
OBJECTS=sensorMessage.o sqlLogger.o main.o

BIN=./bin

all: $(OBJECTS)
	$(CC) $(CFLAGS) $(LIBS) -o hydraLogger $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<


.PHONY: clean
clean:
	rm -rf hydraLogger $(OBJECTS)
