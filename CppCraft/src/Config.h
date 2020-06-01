#pragma once
#include "GLFW/glfw3.h"
struct Config
{
public:
	int  WindowWidht = 1920 / 2;
	int  WindowHeight = 1080 / 2;
	bool Vsyc = true;
	float  fov = 90;
public:
	float getAspectRetio()
	{
		return (float)WindowWidht / (float)WindowHeight;
	}
};