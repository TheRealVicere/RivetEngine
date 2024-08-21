#ifndef EnemyFactory_H
#define EnemyFactory_H

#include <list>

#include "Matrix.h"

class Enemy;
class EnemyPool;
class GameObject;
class PlayerTank;

class EnemyFactory {
public:
	enum class Mode {
		Chaser, Sentry
	};

private:
	static EnemyFactory* instance;

	EnemyFactory();
	EnemyFactory(const EnemyFactory&) = delete;
	EnemyFactory& operator=(const EnemyFactory&) = delete;
	~EnemyFactory();

	static EnemyFactory& Instance();
	void PrivCreate(Matrix m, Mode mode);
	void PrivRecycle(Enemy* e);
	void PrivRecall();

	EnemyPool* pool;
	typedef std::list<Enemy*> ActiveList;
	ActiveList actives;

public:
	static void Create(Matrix m, Mode mode);
	static void Recycle(Enemy* e);
	static void Recall();
	static void Terminate();
	static void SetTank(PlayerTank* t);

	typedef ActiveList::iterator ActiveRef;
	PlayerTank* tank;
};

#endif
