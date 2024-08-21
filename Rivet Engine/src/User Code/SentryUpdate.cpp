#include "SentryUpdate.h"

#include "Enemy.h"
#include "PlayerTank.h"

SentryUpdate::SentryUpdate(Enemy* t) :
	TankUpdate(t), enemy(t) {}

void SentryUpdate::Move()
{
	Vect toTank = enemy->GetTarget()->GetPos() - GetPos();
	Vect fwd = mBody.get(ROW_2);
	if (toTank.X() * fwd.Z() > toTank.Z() * fwd.X())
		mBody = Matrix(ROT_Y, rotAng) * mBody;
	else mBody = Matrix(ROT_Y, -rotAng) * mBody;
}
