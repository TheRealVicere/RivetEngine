#ifndef Tank_H
#define Tank_H

#include "Matrix.h"

#include "../Rivet Engine/Actor.h"

class TankBodyCollision;
class TankCollision;
class TankDraw;
class TankUpdate;

class Tank : public Actor {
public:
	Tank() = default;
	Tank(const Tank&) = delete;
	Tank& operator=(const Tank&) = delete;
	virtual ~Tank();

	const Vect GetPos();
	void Orient(const Matrix& rot);
	void SetBodyMatrix(const Matrix& m);
	void SetCannonMatrix(const Matrix& m);
	void RollbackFrame();

	virtual void OnHit();
	virtual void Fire();

protected:
	TankCollision* colBody;
	TankCollision* colTurret;
	TankCollision* colBarrel;
	TankDraw* dr;
	TankUpdate* up;

	int hitPoints;

	virtual void SetColliders();
	virtual void CollisionSetup();
};

#endif
