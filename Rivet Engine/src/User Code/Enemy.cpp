#include "Enemy.h"

#include "AzulCore.h"

#include "../Rivet Engine/GameObject.h"

#include "Bullet.h"
#include "BulletFactory.h"
#include "EnemyAlarm.h"
#include "EnemyUpdate.h"
#include "PlayerTank.h"
#include "SentryUpdate.h"
#include "TankDraw.h"

Enemy::Enemy() {
	Vect main(80, 16, 16);
	Vect accent(40, 1, 1);
	dr = new TankDraw(this, main, accent);
	go->AddDraw("Draw", dr);

	fire = new EnemyAlarm(this);

	CollisionSetup();
	go->SetCollisionGroup<TankCollision>();

	chaser = new EnemyUpdate(this);
	go->AddUpdate("Chaser", chaser);
	sentry = new SentryUpdate(this);
	go->AddUpdate("Sentry", sentry);
	
	go->AddAlarm("Fire", fire, 1.0f);

	hitPoints = 3;
}

Enemy::~Enemy()
{
	delete chaser;
	delete sentry;
	delete fire;
	up = nullptr;
}

void Enemy::SetActiveRef(EnemyFactory::ActiveRef ref)
{
	activeRef = ref;
}

EnemyFactory::ActiveRef Enemy::GetActiveRef()
{
	return activeRef;
}

void Enemy::SetTarget(PlayerTank* pt)
{
	player = pt;
}

PlayerTank* Enemy::GetTarget()
{
	return player;
}

void Enemy::SetMode(EnemyFactory::Mode m)
{
	switch (m) {
	case EnemyFactory::Mode::Chaser:
		go->SetCurrentUpdate("Chaser");
		up = chaser;
		break;
	case EnemyFactory::Mode::Sentry:
		go->SetCurrentUpdate("Sentry");
		up = sentry;
		break;
	default:
		assert(false);
	}
}

void Enemy::SetSpawnMatrix(Matrix m)
{
	up->Set(m);
}

void Enemy::EnterScene()
{
	go->SetCurrentDraw("Draw");
	go->EnableCollision();
	go->SetAlarm("Fire");
	player->AddEnemy();
}

void Enemy::ExitScene()
{
	go->SetCurrentUpdate("Null");
	go->SetCurrentDraw("Null");
	go->DisableCollision();
	go->CancelAlarm("Fire");
	EnemyFactory::Recycle(this);
	player->OnKill();
}

void Enemy::Alarm()
{
	Fire();
	go->ResetAlarm("Fire", 1.0f);
}

void Enemy::Create()
{
	go->Spawn();
}

void Enemy::Destroy()
{
	go->Despawn();
}
