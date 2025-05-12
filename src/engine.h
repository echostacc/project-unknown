#ifndef ENGINE_H
#define ENGINE_H

#include <stdbool.h>
#include <SDL2/SDL.h>

typedef struct Engine Engine;

struct Engine {
    bool running;
    SDL_Window* window;
    SDL_Renderer* renderer;
    int window_width;
    int window_height;

    bool (*initialize)(Engine* engine, const char* title, int width, int height);
    void (*shutdown)(Engine* engine);
    bool (*loop)(Engine* engine);
};

bool initialize(Engine* engine, const char* title, int width, int height);
void shutdown(Engine* engine);
bool loop(Engine* engine);
Engine* create_engine();

#endif // ENGINE_H