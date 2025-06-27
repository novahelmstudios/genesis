
#include "Window.h"
#include "WindowConfig.h"
#include <GL/gl.h> 

int main() {
    Engine::WindowConfig config;
    config.fullscreen = false; // make it true for windowless fullscreen
    config.maximized = true; // makes it windowed fullscreen
    config.resizable = true; // 
    //config.x_postion = 100;  // optional 
    //config.y_postion = 80;
    config.title = "Game App";

    Engine::Window myWindow(config);
    myWindow.setIcon("../../assets/icons/icon.png");
    while (!myWindow.shouldClose()) {
        glClearColor(0.1f, 0.1f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        myWindow.swapBuffers();
        myWindow.pollEvents();
    }

    return 0;
}
