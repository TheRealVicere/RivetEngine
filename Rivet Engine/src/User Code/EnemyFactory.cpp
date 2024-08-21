#include "EnemyFactory.h"

#include "Enemy.h"
#include "EnemyPool.h"

EnemyFactory* EnemyFactory::instance = nullptr;

EnemyFactory::EnemyFactory()
{
	pool = new EnemyPool();
	tank = nullptr;
}

EnemyFactory::~EnemyFactory()
{
	delete pool;
	EnemyFactory::instance = nullptr;
}

EnemyFactory& EnemyFactory::Instance()
{
	if (!instance) instance = new EnemyFactory();
	return *instance;
}

void EnemyFactory::PrivCreate(Matrix m, EnemyFactory::Mode mode)
{
	Enemy* e = pool->get();
	e->SetTarget(tank);
	e->SetMode(mode);
	e->Create();
	e->SetActiveRef(actives.insert(actives.end(), e));
	e->SetSpawnMatrix(m);
}

void EnemyFactory::PrivRecycle(Enemy* e)
{
	actives.erase(e->GetActiveRef());
	pool->recycle(e);
}

void EnemyFactory::PrivRecall()
{
	while (!actives.empty()) Recycle(actives.front());
}

void EnemyFactory::Create(Matrix m, EnemyFactory::Mode mode)
{
	Instance().PrivCreate(m, mode);
}

void EnemyFactory::Recycle(Enemy* e)
{
	Instance().PrivRecycle(e);
}

void EnemyFactory::Recall()
{
	Instance().PrivRecall();
}

void EnemyFactory::Terminate() {
	Recall();
	delete instance;
}

void EnemyFactory::SetTank(PlayerTank* t)
{
	Instance().tank = t;
}
