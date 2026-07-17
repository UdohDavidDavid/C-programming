#include "../include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <stdio.h>

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 800

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height);
  printf("Resized Window\n");
}

void processInput(GLFWwindow *window) {
  if(glfwGetKey(window, GLFW_KEY_ESCAPE) ==  GLFW_PRESS)
    glfwSetWindowShouldClose(window, 1);
}

int main(int argc, char **argv) {
  glfwInit();
  printf("Here\n");
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Create window
  GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "OpenGL Window", NULL, NULL);
  if (window == NULL) {
    printf("Failed to create GLFW window\n");
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    printf("Failed to initialize GLAD\n");
    return -1;
  }

  // Sets the opengl buffer to match the window size
  glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
  // Checks if the window size has changed
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


  // Create VBO
  unsigned int VBO;
  glGenBuffers(1, &VBO);

  unsigned int VBO2;
  glGenBuffers(1, &VBO2);

  printf("%d\n", VBO);
  printf("%d\n", VBO2);

  while(!glfwWindowShouldClose(window)) {
    processInput(window);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
