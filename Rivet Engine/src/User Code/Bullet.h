#ifndef Bullet_H
#define Bullet_H

#include "Matrix.h"

#include "../Rivet Engine/Actor.h"

#include "BulletFactory.h"

class BulletCollision;
class BulletDraw;
class BulletUpdate;
class Enemy;
class Lifetime;
class Tank;

class Bullet : public Actor {
public:
	Bullet();
	Bullet(const Bullet&) = delete;
	Bullet& operator=(const Bullet&) = delete;
	~Bullet();

	void Create();
	void Destroy();
	void EnterScene();
	void ExitScene();

	void SetActiveRef(BulletFactory::ActiveRef ref);
	BulletFactory::ActiveRef GetActiveRef();

	void SetWorld(const Matrix& w);
	void SetRotTrans(const Matrix& rt);
	bool IsFriendly();
	void SetFriendly(const bool f);

private:
	BulletCollision* col;
	BulletDraw* dr;
	BulletUpdate* up;
	Lifetime* lt;

	bool isFriendly;
	BulletFactory::ActiveRef activeRef;
};

#endif
