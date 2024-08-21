#include "GodCam.h"

#include "Camera.h"
#include "CameraManager.h"
#include "GameObject.h"
#include "GodCamInput.h"
#include "GodCamUpdate.h"
#include "SceneManager.h"

GodCam::GodCam(Camera* const mCam)
{
	godCam = new Camera(Camera::Type::PERSPECTIVE_3D);
	up = new GodCamUpdate(godCam);
	go->AddUpdate("Cam Controls", up);
	in = new GodCamInput(this);
	go->AddInput(AZUL_KEY::KEY_F5, KeyboardManager::EventType::KeyPressed, in);
	go->EnableInput(AZUL_KEY::KEY_F5, KeyboardManager::EventType::KeyPressed);

	mainCam = mCam;
	inUse = false;
}

GodCam::~GodCam()
{
	delete godCam;
	delete up;
	delete in;
}

void GodCam::Toggle()
{
	if (inUse) ExitScene();
	else EnterScene();
}

void GodCam::EnterScene()
{
	go->SetCurrentUpdate("Cam Controls");
	SceneManager::GetCurrent()->SetCurrent3DCamera(godCam);
	inUse = true;
}

void GodCam::ExitScene()
{
	go->SetCurrentUpdate("Null");
	SceneManager::GetCurrent()->SetCurrent3DCamera(mainCam);
	inUse = false;
}
