CC = g++
CFLAGS = -g -Wall
SRCS = usingcin.cpp
PROG = usingcin

OPENCV = `pkg-config opencv --cflags --libs`
LIBS = $(OPENCV)

$(PROG):$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)
