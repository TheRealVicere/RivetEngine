#ifndef BulletDraw_H
#define BulletDraw_H

#include "Matrix.h"

#include "../Rivet Engine/IDrawCallback.h"

class GraphicsObject_TextureLight;
class Model;
class Texture;

class Bullet;

class BulletDraw : public IDrawCallback {
public:
	BulletDraw(Bullet* b);
	BulletDraw() = delete;
	BulletDraw(const BulletDraw&) = delete;
	BulletDraw& operator=(const BulletDraw&) = delete;
	~BulletDraw();

	void Draw() override;
	void Draw2D() override {}

	Model* GetModel();

	void SetWorld(const Matrix& m);
private:
	Bullet* bullet;	
	GraphicsObject_TextureLight* body;
	Texture* color;
};

#endif
