#ifndef RockDraw_H
#define RockDraw_H

#include "Matrix.h"

#include "../Rivet Engine/IDrawCallback.h"

class GraphicsObject_TextureLight;
class Model;
class Rock;
class Terrain;

class RockDraw : public IDrawCallback {
public:
	RockDraw(Rock* r);
	RockDraw() = delete;
	RockDraw(const RockDraw&) = delete;
	RockDraw& operator=(const RockDraw&) = delete;
	~RockDraw();

	void SetPos(const Vect& p);
	const Matrix Orient(Terrain* t);

	Model* GetModel();

	void Draw() override;
	void Draw2D() override {}

private:
	Rock* rock;
	GraphicsObject_TextureLight* model;
	Matrix world;
	Matrix scale;
};

#endif
