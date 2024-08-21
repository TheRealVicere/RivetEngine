#include "GodCamUpdate.h"

#include "Camera.h"
#include "Keyboard.h"
#include "Rivet.h"

GodCamUpdate::GodCamUpdate(Camera* c) :
	godCam(c), rot(IDENTITY), pos(0, 20, 0)
{
	godCam->setViewport(0, 0, Rivet::GetWidth(), Rivet::GetHeight());
	godCam->setPerspective(35.0f, float(Rivet::GetWidth()) /
		float(Rivet::GetHeight()), 1.0f, 5000.0f);
}

void GodCamUpdate::Update()
{
	// Translation
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_I))
		pos += Vect(0, 0, 1) * rot * speed;
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_K))
		pos += Vect(0, 0, 1) * rot * -speed;

	if (Keyboard::GetKeyState(AZUL_KEY::KEY_J))
		pos += Vect(1, 0, 0) * rot * speed;
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_L))
		pos += Vect(1, 0, 0) * rot * -speed;

	// Rotation
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_LEFT))
		rot *= Matrix(ROT_Y, rotAng);
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_RIGHT))
		rot *= Matrix(ROT_Y, -rotAng);

	if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_UP))
		rot *= Matrix(ROT_AXIS_ANGLE, Vect(1, 0, 0) * rot, -rotAng);
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_DOWN))
		rot *= Matrix(ROT_AXIS_ANGLE, Vect(1, 0, 0) * rot, rotAng);

	// Update
	godCam->setOrientAndPosition(up * rot, pos + dir * rot, pos);
	godCam->updateCamera();
}
