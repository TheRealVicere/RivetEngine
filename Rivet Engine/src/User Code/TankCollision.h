#ifndef TankCollision_H
#define TankCollision_H

#include "../Rivet Engine/CollisionComponent.h"

class Tank;

class BulletCollision;
class PlayerTankCollision;
class RockCollision;

class TankCollision : public CollisionComponent {
public:
	TankCollision(Tank* t);
	TankCollision() = delete;
	TankCollision(const TankCollision&) = delete;
	TankCollision& operator=(const TankCollision&) = delete;
	virtual ~TankCollision() = default;

	virtual void SetForward(const Vect& fwd);
	virtual void Collision(BulletCollision* b);
	virtual void Collision(TankCollision* t);
	virtual void Collision(PlayerTankCollision* p);
	virtual void Collision(RockCollision* r);

protected:
	Tank* tank;

private:
	Tank* GetOwner();
};

#endif
