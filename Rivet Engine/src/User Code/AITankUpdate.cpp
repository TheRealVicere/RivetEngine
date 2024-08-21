#include "AITankUpdate.h"

AITankUpdate::AITankUpdate(Tank* t) :
	TankUpdate(t) {}

void AITankUpdate::Move()
{
	mBody = Matrix(ROT_Y, -rotAng) * mBody;
}
