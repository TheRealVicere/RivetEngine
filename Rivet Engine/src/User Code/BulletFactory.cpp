#include "BulletFactory.h"

#include "Bullet.h"
#include "BulletPool.h"

BulletFactory* BulletFactory::instance = nullptr;

BulletFactory::BulletFactory()
{
	pool = new BulletPool();
}

BulletFactory::~BulletFactory()
{
	delete pool;
	BulletFactory::instance = nullptr;
}

BulletFactory& BulletFactory::Instance()
{
	if (!instance) instance = new BulletFactory();
	return *instance;
}

void BulletFactory::PrivCreate(Matrix rotTrans, const bool f)
{
	Bullet* b = pool->get();
	b->SetFriendly(f);
	b->Create();
	b->SetActiveRef(actives.insert(actives.end(), b));
	b->SetRotTrans(rotTrans);
}

void BulletFactory::PrivRecycle(Bullet* b)
{
	actives.erase(b->GetActiveRef());
	pool->recycle(b);
}

void BulletFactory::PrivRecall()
{
	while (!actives.empty()) Recycle(actives.front());
}

void BulletFactory::Create(Matrix rotTrans, const bool f)
{
	Instance().PrivCreate(rotTrans, f);
}

void BulletFactory::Recycle(Bullet* b)
{
	Instance().PrivRecycle(b);
}

void BulletFactory::Recall()
{
	Instance().PrivRecall();
}

void BulletFactory::Terminate() {
	Recall();
	delete instance;
}