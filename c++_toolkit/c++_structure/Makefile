CC = g++
CFLAGS = -g -Wall
SRCS = cplusplus_structure.cpp
PROG = cplusplus_structure

OPENCV = `pkg-config opencv --cflags --libs`
LIBS = $(OPENCV)

$(PROG):$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)
