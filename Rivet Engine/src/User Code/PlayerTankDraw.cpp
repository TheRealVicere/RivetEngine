#include "PlayerTankDraw.h"

#include "Camera.h"
#include "GraphicsObject_TextureLight.h"
#include "Texture.h"

#include "../Rivet Engine/Rivet.h"
#include "../Rivet Engine/Scene.h"
#include "../Rivet Engine/SceneManager.h"
#include "../Rivet Engine/SpriteFontManager.h"
#include "../Rivet Engine/SpriteString.h"

#include "Tank.h"

PlayerTankDraw::PlayerTankDraw(Tank* t, const Vect& mainCol, const Vect& accentCol) :
	TankDraw(t, mainCol, accentCol)
{
	followCam = SceneManager::GetCurrent()->GetCurrent3DCamera();

	hudFont = SpriteFontManager::Get("HUD");
	health = new SpriteString(hudFont, "HP: 10");
	health->SetPos(0, health->GetHeight());
	enemyCount = new SpriteString(hudFont, "Remaining: ???");
	enemyCount->SetPos(Rivet::GetWidth() - enemyCount->GetWidth(),
		enemyCount->GetHeight());
}

PlayerTankDraw::~PlayerTankDraw()
{
	delete health;
	delete enemyCount;
}

void PlayerTankDraw::Draw2D()
{
	health->Render();
	enemyCount->Render();
}

void PlayerTankDraw::SetEnemyCount(const int count)
{
	enemyCount->Set(hudFont, "Remaining: " + std::to_string(count),
		Rivet::GetWidth() - enemyCount->GetWidth(), enemyCount->GetHeight());
	enemyCount->SetPos(Rivet::GetWidth() - enemyCount->GetWidth(), enemyCount->GetHeight());
}

void PlayerTankDraw::SetHealth(const int hp)
{
	health->Set(hudFont, "HP: " + std::to_string(hp), 0, health->GetHeight());
}

Camera* PlayerTankDraw::GetCamera()
{
	return followCam;
}

Vect PlayerTankDraw::UpdateCamera(const Vect& pos, const Vect& lookAt)
{
	followCam->setOrientAndPosition(Vect(0, 1, 0), pos, lookAt);
	followCam->updateCamera();

	Vect camPos;
	followCam->getPos(camPos);
	return camPos;
}
