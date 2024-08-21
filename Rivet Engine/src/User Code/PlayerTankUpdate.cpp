#include "PlayerTankUpdate.h"

#include "Keyboard.h"

#include "../Rivet Engine/DebugLog.h"

#include "PlayerTank.h"

PlayerTankUpdate::PlayerTankUpdate(PlayerTank* t) :
	TankUpdate(t), pTank(t) {}

void PlayerTankUpdate::SetTerrainPos(const Vect& p)
{
	terrainPos = p;
}

const Vect& PlayerTankUpdate::GetCamPos()
{
	return camPos;
}

void PlayerTankUpdate::Move()
{
	// Adjust tank world matrix
	int ccw = Keyboard::GetKeyState(AZUL_KEY::KEY_A);
	int cw = Keyboard::GetKeyState(AZUL_KEY::KEY_D);
	mBody = Matrix(ROT_Y, (ccw - cw) * rotAng) * mBody;

	int fwd = Keyboard::GetKeyState(AZUL_KEY::KEY_W);
	int bwd = Keyboard::GetKeyState(AZUL_KEY::KEY_S);
	mBody = Matrix(TRANS, 0, 0, (fwd - bwd) * speed) * mBody;

	int ccw2 = Keyboard::GetKeyState(AZUL_KEY::KEY_Z);
	int cw2 = Keyboard::GetKeyState(AZUL_KEY::KEY_C);
	mCannon = Matrix(ROT_Y, (ccw2 - cw2) * rotAng) * mCannon;
}

void PlayerTankUpdate::ShowDebug()
{
	Vect pos = mBody.get(ROW_3);
	DebugLog::Clear();
	DebugLog::Add("Tank: ");
	DebugLog::Add("\tPos: %.1f, %.1f, %.1f", pos.X(), pos.Y(), pos.Z());
	DebugLog::Add("\tPos On Terrain: %.1f, %.1f, %.1f", terrainPos.X(),
		terrainPos.Y(), terrainPos.Z());
	DebugLog::Add("\tCam Pos: %.1f, %.1f, %.1f", camPos.X(), camPos.Y(),
		camPos.Z());
	DebugLog::Add("\tDist to Origin: %.1f", pos.mag());
}

void PlayerTankUpdate::UpdateCamera()
{
	Vect newCamPos = camTarget * mCam;	// This moves the cam position relative to tank's position and rotation
	Vect newLookAt = camOffset * mCam; // This moves the look-at point relative to tank's position and rotation
	camPos = pTank->UpdateCamera(newCamPos, newLookAt);
}
