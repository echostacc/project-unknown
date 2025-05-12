#ifndef ENGINE_H
#define ENGINE_H

#include <stdbool.h>
#include <SDL2/SDL.h>

typedef struct {
    bool running;
    SDL_Window* window;
    SDL_Renderer* renderer;
    int window_width;
    int window_height;
} Engine;

bool engine_initialize(Engine* engine, const char* title, int width, int height);
void engine_shutdown(Engine* engine);
bool engine_main_loop(Engine* engine);

#endif // ENGINE_H