#ifndef PlayerTankUpdate_H
#define PlayerTankUpdate_H

#include "Matrix.h"

#include "TankUpdate.h"

class PlayerTank;

class PlayerTankUpdate : public TankUpdate {
public:
	PlayerTankUpdate(PlayerTank* t);
	PlayerTankUpdate() = delete;
	PlayerTankUpdate(const PlayerTankUpdate&) = delete;
	PlayerTankUpdate& operator=(const PlayerTankUpdate&) = delete;
	~PlayerTankUpdate() = default;

	void SetTerrainPos(const Vect& p);
	const Vect& GetCamPos();

private:
	PlayerTank* pTank;

	// Camera Variables
	const Vect camOffset = Vect(0, 30, -150);
	const Vect camTarget = Vect(0, 0, 0);
	Vect camPos;
	Vect terrainPos;

	void Move() override;
	void UpdateCamera() override;
	void ShowDebug() override;
};

#endif
