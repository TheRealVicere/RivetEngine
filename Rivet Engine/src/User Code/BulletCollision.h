#ifndef BulletCollision_H
#define BulletCollision_H

#include "../Rivet Engine/CollisionComponent.h"

class Bullet;

class TankCollision;
class PlayerTankCollision;
class RockCollision;

class BulletCollision : public CollisionComponent {
public:
	BulletCollision(Bullet* b);
	BulletCollision() = delete;
	BulletCollision(const BulletCollision&) = delete;
	BulletCollision& operator=(const BulletCollision&) = delete;
	virtual ~BulletCollision() = default;

	void Collision(BulletCollision* b);
	void Collision(TankCollision* t);
	void Collision(PlayerTankCollision* p);
	void Collision(RockCollision* r);
	void Collision(Terrain* t) override;

	void Destroy();
	bool IsFriendly();

protected:
	Bullet* bullet;
};

#endif
