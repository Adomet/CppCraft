#pragma once
#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "GameSettings.h"

class Application
{
public:
	void RunLoop();

	Application(const char* appName);
	~Application();

private:
	const char* m_AppName;
	GLFWwindow* m_Window;
	GameSettings m_GameSettings;

};

