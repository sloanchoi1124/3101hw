all: part2

part2: main.o part2.o
	g++ -std=c++11 -o part2 main.o part2.o

main.o: main.cpp part2.h
	g++ -std=c++11 -c main.cpp

part2.o: part2.cpp part2.h
	g++ -std=c++11 -c part2.cpp

clean:
	rm -f *.opp *.o part2

run:
	./part2

.PHONY: clean run help
