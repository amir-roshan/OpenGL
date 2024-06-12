#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>

// The framebuffer size callback function takes a GLFWwindow as its first argument and
// two integers indicating the new window dimensions. It updates the OpenGL viewport
// to the new window size.
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main()
{
    // Initialize the GLFW library
    if (!glfwInit())
    {
        std::cout << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Configure GLFW to use OpenGL version 3.3 and the core profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a windowed mode window and its OpenGL context
    // The glfwCreateWindow function requires the window width and height as its first two arguments respectively.
    // The third argument allows us to create a name for the window.
    // The first NULL is the monitor parameter (used for full screen mode, NULL for windowed mode).
    // The second NULL is the share parameter (used for sharing resources with another window, NULL for no sharing).
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Initialize GLAD to manage OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Set the viewport to cover the new window
    // The first two parameters of glViewport set the location of the lower-left corner of the window.
    // The third and fourth parameter set the width and height of the rendering window in pixels.
    glViewport(0, 0, 800, 600);

    // Register the framebuffer size callback to adjust the viewport when the window is resized
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Main loop: continues until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        // Render here: clear the color buffer
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events (e.g., keyboard and mouse input)
        glfwPollEvents();
    }

    // Terminate GLFW and clean up resources
    glfwTerminate();
    return 0;
}
