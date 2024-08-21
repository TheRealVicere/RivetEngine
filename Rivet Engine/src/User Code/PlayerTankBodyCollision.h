#ifndef PlayerTankBodyCollision_H
#define PlayerTankBodyCollision_H

#include "Vect.h"

#include "PlayerTankCollision.h"
#include "TankBodyCollision.h"

class PlayerTankBodyCollision : public PlayerTankCollision {
public:
	PlayerTankBodyCollision(PlayerTank* t);
	PlayerTankBodyCollision() = delete;
	PlayerTankBodyCollision(const PlayerTankBodyCollision&) = delete;
	PlayerTankBodyCollision& operator=(const PlayerTankBodyCollision&) = delete;
	~PlayerTankBodyCollision() = default;

	void SetForward(const Vect& fwd) override;
	void Collision(Terrain* t) override;

private:
	Vect forward;
};

#endif
