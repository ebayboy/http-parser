CC = g++
LD = g++

TARGET = test_url

INCLUDES := -I /usr/local/googletest/include/ -I /usr/local/glog/include/
LIB = 
CFLAGS := -c -g -O0 -std=c++17 -Wall
LDFLAGS := -lpthread 

SRC_C := $(wildcard *.c)
SRC_CPP := $(wildcard *.cc)

OBJS_C=$(SRC_C:.c=.o)
OBJS_CPP=$(SRC_CPP:.cc=.o)

#===========add other libs start
INCLUDES += -I /usr/local/http-parser/include
LDFLAGS += /usr/local/http-parser/lib/libhttp_parser.a
#===========add other libs end

#$(warning $(OBJS_C))

.PHONY:all clean

test_url : test_url.o
	$(LD) $^ -o $@ $(LDFLAGS) $(LIB) 

%.o:%.c
	$(CC) $(CFLAGS) $< $(INCLUDES) -o $@

%.o:%.cc
	$(CC) $(CFLAGS) $< $(INCLUDES) -o $@

clean:
	rm -rf $(TARGET) $(OBJS_C) $(OBJS_CPP)

