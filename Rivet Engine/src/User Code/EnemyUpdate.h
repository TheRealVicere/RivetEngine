#ifndef EnemyUpdate_H
#define EnemyUpdate_H

#include "Matrix.h"

#include "TankUpdate.h"

class Enemy;

class EnemyUpdate : public TankUpdate {
public:
	EnemyUpdate(Enemy* t);
	EnemyUpdate() = delete;
	EnemyUpdate(const EnemyUpdate&) = delete;
	EnemyUpdate& operator=(const EnemyUpdate&) = delete;
	~EnemyUpdate() = default;

private:
	Enemy* enemy;

	void Move() override;
};

#endif
