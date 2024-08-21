#include "EnemyPool.h"

#include "Enemy.h"

EnemyPool::EnemyPool() {
	pool = std::stack<Enemy*>();
}

EnemyPool::~EnemyPool() {
	while (!pool.empty()) {
		delete pool.top();
		pool.pop();
	}
}

Enemy* EnemyPool::get()
{
	if (pool.empty()) return new Enemy();
	Enemy* e = pool.top();
	pool.pop();
	return e;
}

void EnemyPool::recycle(Enemy* e)
{
	pool.push(e);
}
