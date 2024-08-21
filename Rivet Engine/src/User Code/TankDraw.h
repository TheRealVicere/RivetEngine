#ifndef TankDraw_H
#define TankDraw_H

#include "Matrix.h"

#include "../Rivet Engine/IDrawCallback.h"

class GraphicsObject_TextureLight;
class Model;
class Texture;

class Tank;

class TankDraw : public IDrawCallback {
public:
	TankDraw(Tank* t, const Vect& mainCol, const Vect& accentCol);
	TankDraw() = delete;
	TankDraw(const TankDraw&) = delete;
	TankDraw& operator=(const TankDraw&) = delete;
	virtual ~TankDraw();

	virtual void Draw() override;
	virtual void Draw2D() override {}

	Model* GetBodyModel();
	Model* GetTurretModel();
	Model* GetBarrelModel();

	void SetBodyMatrix(const Matrix& m);
	void SetCannonMatrix(const Matrix& m);

private:
	Tank* tank;

	GraphicsObject_TextureLight* body;
	GraphicsObject_TextureLight* turret;
	GraphicsObject_TextureLight* barrel;

	Texture* mainColor;
	Texture* accentColor;
};

#endif
