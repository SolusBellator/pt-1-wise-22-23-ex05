SHELL = /bin/bash
CC = gcc
TARGETS = grading_tasks dec2rom caesar teststack
CFLAGS = -Wall
LDLIBS = -lm

all: Makefile $(TARGETS)

clean: Makefile
	rm -f *.o $(TARGETS)
	clear

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

.INTERMEDIATE grading_tasks: grading_tasks.o grading_table.o

.INTERMEDIATE dec2rom: dec2rom.o

.INTERMEDIATE caesar: caesar.o

.INTERMEDIATE teststack: teststack.o i2stack.o

.PHONY: all clean
