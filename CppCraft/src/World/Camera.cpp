#include "Camera.h"

Camera::Camera(const Config& config)
{
	m_projMatrix = makeProjMatrix(config.fov,(float)config.WindowWidht/(float)config.WindowHeight);

	position = { 0, 0, 0};

	m_viewMatrix = makeViewMatrix(*this);
	m_projViewMatrix = m_projMatrix * m_viewMatrix;
}

void Camera::Update()
{

	m_viewMatrix = makeViewMatrix(*this);

	m_projViewMatrix = m_projMatrix * m_viewMatrix;
}

const glm::mat4 Camera::getViewMatrix() const
{
	return m_viewMatrix;
}

const glm::mat4 Camera::getProjMatrix() const
{
	return m_projMatrix;
}

const glm::mat4 Camera::getProjViewMatrix() const
{
	return m_projViewMatrix;
}
