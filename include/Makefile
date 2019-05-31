CC       = gcc 
CFLAGS   = -Wall -g -O -fPIC
CXXFLAGS = 
INCLUDE  = -I .
TARGET   = libtoolkit.so
LIBPATH  = ../lib/

vpath %.h ./inc

OBJS     = toolkit.o
SRCS     = toolkit.c

all:$(OBJS)
	$(CC) -shared -fPIC -o $(TARGET) $(OBJS)
	mv $(TARGET) $(LIBPATH)
	rm $(OBJS)

$(OBJS):$(SRCS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $^

clean:
	rm -f *.o
	rm -f $(LIBPATH)/$(TARGET)