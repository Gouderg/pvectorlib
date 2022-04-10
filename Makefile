CC = g++
CFLAGS = -W -Wall -g
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = $(wildcard src/*.cpp)
OBJS = $(SRC:.cpp=.o)
HEADER = $(SRC:.cpp=.hpp)
 
all : pvector clean

pvector : $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o : %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm src/*.o