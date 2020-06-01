#pragma once

#include "../Config.h"
#include "Entity.h"
#include "../Math/Matrix.h"

class Camera : public Entity
{
public:
	     Camera(const Config& config);

    void Update();
	 
	const glm::mat4 getViewMatrix()const;
	const glm::mat4 getProjMatrix()const;
	const glm::mat4 getProjViewMatrix()const;

private:
	//const Entity* m_Entity;

	glm::mat4 m_projMatrix;
	glm::mat4 m_viewMatrix;
	glm::mat4 m_projViewMatrix;

};