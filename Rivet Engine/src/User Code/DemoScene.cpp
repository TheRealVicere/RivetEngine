#include "DemoScene.h"

#include "../Rivet Engine/GodCam.h"
#include "../Rivet Engine/SkyboxManager.h"
#include "../Rivet Engine/Terrain.h"
#include "../Rivet Engine/TerrainManager.h"

#include "Bullet.h"
#include "BulletFactory.h"
#include "Enemy.h"
#include "EnemyFactory.h"
#include "PlayerTank.h"
#include "Rock.h"

#include "BulletCollision.h"
#include "PlayerTankCollision.h"
#include "RockCollision.h"

void DemoScene::Initialize()
{
	gc = new GodCam(GetCurrent3DCamera());
	t = new PlayerTank;
	skybox = SkyboxManager::Get("Day");
	terrain = TerrainManager::Get("Hills");
	
	Vect p1(0, 0, 1000), p2(1000 * sin(MATH_PI4), 0, 1000 * cos(MATH_PI4)),
		p3(1000 * sin(-MATH_PI4), -40, 1000 * cos(-MATH_PI4));
	Vect t1 = terrain->GetPointBelow(p1), t2 = terrain->GetPointBelow(p2),
		t3 = terrain->GetPointBelow(p3);

	EnemyFactory::SetTank(t);
	Matrix world = Matrix(ROT_Y, MATH_PI) * Matrix(TRANS, t1);
	EnemyFactory::Create(world, EnemyFactory::Mode::Chaser);
	world = Matrix(ROT_Y, -MATH_3PI4) * Matrix(TRANS, t2);
	EnemyFactory::Create(world, EnemyFactory::Mode::Chaser);
	world = Matrix(ROT_Y, MATH_3PI4) * Matrix(TRANS, t3);
	EnemyFactory::Create(world, EnemyFactory::Mode::Chaser);

	SetCollisionSelf<BulletCollision>();
	SetCollisionSelf<TankCollision>();
	SetCollisionPair<TankCollision, BulletCollision>();
	SetCollisionPair<PlayerTankCollision, BulletCollision>();
	SetCollisionPair<PlayerTankCollision, TankCollision>();
	SetCollisionTerrain<PlayerTankCollision>();
	SetCollisionTerrain<TankCollision>();
	SetCollisionTerrain<BulletCollision>();
}

void DemoScene::Terminate() {
	delete t;
	delete gc;

	BulletFactory::Terminate();
	EnemyFactory::Terminate();
}
