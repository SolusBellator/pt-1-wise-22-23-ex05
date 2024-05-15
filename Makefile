SHELL = /bin/bash
CC = gcc
TARGETS = grading_tasks dec2rom caesar teststack
CFLAGS = -Wall -O3
LDLIBS = -lm

all: Makefile $(TARGETS)

clean: Makefile
	rm -f *.o $(TARGETS)
	clear

$(foreach D,.,$(wildcard grading*.c)): grading_table.h

grading_tasks: $(patsubst .c,.o,$(foreach D,.,$(wildcard grading*.c)))

dec2rom: $(patsubst .c,.o,$*)

caesar: $(patsubst .c,.o,$*)

$(foreach D,.,$(wildcard *stack*.c)): istack.h

teststack: $(patsubst .c,.o,$(foreach D,.,$(wildcard *stack*.c)))

.PHONY: all clean
