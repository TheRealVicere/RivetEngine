#ifndef PlayerTankDraw_H
#define PlayerTankDraw_H

#include "Matrix.h"

#include "TankDraw.h"

class Camera;
class SpriteFont;
class SpriteString;

class PlayerTankDraw : public TankDraw {
public:
	PlayerTankDraw(Tank* t, const Vect& mainCol, const Vect& accentCol);
	PlayerTankDraw() = delete;
	PlayerTankDraw(const PlayerTankDraw&) = delete;
	PlayerTankDraw& operator=(const PlayerTankDraw&) = delete;
	virtual ~PlayerTankDraw();

	virtual void Draw2D() override;

	void SetEnemyCount(const int count);
	void SetHealth(const int hp);

	Camera* GetCamera();
	Vect UpdateCamera(const Vect& pos, const Vect& lookAt);

private:
	Camera* followCam;

	SpriteFont* hudFont;
	SpriteString* health;
	SpriteString* enemyCount;
};

#endif
