#ifndef EnemyPool_H
#define EnemyPool_H

#include <stack>

class Enemy;

class EnemyPool
{
public:
	EnemyPool();
	EnemyPool(const EnemyPool&) = delete;
	EnemyPool& operator=(const EnemyPool&) = delete;
	~EnemyPool();

	Enemy* get();
	void recycle(Enemy* e);

private:
	std::stack<Enemy*> pool;
};

#endif