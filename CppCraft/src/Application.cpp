#include "Application.h"

void Application::RunLoop()
{
    if (!glfwInit())
    {
        std::cout << "GLFWInit failed!!" << std::endl;
        getchar();
        return;
    }
    GLFWwindow* window;
    window = glfwCreateWindow(m_GameSettings.m_WindowWidht, m_GameSettings.m_WindowHeight, m_AppName, NULL, NULL);
    //glfwSetWindowMonitor(window, NULL, 0, 0, m_GameSettings.m_WindowWidht, m_GameSettings.m_WindowHeight, 0);
    if (!window)
    {
        std::cout << "Failed to open GLFW window!!" << std::endl;
        getchar();
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

    if (GLEW_OK != glewInit())
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        getchar();
        glfwTerminate;
        return;
    }

    std::cout << glGetString(GL_VERSION) << std::endl;


    glClearColor(0.3f, 0.77f, 1.0f, 0.0f);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}




Application::Application(const char* appName)
    :m_AppName(appName), m_Window(nullptr),m_GameSettings(1920/2,1080/2,true)
{
    
}

Application::~Application()
{
}