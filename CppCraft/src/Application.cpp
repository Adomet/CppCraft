#include "Application.h"

void Application::RunLoop()
{


    if (m_Config.Vsyc)
        glfwSwapInterval(0);
   
    std::cout << glGetString(GL_VERSION) << std::endl;
    {
        GLfloat vertices[] = {
            -0.5f,-0.5f , 0.0f,0.0f,
             0.5f,-0.5f , 1.0f,0.0f,
             0.5f, 0.5f , 1.0f,1.0f,
            -0.5f, 0.5f , 1.0f,0.0f,

        };

        GLuint indices[] = {
        0,1,2,2,3,0
        };


        // Create Vertex Array Object
        VertexArray va;
        VertexBuffer vb(vertices, sizeof(vertices));
        VertexBufferLayout layout;
        layout.Push<float>(2);
        layout.Push<float>(2);
        va.AddBuffer(vb, layout);


        IndexBuffer ib(indices, sizeof(indices) / sizeof(unsigned int));



       
        glm::mat4 proj = glm::perspective(m_Config.fov, m_Config.getAspectRetio(), 0.001f, 1000.0f); // glm::mat4(1.0f);//m_Camera.getProjMatrix();
  
        glm::mat4 model = glm::mat4(1.0f);



        glm::mat4 MVP = glm::translate(proj, glm::vec3(0,0,-5));
        


        //m_Camera.getProjMatrix();
        //glm::mat4 view(1.0f);

       


        Shader shader("res/shaders/Basic.shader");
        shader.Bind();
        // shader.SetUniform4f("u_Color", 1.0f, 0.5f, 0.3f, 1.0f);

        shader.SetUniformMat4f("u_MVP", MVP);

        Texture texture("res/textures/grass.png");
        texture.Bind();

        shader.SetUniform1i("u_Texture", 0);

        Renderer renderer;

        glClearColor(0.3f, 0.77f, 1.0f, 0.0f);

        float r = 1.0f;
        float increament = 0.01f;

        auto currentTime = std::chrono::steady_clock::now();
        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(m_Window))
        {
            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);

            renderer.Draw(vb, ib, shader);

            auto elapsed = currentTime - std::chrono::steady_clock::now();

            float elapsed_f = elapsed.count();


            glm::mat4 MVP = glm::translate(proj, glm::vec3(0, 0,-2+std::sin(elapsed_f/2000000000)));

            shader.SetUniformMat4f("u_MVP", MVP);
            //shader.SetUniform4f("u_Color", r, 0.5f, 0.3f, 1.0f);


            if (r > 1.0f)
                increament = -0.01f;
            else if (r < 0.0f)
                increament = 0.01f;

            r += increament;

            glfwSwapBuffers(m_Window);
            glfwPollEvents();
        }
    }

    glfwTerminate();
}





void Application::Init()
{
    if (!glfwInit())
    {
        std::cout << "GLFWInit failed!!" << std::endl;
        getchar();
        return;
    }
    m_Window = CreateWindow(m_Config.WindowWidht, m_Config.WindowHeight,m_AppName);

    if (GLEW_OK != glewInit())
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        getchar();
        glfwTerminate;
        return;
    }

}

GLFWwindow* Application::CreateWindow(int Width, int Height, const char* Title)
{
    GLFWwindow* window = glfwCreateWindow(Width, Height, Title, NULL, NULL);
    //glfwSetWindowMonitor(window, NULL, 0, 0, m_GameSettings.m_WindowWidht, m_GameSettings.m_WindowHeight, 0);
    if (!window)
    {
        std::cout << "Failed to open GLFW window!!" << std::endl;
        getchar();
        glfwTerminate();
        return nullptr;
    }

    glfwMakeContextCurrent(window);

    return window;
}




Application::Application(const char* appName)
    :m_AppName(appName), m_Window(nullptr),m_Camera(m_Config)
{
    Init();
}

Application::~Application()
{
}