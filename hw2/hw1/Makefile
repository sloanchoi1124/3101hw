
CXX := g++
CXXFLAGS := -Wall -g -Wno-c++11-extensions
# CXXFLAGS := -Wall -g -std=c++11

PART1SRC := part1/part1.cpp
PART1OBJ := part1.opp
PART1H := part1/part1.h

PART2SRC := part2/part2.cpp
PART2OBJ := part2.opp
PART2H := part2/part2.h

PART3SRC := part3/part3.cpp
PART3OBJ := part3.opp
PART3H := part3/part3.h


part1.opp: $(PART1H) $(PART1SRC)
	$(CXX) $(CXXFLAGS) -c $(PART1SRC) -o $(PART1OBJ)

part2.opp: $(PART1H) $(PART2H) $(PART2SRC)
	$(CXX) $(CXXFLAGS) -c $(PART2SRC) -I./part1 -o $(PART2OBJ)

part3.opp: $(PART1H) $(PART2H) $(PART3H) $(PART3SRC)
	$(CXX) $(CXXFLAGS) -c $(PART3SRC) -I./part1 -I./part2 -o $(PART3OBJ)

main1.opp: part1/main.cpp $(PART1H)
	$(CXX) $(CXXFLAGS) -c part1/main.cpp -I./part1 -o main1.opp

main2.opp: part2/main.cpp $(PART2H)
	$(CXX) $(CXXFLAGS) -c part2/main.cpp -I./part1 -I./part2 -o main2.opp

main3.opp: part3/main.cpp $(PART3H)
	$(CXX) $(CXXFLAGS) -c part3/main.cpp -I./part1 -I./part2 -I./part3 -o main3.opp

part1b: main1.opp $(PART1OBJ)
	$(CXX) -o $@ $(PART1OBJ) main1.opp 

part1: part1b
	./part1b

part2b: main2.opp $(PART1OBJ) $(PART2OBJ)
	$(CXX) -o $@ $(PART1OBJ) $(PART2OBJ) main2.opp 

part2: part2b
	./part2b

part3b: main3.opp $(PART1OBJ) $(PART2OBJ) $(PART3OBJ)
	$(CXX) -o $@ $(PART1OBJ) $(PART2OBJ) $(PART3OBJ) main3.opp 

part3: part3b
	./part3b

.DEFAULT_GOAL := all
all: part1b part2b part3b

clean:
	rm -rf ./*.opp part1b part2b part3b

.PHONY: clean all part1 part2 part3

