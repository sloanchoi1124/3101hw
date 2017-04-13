CXX := g++
CXXFLAGS := -Wall -g -std=c++11

CXX_SOURCES2 += src/hw2.cpp
CXX_OBJECTS2 += $(CXX_SOURCES2:.cpp=.o)

LIBS := -L./hw1/include -lhw1
INCLUDES := -I./hw1/part1 -I./hw1/part2 -I./hw1/part3

TARGET2 := src/hw2

.DEFAULT_GOAL := all
all: $(TARGET2)

$(TARGET2): $(CXX_OBJECTS2) hw1
	$(CXX) -o $@ $(CXX_OBJECTS2) $(LIBS)

hw1:
	make -C hw1

.cpp.o: 
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f *.opp *.o $(TARGET2)
	make -C hw1 clean

run2: $(TARGET2)
	LD_LIBRARY_PATH=./hw1/include ./$(TARGET2)

.PHONY: clean run2 help hw1
