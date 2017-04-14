CXX := g++
CXXFLAGS := -Wall -g -std=c++11

CXX_SOURCES2 += src/hw2.cpp
CXX_OBJECTS2 += $(CXX_SOURCES2:.cpp=.o)

CXX_SOURCES1 += main.cpp
CXX_OBJECTS1 += $(CXX_SOURCES1:.cpp=.o)

LIBS := -L./hw1/include -lhw1
INCLUDES := -I./hw1/part1 -I./hw1/part2 -I./hw1/part3 -I./src

TARGET2 := src/hw2
TARGET1 := main

.DEFAULT_GOAL := all
all: $(TARGET1)

$(TARGET1): $(CXX_OBJECTS2) $(CXX_OBJECTS1) hw1
	$(CXX) -o $@ $(CXX_OBJECTS2) $(CXX_OBJECTS1) $(LIBS)

hw1:
	make -C hw1

.cpp.o: 
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f *.opp *.o $(TARGET1) src/*.opp src/*.o
	make -C hw1 clean

run1: $(TARGET1)
	LD_LIBRARY_PATH=./hw1/include ./$(TARGET1)

.PHONY: clean run1 help hw1
