#ifndef EnemyAlarm_H
#define EnemyAlarm_H

#include "../Rivet Engine/IAlarmCallback.h"

#include "Enemy.h"

class EnemyAlarm : public IAlarmCallback {
private:
	Enemy* enemy;

public:
	EnemyAlarm(Enemy* e) : enemy(e) {}
	EnemyAlarm(const EnemyAlarm&) = delete;
	EnemyAlarm& operator=(const EnemyAlarm&) = delete;
	~EnemyAlarm() = default;

	virtual void Alarm() { enemy->Alarm(); }
};

#endif
