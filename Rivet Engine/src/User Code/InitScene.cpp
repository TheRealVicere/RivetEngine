#include "InitScene.h"

#include "../Rivet Engine/SkyboxManager.h"
#include "../Rivet Engine/TerrainManager.h"

#include "AITank.h"

void InitScene::Initialize()
{
	ait = new AITank;
	terrain = TerrainManager::Get("Flat");
	skybox = SkyboxManager::Get("Day");
}

void InitScene::Terminate()
{
	delete ait;
}
