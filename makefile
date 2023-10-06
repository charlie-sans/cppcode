# make file to make main.c++
# clang++ main.cpp -o main -lstdc++

# Path: makefile

all: main

main: main.cpp
	clang++ main.cpp -o main -lstdc++ `pkg-config gtkmm-4.0 --cflags --libs`

	./main
clean:
	rm -rf main
everything: main.cpp
	clang++ main.cpp -o main -lstdc++ 
	./main
