#ifndef Rock_H
#define Rock_H

#include "Vect.h"

#include "../Rivet Engine/Actor.h"

class RockCollision;
class RockDraw;
class Terrain;

class Rock : public Actor {
public:
	Rock();
	Rock(const Rock&) = delete;
	Rock& operator=(const Rock&) = delete;
	~Rock();

	void SetPos(const Vect& p);
	void Orient(Terrain* t);
	
	void EnterScene() override;
	void ExitScene() override;

private:
	RockCollision* col;
	RockDraw* dr;
};

#endif
