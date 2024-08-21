#ifndef PlayerTank_H
#define PlayerTank_H

#include "Matrix.h"

#include "Tank.h"

class Camera;
class GameOverDraw;
class PlayerTankDraw;
class PlayerTankInput;
class PlayerTankUpdate;
class ResetInput;

class PlayerTank : public Tank {
public:
	PlayerTank();
	PlayerTank(const PlayerTank&) = delete;
	PlayerTank& operator=(const PlayerTank&) = delete;
	virtual ~PlayerTank();

	Camera* GetCamera();
	Vect UpdateCamera(const Vect& pos, const Vect& lookAt);

	void OnHit() override;
	void OnKill();
	void OnDeath();
	void AddEnemy();
	void Fire() override;

	void ShareTerrainPos(const Vect& p);

	void EnterScene() override;
	void ExitScene() override;

private:
	PlayerTankDraw* pDr;
	GameOverDraw* over;
	PlayerTankInput* fire;
	ResetInput* reset;
	PlayerTankUpdate* pUp;

	int enemiesLeft;

	void SetColliders() override;
};

#endif
