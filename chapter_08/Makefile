SOURCE = $(wildcard *.c)
TARGETS = $(patsubst %.c, %, $(SOURCE))
 
CC = gcc
INC = ../include
CFLAGS = -Wall -g

all:$(TARGETS)

$(TARGETS):%:%.c
	$(CC) $< $(CFLAGS) -I$(INC) -o $@.out

.PHONY:clean all
clean:
	-rm -rf $(TARGETS).out