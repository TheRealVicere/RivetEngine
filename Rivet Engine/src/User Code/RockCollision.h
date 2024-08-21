#ifndef RockCollision_H
#define RockCollision_H

#include "../Rivet Engine/CollisionComponent.h"

class BulletCollision;
class PlayerTankCollision;
class TankCollision;

class RockCollision : public CollisionComponent {
public:
	RockCollision() = default;
	RockCollision(const RockCollision&) = delete;
	RockCollision& operator=(const RockCollision&) = delete;
	~RockCollision() = default;

	void Collision(BulletCollision* b) { UNREFERENCED_PARAMETER(b); }
	void Collision(PlayerTankCollision* p) { UNREFERENCED_PARAMETER(p); }
	void Collision(TankCollision* t) { UNREFERENCED_PARAMETER(t); }
};

#endif
