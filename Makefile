CXX = g++
CXXFLAGS = -std=c++11 -pedantic -pedantic-errors -Wnarrowing -Wsign-compare -Wall -Werror
HEADERS = headers/
SRC_FILES = src/*.cpp


run: main
	./main 

main: playfair.o src/main.cpp
	$(CXX) $(CXXFLAGS) -I $(HEADERS) playfair.o src/main.cpp -o main


playfair.o: src/playfair.cpp headers/playfair.h
	$(CXX) $(CXXFLAGS) -I $(HEADERS) -c src/playfair.cpp -o playfair.o

.PHONY: clean
clean: 
	rm -rf *.o main