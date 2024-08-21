#include "PlayerTankCollision.h"

#include "BulletCollision.h"
#include "PlayerTank.h"

PlayerTankCollision::PlayerTankCollision(PlayerTank* t) :
	TankCollision(t), pTank(t) {}

void PlayerTankCollision::Collision(BulletCollision* b)
{
	if (!b->IsFriendly())
		pTank->OnHit();
	b->Destroy();
}

void PlayerTankCollision::Collision(TankCollision* t)
{
	pTank->RollbackFrame();
	UNREFERENCED_PARAMETER(t);
}

void PlayerTankCollision::Collision(PlayerTankCollision* p)
{
	UNREFERENCED_PARAMETER(p);
}

void PlayerTankCollision::Collision(RockCollision* r)
{
	pTank->RollbackFrame();
	UNREFERENCED_PARAMETER(r);
}
