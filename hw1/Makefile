all: part3/part3 part2/part2 part1/part1

part3/part3: part3/main.o part3/part3.o part2/part2.o part1/part1.o
	g++ -std=c++11 -o part3/part3 part3/main.o part3/part3.o part2/part2.o part1/part1.o

part3/main.o: part3/main.cpp part3/part3.h part2/part2.h part2/part2.o part1/part1.h part1/part1.o
	g++ -std=c++11 -c part3/main.cpp -o part3/main.o

part3/part3.o: part3/part3.cpp part3/part3.h
	g++ -std=c++11 -c part3/part3.cpp -o part3/part3.o



part2/part2: part2/main.o part2/part2.o
	g++ -std=c++11 -o part2/part2 part2/main.o part2/part2.o
part2/main.o: part2/main.cpp part2/part2.h
	g++ -std=c++11 -c part2/main.cpp -o part2/main.o
part2/part2.o: part2/part2.cpp part2/part2.h
	g++ -std=c++11 -c part2/part2.cpp -o part2/part2.o

part1/part1: part1/main.o part1/part1.o
	g++ -std=c++11 -o part1/part1 part1/main.o part1/part1.o

part1/main.o: part1/main.cpp part1/part1.h
	g++ -std=c++11 -c part1/main.cpp -o part1/main.o

part1/part1.o: part1/part1.cpp part1/part1.h
	g++ -std=c++11 -c part1/part1.cpp -o part1/part1.o

clean:
	rm -f *.opp *.o part1/part1 part2/part2 part3/part3

run:
	./part1/part1

.PHONY: clean run help
