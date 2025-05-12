build: 
	gcc -Wall -std=c99 main.c engine.c -I/opt/homebrew/include -L/opt/homebrew/lib -lSDL2 -o app

run:
	./app

clean:
	rm app