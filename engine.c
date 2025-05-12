#include "engine.h"
#include <stdio.h>

bool engine_initialize(Engine* engine, const char* title, int width, int height) {
    engine->running = true;
    engine->window = NULL;
    engine->renderer = NULL;
    engine->window_width = width;
    engine->window_height = height;
    
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    
    engine->window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        width, height,
        SDL_WINDOW_SHOWN
    );
    
    if (engine->window == NULL) {
        fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }
    
    engine->renderer = SDL_CreateRenderer(
        engine->window, 
        -1, 
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
    
    if (engine->renderer == NULL) {
        fprintf(stderr, "Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(engine->window);
        SDL_Quit();
        return false;
    }
    
    return true;
}

void engine_shutdown(Engine* engine) {
    if (engine->renderer) {
        SDL_DestroyRenderer(engine->renderer);
    }
    if (engine->window) {
        SDL_DestroyWindow(engine->window);
    }
    SDL_Quit();
}

bool engine_main_loop(Engine* engine) {
    SDL_Event event;
    
    while (engine->running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                engine->running = false;
            }
        }
        
        SDL_SetRenderDrawColor(engine->renderer, 0, 0, 0, 255);
        SDL_RenderClear(engine->renderer);
        
        // Scene rendering here...

        SDL_RenderPresent(engine->renderer);
    }
    
    return true;
}