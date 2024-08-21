#ifndef TankInput_H
#define TankInput_H

#include "../Rivet Engine/IInputCallback.h"

#include "Tank.h"

class TankInput : public IInputCallback {
private:
	Tank* tank;

public:
	TankInput(Tank* t): tank(t) {}
	TankInput() = delete;
	TankInput(const TankInput&) = delete;
	TankInput& operator=(const TankInput&) = delete;
	~TankInput() = default;

	void KeyEvent() override { tank->Fire(); }
};

#endif
