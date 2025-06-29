#pragma once

#include <GLFW/glfw3.h>
#include <string>

namespace Engine{

    struct WindowConfig {
        int width = 800;
        int height = 600;
        std::string title = "Game App";

        bool decorated = true;
        bool resizable = true;
        bool maximized = true;
        bool fullscreen = true; // we'll use primary monitor if true
        int x_postion = 70;
        int y_postion = 80;
    };


    class Window {
    public:
        Window(const WindowConfig& config);
        ~Window();

        void pollEvents();
        void swapBuffers();
        bool shouldClose() const;
        void setIcon(const std::string& imagePath);

    private:
        GLFWwindow* window;
        GLFWmonitor* monitor;
        const GLFWvidmode* mode;

        WindowConfig config;

        void init();
        void setupCallbacks();

        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
        static void window_close_callback(GLFWwindow* window);
    };

}
