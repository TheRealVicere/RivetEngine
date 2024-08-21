#ifndef AITank_H
#define AITank_H

#include "Tank.h"

class AITankDraw;
class AITankInput;
class AITankUpdate;
class ResetInput;

class AITank : public Tank {
public:
	AITank();
	AITank(const AITank&) = delete;
	AITank& operator=(const Tank&) = delete;
	~AITank();

	void EnterScene() override;
	void ExitScene() override;

private:
	virtual void Fire() override {};

	AITankDraw* aiDr;
	AITankUpdate* aiUp;
	ResetInput* reset;
};

#endif
