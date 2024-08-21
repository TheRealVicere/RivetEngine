#include "PlayerTank.h"

#include "../Rivet Engine/GameObject.h"
#include "../Rivet Engine/MathTools.h"

#include "BulletFactory.h"
#include "GameOverDraw.h"
#include "PlayerTankDraw.h"
#include "PlayerTankInput.h"
#include "PlayerTankUpdate.h"
#include "PlayerTankBodyCollision.h"
#include "ResetInput.h"
#include "SceneSequence.h"

PlayerTank::PlayerTank()
{
	Vect main(16.0f, 64.0f, 16.0f);
	Vect accent(1.0f, 32.0f, 1.0f);
	pDr = new PlayerTankDraw(this, main, accent);
	dr = pDr;
	over = new GameOverDraw;
	go->AddDraw("Main Draw", dr);
	go->AddDraw("Game Over", over);

	fire = new PlayerTankInput(this);
	reset = new ResetInput(this);
	go->AddInput(KEY_ENTER, KeyboardManager::EventType::KeyPressed, fire);
	go->AddInput(KEY_SPACE, KeyboardManager::EventType::KeyPressed, reset);

	CollisionSetup();
	go->SetCollisionGroup<PlayerTankCollision>();

	pUp = new PlayerTankUpdate(this);
	up = pUp;
	go->AddUpdate("Update", up);

	go->Spawn();
	hitPoints = 10;
	enemiesLeft = 0;
}

PlayerTank::~PlayerTank()
{
	delete over;
	delete fire;
	delete reset;
}

Camera* PlayerTank::GetCamera()
{
	return pDr->GetCamera();
}

Vect PlayerTank::UpdateCamera(const Vect& pos, const Vect& lookAt)
{
	return pDr->UpdateCamera(pos, lookAt);
}

void PlayerTank::AddEnemy() {
	pDr->SetEnemyCount(++enemiesLeft);
}

void PlayerTank::Fire()
{
	static Matrix bulletPos(TRANS, 0, 0, 40);
	Matrix offset = bulletPos * up->GetCannonMatrix();
	BulletFactory::Create(offset, true);
}

void PlayerTank::ShareTerrainPos(const Vect& p)
{
	pUp->SetTerrainPos(p);
}

void PlayerTank::OnHit()
{
	if (--hitPoints <= 0) OnDeath();
	else pDr->SetHealth(hitPoints);
}

void PlayerTank::OnKill()
{
	pDr->SetEnemyCount(--enemiesLeft);
	if (enemiesLeft == 0) SceneSequence::Next();
}

void PlayerTank::OnDeath()
{
	go->SetCurrentUpdate("Null");
	go->SetCurrentDraw("Game Over");
	go->DisableCollision();
	go->DisableInput(KEY_ENTER, KeyboardManager::EventType::KeyPressed);
	go->EnableInput(KEY_SPACE, KeyboardManager::EventType::KeyPressed);
}

void PlayerTank::EnterScene()
{
	go->SetCurrentUpdate("Update");
	go->SetCurrentDraw("Main Draw");
	go->EnableCollision();
	go->EnableInput(KEY_ENTER, KeyboardManager::EventType::KeyPressed);
}

void PlayerTank::ExitScene()
{
	go->SetCurrentUpdate("Null");
	go->SetCurrentDraw("Null");
	go->DisableCollision();
	go->ClearInputs();
}

void PlayerTank::SetColliders()
{
	colBody = new PlayerTankBodyCollision(this);
	colTurret = new PlayerTankCollision(this);
	colBarrel = new PlayerTankCollision(this);
}
