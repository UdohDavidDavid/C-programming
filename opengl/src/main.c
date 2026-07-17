#include "../include/glad/glad.h" // Always import glad before glfw3
#include <GLFW/glfw3.h>
#include <stdio.h>

// Window size
#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 800

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);  // Like it says it processes the input
                                       
// Vertex input ///////////////////////////////////////////////////////////////
float vertices[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f,  0.5f, 0.0f
};

// Vertex shader code
const char *vertexShaderSource = "#version 460 core\n"
	"layout (location = 0) in vec3 aPos;\n"
	"void main()\n"
	"{\n"
	"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
	"}\0";

// Fragment shader code
const char *fragmentShaderSource = "#version 460 core\n"
	"out vec4 FragColor;\n"
	"void main()\n"
	"{\n"
	"    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
	"}\0";

void init_glfw() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

int window_initialized(GLFWwindow* window) {
    if (window == NULL) {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }
    return 0;
}

int glad_initialized() {
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialize GLAD\n");
        return -1;
    }
    return 0;
}

unsigned int create_vbo(float* vertices) {
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    return VBO;
}

// Driver code
int main(int argc, char **argv) {

	// Create the window here
	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (!window_initialized(window)) return -1;

	glfwMakeContextCurrent(window);
	glfwSwapInterval(0); // VSync

    if (!glad_initialized()) return -1;

	// Sets the opengl buffer thingy to match the window size
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

	// Checks if the window size has changed
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);



    unsigned int VBO = create_vbo(vertices);

	// VOA type shii
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);

	// ..:: Initialization code (done once (unless your object frequently changes)) :: ..
	// 1. bind Vertex Array Object
	glBindVertexArray(VAO);
	// 2. copy our vertices array in a buffer for OpenGL to use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 3. then set our vertex attributes pointers
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);



	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	// Check for errors
	int  success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if(!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		// std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		printf("ERROR::SHADER:VERTEX::COMPILATION_FAILED\n%s\n", infoLog);
	}

	// Fragment Input ////////////////////////////////////////////////////////////////


	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	// Check for errors
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if(!success) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		// std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n%s\n", infoLog);
	}

	// Shader Program ///////////////////////////////////////////////////////////////
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();

	// Link shader objects
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	// Delete shader objects after linking them
	// We no longer need them
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	// Checks for compilation errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if(!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		printf("ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n%s\n", infoLog);
	}

	// Activate shader program
	//glUseProgram(shaderProgram);



	// Render loop //////////////////////////////////////////////////////////////////
	while(!glfwWindowShouldClose(window)) {
		// input
		processInput(window);

		// rendering commands here
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// ..:: Drawing code (in render loop) :: ..
		// 4. draw the object
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);


		// check and call events and swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents(); // Checks if events are triggered
	}

	// End
	glfwTerminate();
	printf("I'm out\n");
	return 0;
}

// Resizes the opengl buffer thingy to match the window size
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
	printf("The size is changing now\n");
}

// Process input
void processInput(GLFWwindow *window) {
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, 1);
}
