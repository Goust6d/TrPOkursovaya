CXX=gcc
CFLAGS = -c -Wall -Werror
FLAGS = -Wall -Werror
OBJECTS = build/main.o
OB = build/main_test.o

.PHONY: clean all bin build bin/game default test

all: bin build bin/game default test

default: bin/game


bin/game: $(OBJECTS)
	$(CXX) $(FLAGS) $(OBJECTS) -o bin/game

build/main.o: src/main.cpp
	$(CXX) $(CFLAGS) src/main.cpp -o build/main.o


build:
	mkdir build
bin:
	mkdir bin
bin/game:
	mkdir bin/game
bin/game_test:
	mkdir bin/game_test

clean:
	-rm -rf build bin
