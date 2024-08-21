#include "TerrainTestScene.h"

#include "../Rivet Engine/GodCam.h"
#include "../Rivet Engine/SkyboxManager.h"
#include "../Rivet Engine/TerrainManager.h"

#include "BulletFactory.h"
#include "PlayerTank.h"
#include "PlayerTankCollision.h"

void TerrainTestScene::Initialize()
{
	gc = new GodCam(GetCurrent3DCamera());
	tank = new PlayerTank;
	terrain = TerrainManager::Get("Hills");
	skybox = SkyboxManager::Get("Day");
	SetCollisionTerrain<PlayerTankCollision>();
}

void TerrainTestScene::Terminate()
{
	delete tank;
	delete gc;
	BulletFactory::Terminate();
}
