#include "PlayerTankBodyCollision.h"

#include "../Rivet Engine/Terrain.h"

#include "PlayerTank.h"

PlayerTankBodyCollision::PlayerTankBodyCollision(PlayerTank* t) :
	PlayerTankCollision(t) {}

void PlayerTankBodyCollision::SetForward(const Vect& fwd)
{
	forward = fwd;
}

void PlayerTankBodyCollision::Collision(Terrain* t)
{
	Vect norm = t->GetNormBelow(pTank->GetPos());
	Vect right = norm.cross(forward);
	Vect fwd = right.cross(norm);
	Matrix rot(ROT_ORIENT, fwd, norm);
	pTank->Orient(rot);

	Vect pos = t->GetPointBelow(pTank->GetPos());
	pTank->ShareTerrainPos(pos);
}
