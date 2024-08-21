#ifndef PlayerTankInput_H
#define PlayerTankInput_H

#include "../Rivet Engine/IInputCallback.h"

#include "PlayerTank.h"

class PlayerTankInput : public IInputCallback {
private:
	PlayerTank* tank;

public:
	PlayerTankInput(PlayerTank* t): tank(t) {}
	PlayerTankInput() = delete;
	PlayerTankInput(const PlayerTankInput&) = delete;
	PlayerTankInput& operator=(const PlayerTankInput&) = delete;
	~PlayerTankInput() = default;

	void KeyEvent() override { tank->Fire(); }
};

#endif
