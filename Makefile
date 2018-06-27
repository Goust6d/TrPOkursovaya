CXX=gcc
CFLAGS =  -c -Wall -Werror -std=c99
FLAGS  =  -Wall -Werror -std=c99
OBJECTS = build/main.o build/Bender.o build/Numgeneration.o
OB = build/main_test.o build/Bender.o build/Numgeneration.o

.PHONY: clean all bin build bin/game bin/game_test default test

all: bin build bin/game bin/game_test default test

default: bin/game/prog

test: bin/game_test/prog_test
	bin/game_test/prog_test

bin/game/prog: $(OBJECTS) 
	$(CXX) $(FLAGS) $(OBJECTS) -o bin/game/prog

build/main.o: src/main.c src/func.h
	$(CXX) $(CFLAGS) src/main.c -o build/main.o

build/Bender.o: src/Bender.c src/func.h
	$(CXX) $(CFLAGS) src/Bender.c -o build/Bender.o

build/Numgeneration.o: src/Numgeneration.c src/func.h
	$(CXX) $(CFLAGS) src/Numgeneration.c -o build/Numgeneration.o


bin/game_test/prog_test: $(OB)
	$(CXX) $(FLAGS) $(OB) -o bin/game_test/prog_test

build/main_test.o: Test/main_test.c src/func.h thirdparty/ctest.h
	$(CXX) $(CFLAGS) -I thirdparty -I src -c Test/main_test.c -o build/main_test.o

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
