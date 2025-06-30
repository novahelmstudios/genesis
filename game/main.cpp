#include "engine.hpp"

int main(){
    Engine::EngineConfig cfg;
    cfg.title = "genesis";
    cfg.height = 1280;
    cfg.width = 720;
    cfg.bFullscreen = false;

    Engine::Engine::init(cfg);
    Engine::Engine::run();
    Engine::Engine::resign();

    return 0;
}


