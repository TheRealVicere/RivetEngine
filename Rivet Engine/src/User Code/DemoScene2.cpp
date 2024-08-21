#include "DemoScene2.h"

#include "../Rivet Engine/GodCam.h"
#include "../Rivet Engine/MathTools.h"
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

void DemoScene2::Initialize()
{
	gc = new GodCam(GetCurrent3DCamera());
	t = new PlayerTank;
	skybox = SkyboxManager::Get("Night");
	terrain = TerrainManager::Get("Snowy");
	
	EnemyFactory::SetTank(t);
	
	Matrix world;
	for (int i = 0; i < 10; i++) {
		Vect p(((float) (rand() % 401) + 200) * sin(MATH_2PI / (float) (rand() % 8 + 1)),
			0, ((float)(rand() % 401) + 200) * cos(MATH_2PI / (float)(rand() % 8 + 1)));
		Vect tp = terrain->GetPointBelow(p);
		world = Matrix(ROT_Y, MathTools::RandomAngle()) * Matrix(TRANS, tp);
		EnemyFactory::Create(world, EnemyFactory::Mode::Sentry);
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

void DemoScene2::Terminate() {
	delete t;
	delete gc;
	BulletFactory::Terminate();
	EnemyFactory::Terminate();
}
