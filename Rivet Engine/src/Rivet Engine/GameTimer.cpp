#include "GameTimer.h"

GameTimer* GameTimer::instance = nullptr;

GameTimer::GameTimer() :
	currentTime(0), frameTime(0), prevTime(0) {}

GameTimer* GameTimer::Instance()
{
	if (!instance) instance = new GameTimer;
	return instance;
}

void GameTimer::Terminate()
{
	delete instance;
	instance = nullptr;
}

void GameTimer::ProcessTime(const float sys_time)
{
	Instance()->prevTime = Instance()->currentTime;
	Instance()->currentTime = Instance()->freeze.ComputeGameTime(sys_time,
		Instance()->prevTime);
	Instance()->frameTime = Instance()->currentTime - Instance()->prevTime;
}

float GameTimer::GetFrameTime()
{
	return Instance()->frameTime;
}

float GameTimer::GetElapsedTime()
{
	return Instance()->currentTime;
}
