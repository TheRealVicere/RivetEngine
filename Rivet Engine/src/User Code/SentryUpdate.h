#ifndef SentryUpdate_H
#define SentryUpdate_H

#include "Matrix.h"

#include "TankUpdate.h"

class Enemy;

class SentryUpdate : public TankUpdate {
public:
	SentryUpdate(Enemy* t);
	SentryUpdate() = delete;
	SentryUpdate(const SentryUpdate&) = delete;
	SentryUpdate& operator=(const SentryUpdate&) = delete;
	~SentryUpdate() = default;

private:
	Enemy* enemy;

	void Move() override;
};

#endif
