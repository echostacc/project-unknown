build: 
	gcc -Wall -std=c99 main.c src/engine.c -I./src -I/opt/homebrew/include -L/opt/homebrew/lib -lSDL2 -o app

run:
	./app

clean:
	rm app