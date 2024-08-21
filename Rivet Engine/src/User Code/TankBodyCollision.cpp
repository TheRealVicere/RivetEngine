#include "TankBodyCollision.h"

#include "../Rivet Engine/Debugger.h"
#include "../Rivet Engine/Terrain.h"

#include "Tank.h"

TankBodyCollision::TankBodyCollision(Tank* t) :
	TankCollision(t), forward(0.0f, 0.0f, 0.0f) {}

void TankBodyCollision::SetForward(const Vect& fwd)
{
	forward.set(fwd);
}

void TankBodyCollision::Collision(Terrain* t)
{
	Vect norm = t->GetNormBelow(tank->GetPos());
	Vect right = norm.cross(forward);
	Vect fwd = right.cross(norm);
	Matrix rot(ROT_ORIENT, fwd, norm);
	tank->Orient(rot);
}
