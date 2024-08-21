#include "BulletCollision.h"

#include "Bullet.h"
#include "TankCollision.h"

BulletCollision::BulletCollision(Bullet* b) :
	bullet(b) {}

void BulletCollision::Collision(BulletCollision* b)
{
	Destroy();
	UNREFERENCED_PARAMETER(b);
}

void BulletCollision::Collision(TankCollision* t)
{
	UNREFERENCED_PARAMETER(t);
}

void BulletCollision::Collision(PlayerTankCollision* p)
{
	UNREFERENCED_PARAMETER(p);
}

void BulletCollision::Collision(RockCollision* r)
{
	Destroy();
	UNREFERENCED_PARAMETER(r);
}

void BulletCollision::Collision(Terrain* t)
{
	Destroy();
	UNREFERENCED_PARAMETER(t);
}

void BulletCollision::Destroy()
{
	bullet->Destroy();
}

bool BulletCollision::IsFriendly()
{
	return bullet->IsFriendly();
}
