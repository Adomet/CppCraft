#pragma once

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "../World/Camera.h"
#include "../World/Entity.h"

class Camera;
class Entity;

glm::mat4 makeModelMatrix(const Entity& entity);
glm::mat4 makeViewMatrix(const Camera& camera);
glm::mat4 makeProjMatrix(float fov,float aspectRatio);





