#include "engine.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    Engine* engine = create_engine();
    if (!engine) {
        fprintf(stderr, "Failed to allocate memory for engine\n");
        return 1;
    }
    
    if (engine->initialize(engine, "Application", 800, 600)) {
        engine->loop(engine);
        engine->shutdown(engine);
    } else {
        fprintf(stderr, "Failed to initialize the engine.\n");
    }
    
    free(engine);
    return 0;
}