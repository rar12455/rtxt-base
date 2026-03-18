CXX = g++
CXXFLAGS = -std=c++23 -Wall -Wextra -O3 -march=native -flto=auto 
LIBS= -lreadline

all: rtxi

rtxi: main.o backend.o 
	$(CXX) $(CXXFLAGS) -o rtxi main.o backend.o $(LIBS)

main.o: main.cpp backend.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

backend.o: backend.cpp backend.hpp
	$(CXX) $(CXXFLAGS) -c backend.cpp

clean:
	rm -f rtxi *.o

run: rtxi
	./rtxi

.PHONY: all clean run
