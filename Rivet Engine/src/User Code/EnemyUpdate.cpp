#include "EnemyUpdate.h"

#include "Enemy.h"
#include "PlayerTank.h"

EnemyUpdate::EnemyUpdate(Enemy* t) :
	TankUpdate(t), enemy(t) {}

void EnemyUpdate::Move()
{
	Vect toTank = enemy->GetTarget()->GetPos() - GetPos();
	Vect fwd = mBody.get(ROW_2);
	if (toTank.X() * fwd.Z() > toTank.Z() * fwd.X())
		mBody = Matrix(ROT_Y, rotAng) * mBody;
	else mBody = Matrix(ROT_Y, -rotAng) * mBody;

	mBody = Matrix(TRANS, 0, 0, speed) * mBody;
}
