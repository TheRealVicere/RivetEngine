#ifndef PlayerTankCollision_H
#define PlayerTankCollision_H

#include "TankCollision.h"

class PlayerTank;

class BulletCollision;

class PlayerTankCollision : public TankCollision {
public:
	PlayerTankCollision(PlayerTank* t);
	PlayerTankCollision() = delete;
	PlayerTankCollision(const PlayerTankCollision&) = delete;
	PlayerTankCollision& operator=(const PlayerTankCollision&) = delete;
	virtual ~PlayerTankCollision() = default;

	void Collision(BulletCollision* t) override;
	void Collision(TankCollision* t) override;
	void Collision(PlayerTankCollision* p) override;
	void Collision(RockCollision* r) override;

protected:
	PlayerTank* pTank;
};

#endif
