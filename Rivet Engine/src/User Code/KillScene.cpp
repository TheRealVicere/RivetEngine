#include "KillScene.h"

#include "../Rivet Engine/GodCam.h"
#include "../Rivet Engine/SkyboxManager.h"
#include "../Rivet Engine/Terrain.h"
#include "../Rivet Engine/TerrainManager.h"

#include "Bullet.h"
#include "BulletFactory.h"
#include "Enemy.h"
#include "EnemyFactory.h"
#include "PlayerTank.h"

#include "BulletCollision.h"
#include "PlayerTankCollision.h"

void KillScene::Initialize()
{
	gc = new GodCam(GetCurrent3DCamera());
	t = new PlayerTank;
	skybox = SkyboxManager::Get("Hell");
	terrain = TerrainManager::Get("Hell");
	
	float angle = 0;
	EnemyFactory::SetTank(t);

	for (int i = 0; i < 8; i++) {
		Matrix world(ROT_Y, angle + MATH_PI);
		world *= Matrix(TRANS, 200 * sin(angle), 0, 200 * cos(angle));
		EnemyFactory::Create(world, EnemyFactory::Mode::Chaser);
		angle += MATH_PI4;
	}

	SetCollisionSelf<BulletCollision>();
	SetCollisionSelf<TankCollision>();
	SetCollisionPair<TankCollision, BulletCollision>();
	SetCollisionPair<PlayerTankCollision, BulletCollision>();
	SetCollisionPair<PlayerTankCollision, TankCollision>();
	SetCollisionTerrain<PlayerTankCollision>();
	SetCollisionTerrain<TankCollision>();
	SetCollisionTerrain<BulletCollision>();
}

void KillScene::Terminate() {
	delete t;
	delete gc;

	BulletFactory::Terminate();
	EnemyFactory::Terminate();
}
