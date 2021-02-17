CC = g++
CFLAGS = -g -Wall
SRCS = string_to_int.cpp
PROG = string_to_int_conversion

OPENCV = `pkg-config opencv --cflags --libs`
LIBS = $(OPENCV)

$(PROG):$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)
