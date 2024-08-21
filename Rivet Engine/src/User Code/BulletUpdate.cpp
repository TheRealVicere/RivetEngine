#include "BulletUpdate.h"

#include "Bullet.h"

BulletUpdate::BulletUpdate(Bullet* b)
{
	bullet = b;
	scale.set(SCALE, 1, 1, 1);
	rotTrans = Matrix(IDENTITY);
	SetWorld();
}

void BulletUpdate::Update()
{
	rotTrans = Matrix(TRANS, Vect(0, 0, speed)) * rotTrans;
	SetWorld();
}

void BulletUpdate::SetRotTrans(const Matrix& rt)
{
	rotTrans = rt;
	SetWorld();
}

void BulletUpdate::SetWorld()
{
	Matrix world = scale * rotTrans;
	bullet->SetWorld(world);
}
