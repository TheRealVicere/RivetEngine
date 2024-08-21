#include "CameraManager.h"

#include "Camera.h"
#include "Rivet.h"

CameraManager::CameraManager()
{
	// Set Up 3D Camera
	default3DCam = new Camera(Camera::Type::PERSPECTIVE_3D);
	default3DCam->setViewport(0, 0, Rivet::GetWidth(), Rivet::GetHeight());
	default3DCam->setPerspective(35.0f, float(Rivet::GetWidth()) / 
		float(Rivet::GetHeight()), 1.0f, 5000.0f);

	// Orient 3D Camera
	Vect up3DCam(0.0f, 1.0f, 0.0f);
	Vect pos3DCam(50.0f, 50.0f, 150.0f);
	Vect lookAt3DCam(0.0f, 0.0f, 0.0f);
	default3DCam->setOrientAndPosition(up3DCam, lookAt3DCam, pos3DCam);
	default3DCam->updateCamera();  // Note: if the camera moves/changes, we need to call update again

	// Set Up 2D Camera
	default2DCam = new Camera(Camera::Type::ORTHOGRAPHIC_2D);
	default2DCam->setViewport(0, 0, Rivet::GetWidth(), Rivet::GetHeight());
	default2DCam->setOrthographic(-0.5f * Rivet::GetWidth(), 0.5f * Rivet::GetWidth(),
		-0.5f * Rivet::GetHeight(), 0.5f * Rivet::GetHeight(), 1.0f, 1000.0f);

	// Orient 2D Camera
	Vect up2DCam(0.0f, 1.0f, 0.0f);
	Vect pos2DCam(0.0f, 0.0f, 0.0f);
	Vect lookAt2DCam(0.0f, 0.0f, -1.0f);
	default2DCam->setOrientAndPosition(up2DCam, lookAt2DCam, pos2DCam);
	default2DCam->updateCamera();

	current3DCam = default3DCam;
	current2DCam = default2DCam;
}

CameraManager::~CameraManager()
{
	delete default3DCam;
	delete default2DCam;
}

void CameraManager::SetCurrent3D(Camera* camera)
{
	assert(camera->getType() == Camera::Type::PERSPECTIVE_3D);
	current3DCam = camera;
}

Camera* CameraManager::GetCurrent3D()
{
	return current3DCam;
}

void CameraManager::SetCurrent2D(Camera* camera)
{
	assert(camera->getType() == Camera::Type::ORTHOGRAPHIC_2D);
	current2DCam = camera;
}

Camera* CameraManager::GetCurrent2D()
{
	return current2DCam;
}
