PATH_SRC = src/
PATH_BUILD_SRC = build/

all: build build/src pr

pr: $(PATH_BUILD_SRC)main.o $(PATH_BUILD_SRC)Lab3.o
	g++ $(PATH_BUILD_SRC)main.o $(PATH_BUILD_SRC)Lab3.o -o pr

$(PATH_BUILD_SRC)main.o: $(PATH_SRC)main.cpp
	g++ -Wall -c $(PATH_SRC)main.cpp -o $(PATH_BUILD_SRC)main.o

$(PATH_BUILD_SRC)Lab3.o: $(PATH_SRC)Lab3.cpp
	g++ -Wall -c $(PATH_SRC)Lab3.cpp -o $(PATH_BUILD_SRC)Lab3.o

build:
	mkdir build

build/src:
	mkdir build/src

clean:
	rm -rf build/*.o

.PHONY: clean
