CC = g++
CFLAGS = -g -Wall
SRCS = types.cpp
PROG = type_check

OPENCV = `pkg-config opencv --cflags --libs`
LIBS = $(OPENCV)

$(PROG):$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)
