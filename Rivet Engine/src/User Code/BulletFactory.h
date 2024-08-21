#ifndef BulletFactory_H
#define BulletFactory_H

#include <list>

#include "Matrix.h"

class Bullet;
class BulletPool;
class GameObject;

class BulletFactory {
private:
	static BulletFactory* instance;

	BulletFactory();
	BulletFactory(const BulletFactory&) = delete;
	BulletFactory& operator=(const BulletFactory&) = delete;
	~BulletFactory();

	static BulletFactory& Instance();
	void PrivCreate(Matrix rotTrans, const bool f);
	void PrivRecycle(Bullet* b);
	void PrivRecall();

	BulletPool* pool;
	typedef std::list<Bullet*> ActiveList;
	ActiveList actives;

public:
	static void Create(Matrix rotTrans, const bool f = false);
	static void Recycle(Bullet* b);
	static void Recall();
	static void Terminate();

	typedef ActiveList::iterator ActiveRef;
};

#endif
