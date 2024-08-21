#ifndef AlarmAttorney_H
#define AlarmAttorney_H

#include "AlarmComponent.h"

class AlarmAttorney {
	friend class AlarmManager;
private:
	static void Alarm(AlarmComponent* a) { a->Alarm(); }
	static AlarmManager::TimelineRef GetTimelineRef(AlarmComponent* a) {
		return a->GetTimelineRef();
	}
};

#endif
