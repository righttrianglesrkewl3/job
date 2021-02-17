CC = g++
CFLAGS = -g -Wall
SRCS = frequency_of_characters_in_string.cpp
PROG = frequency_of_characters_in_string

OPENCV = `pkg-config opencv --cflags --libs`
LIBS = $(OPENCV)

$(PROG):$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)
