#ifndef TankBodyCollision_H
#define TankBodyCollision_H

#include "TankCollision.h"

class TankBodyCollision : virtual public TankCollision {
public:
	TankBodyCollision(Tank* t);
	TankBodyCollision() = delete;
	TankBodyCollision(const TankBodyCollision&) = delete;
	TankBodyCollision& operator=(const TankBodyCollision&) = delete;
	virtual ~TankBodyCollision() = default;

	void SetForward(const Vect& fwd) override;
	void Collision(Terrain* t) override;

private:
	Vect forward;
};

#endif
