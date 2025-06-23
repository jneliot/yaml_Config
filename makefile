CXX := g++-14
CXXFLAGS := -Iinclude -std=c++11 -Wall -Wextra

all: RunStart

RunStart: RunStart.o
	$(CXX) $(CXXFLAGS) -o RunStart RunStart.o
	rm -f RunStart.o

RunStart.o: RunStart.cpp
	$(CXX) $(CXXFLAGS) -c RunStart.cpp -o RunStart.o

clean:
	rm -f RunStart

clear:
	rm -rf Run1750*/
