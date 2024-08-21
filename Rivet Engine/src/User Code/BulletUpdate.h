#ifndef BulletUpdate_H
#define BulletUpdate_H

#include "Matrix.h"

#include "../Rivet Engine/IUpdateCallback.h"

class Bullet;

class BulletUpdate : public IUpdateCallback {
public:
	BulletUpdate(Bullet* b);
	BulletUpdate() = delete;
	BulletUpdate(const BulletUpdate&) = delete;
	BulletUpdate& operator=(const BulletUpdate&) = delete;
	~BulletUpdate() = default;

	void Update();
	void SetRotTrans(const Matrix& rt);

private:
	Bullet* bullet;
	Matrix scale;
	Matrix rotTrans;
	const float speed = 5;

	void SetWorld();
};

#endif
