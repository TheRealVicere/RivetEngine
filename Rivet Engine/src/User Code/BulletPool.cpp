#include "BulletPool.h"

#include "Bullet.h"

BulletPool::BulletPool() {
	pool = std::stack<Bullet*>();
}

BulletPool::~BulletPool() {
	while (!pool.empty()) {
		delete pool.top();
		pool.pop();
	}
}

Bullet* BulletPool::get()
{
	if (pool.empty()) return new Bullet();
	Bullet* b = pool.top();
	pool.pop();
	return b;
}

void BulletPool::recycle(Bullet* b)
{
	pool.push(b);
}
