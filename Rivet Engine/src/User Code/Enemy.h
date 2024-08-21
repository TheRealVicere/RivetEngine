#ifndef Enemy_H
#define Enemy_H

#include "Matrix.h"

#include "EnemyFactory.h"
#include "Tank.h"

class EnemyAlarm;
class EnemyUpdate;
class PlayerTank;
class SentryUpdate;

class Enemy : public Tank {
public:
	Enemy();
	Enemy(const Enemy&) = delete;
	Enemy& operator=(const Enemy&) = delete;
	virtual ~Enemy();

	void SetActiveRef(EnemyFactory::ActiveRef ref);
	EnemyFactory::ActiveRef GetActiveRef();
	void SetTarget(PlayerTank* pt);
	PlayerTank* GetTarget();

	void SetMode(EnemyFactory::Mode m);
	void SetSpawnMatrix(Matrix m);

	void Alarm();

	void Create();
	void Destroy();
	void EnterScene() override;
	void ExitScene() override;

protected:
	EnemyAlarm* fire;
	EnemyUpdate* chaser;
	SentryUpdate* sentry;
	PlayerTank* player;

	EnemyFactory::ActiveRef activeRef;
};

#endif
