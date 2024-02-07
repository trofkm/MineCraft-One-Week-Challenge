#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include "glm.h"

class Camera;

struct Entity;
struct Config;

glm::mat4 makeModelMatrix(const Entity &entity);
glm::mat4 makeViewMatrix(const Camera &camera);
/// @brief Make projection matrix
/// @param sizeX Size of the x axis
/// @param sizeY Size of the y axis
/// @param fov Field of view
/// @param zNear Near plane
/// @param zFar Far plane
/// @return Projection matrix
glm::mat4 makeProjectionMatrix(float sizeX, float sizeY, float fov, float zNear = 0.1f, float zFar = 2000.f);

#endif // MATRIX_H_INCLUDED
