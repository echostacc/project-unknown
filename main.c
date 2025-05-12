#include "engine.h"

int main(int argc, char* argv[]) {
    Engine engine;
    
    if (!engine_initialize(&engine, "Application", 800, 600)) {
        return 1;
    }
    
    engine_main_loop(&engine);
    
    engine_shutdown(&engine);
    
    return 0;
}