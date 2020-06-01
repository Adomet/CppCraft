#pragma once
#include <iostream>
#include <chrono>
#include <cmath>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Config.h"
#include "Render/Renderer.h"
#include "Render/VertexBuffer.h"
#include "Render/IndexBuffer.h"
#include "Render/Shader.h"
#include "Render/VertexArray.h"
#include "Render/Texture.h"
#include "World/Camera.h"


#include <glm.hpp>
#include <gtc/matrix_transform.hpp> 

class Application
{
public:
	void RunLoop();
	void Init();
	GLFWwindow* CreateWindow(int Width,int Height,const char* Title);
	Application(const char* appName);
	~Application();

private:
	const char* m_AppName;
	GLFWwindow* m_Window;
	Config m_Config;
	Camera m_Camera;


};

