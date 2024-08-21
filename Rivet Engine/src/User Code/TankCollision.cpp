#include "TankCollision.h"

#include "BulletCollision.h"
#include "PlayerTankCollision.h"
#include "Tank.h"

TankCollision::TankCollision(Tank* t) :
	tank(t) {}

Tank* TankCollision::GetOwner()
{
	return tank;
}

void TankCollision::SetForward(const Vect& fwd)
{
	UNREFERENCED_PARAMETER(fwd);
}

void TankCollision::Collision(BulletCollision* b)
{
	if (b->IsFriendly())
		tank->OnHit();
	b->Destroy();
}

void TankCollision::Collision(TankCollision* t)
{
	if (t->GetOwner() == tank) return;
	tank->RollbackFrame();
	UNREFERENCED_PARAMETER(t);
}

void TankCollision::Collision(PlayerTankCollision* p)
{
	tank->RollbackFrame();
	UNREFERENCED_PARAMETER(p);
}

void TankCollision::Collision(RockCollision* r)
{
	tank->RollbackFrame();
	UNREFERENCED_PARAMETER(r);
}
