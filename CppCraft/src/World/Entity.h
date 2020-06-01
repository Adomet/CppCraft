#pragma once
#include <glm.hpp>
class Entity
{
public:
	Entity();
	~Entity();

public:
	glm::vec3 position;
	glm::vec3 rotation;
};

