#ifndef BulletPool_H
#define BulletPool_H

#include <stack>

class Bullet;

class BulletPool
{
public:
	BulletPool();
	BulletPool(const BulletPool&) = delete;
	BulletPool& operator=(const BulletPool&) = delete;
	~BulletPool();

	Bullet* get();
	void recycle(Bullet* b);

private:
	std::stack<Bullet*> pool;
};

#endif