SOURCE = $(wildcard *.c)
TARGETS = $(patsubst %.c, %, $(SOURCE))
 
CC = gcc
INC = ../include
LIB = ../lib
CFLAGS = -Wall -g

all:$(TARGETS)

$(TARGETS):%:%.c
	$(CC) $< $(CFLAGS) -I$(INC) -L$(LIB) -l:libapue.a -o $@.out

.PHONY:clean all
clean:
	-rm -rf $(TARGETS).out