#ifndef AITankUpdate_H
#define AITankUpdate_H

#include "Matrix.h"

#include "TankUpdate.h"

class AITankUpdate : public TankUpdate {
public:
	AITankUpdate(Tank* t);
	AITankUpdate() = delete;
	AITankUpdate(const AITankUpdate&) = delete;
	AITankUpdate& operator=(const AITankUpdate&) = delete;
	~AITankUpdate() = default;

	void Set(Matrix m) override {}

private:
	void Move() override;
};

#endif
