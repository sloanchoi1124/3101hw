all: part1

part1: main.o part1.o
	g++ -std=c++11 -o part1 main.o part1.o

main.o: main.cpp part1.h
	g++ -std=c++11 -c main.cpp

part1.o: part1.cpp part1.h
	g++ -std=c++11 -c part1.cpp

clean:
	rm -f *.opp *.o part1

run:
	./part1

.PHONY: clean run help
