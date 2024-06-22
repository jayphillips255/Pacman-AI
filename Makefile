all:
	g++ -I include -L lib -o bin/main src/main.cpp include/Game/*.cpp -g -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
run:
	./bin/main
