#ifndef TimeAttorney_H
#define TimeAttorney_H

#include "GameTimer.h"

class TimeAttorney {
private:
	friend class Rivet;
	static void ProcessTime(const float sys_time) { GameTimer::ProcessTime(sys_time); }
	static void Terminate() { GameTimer::Terminate(); }
};

#endif
