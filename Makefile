all:
	g++ -o bin/main src/main.cpp include/Game/*.cpp
run:
	./bin/main
