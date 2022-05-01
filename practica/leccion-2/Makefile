CC = g++
CFLAGS = -Wall
RM = rm -f
SRCS = $(wildcard *.cpp)
PROGS = $(patsubst %.cpp,%.out,$(SRCS))

.PHONY: all clean

all: $(PROGS)

%.out: %.cpp
		$(CC) $(CFLAGS) -g3 -o3 -o $@ $<

clean:
		$(RM) $(PROGS)
