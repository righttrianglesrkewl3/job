CC = g++
CFLAGS = -g -Wall
SRCS = geeks_frequency.cpp
PROG = geeks_frequency

OPENCV = `pkg-config opencv --cflags --libs`
LIBS = $(OPENCV)

$(PROG):$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)
