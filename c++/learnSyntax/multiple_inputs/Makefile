CC = g++
CFLAGS = -g -Wall
SRCS = takingmultipleinputs.cpp
PROG = takingmultipleinputs

OPENCV = `pkg-config opencv --cflags --libs`
LIBS = $(OPENCV)

$(PROG):$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)
