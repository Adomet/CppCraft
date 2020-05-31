#pragma once
#include "GLFW/glfw3.h"
class GameSettings
{
public:
	GameSettings(int WindowWidth,int WindowHeigth,bool Vsyc);
	~GameSettings();

public:
	int m_WindowWidht;
	int m_WindowHeight;
	bool m_Vsyc;
};

