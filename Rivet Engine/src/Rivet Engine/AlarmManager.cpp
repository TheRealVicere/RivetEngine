#include "AlarmManager.h"

#include "AlarmAttorney.h"
#include "GameTimer.h"

AlarmManager::~AlarmManager()
{
	timeline.clear();
}

void AlarmManager::ProcessElements()
{
	if (timeline.empty()) return;
	TimelineRef ref = timeline.begin();
	while (!timeline.empty() &&
		(ref = timeline.begin())->first < GameTimer::GetElapsedTime()) {
		AlarmAttorney::Alarm(ref->second);
		timeline.erase(ref);
	}
}

AlarmManager::TimelineRef AlarmManager::Register(AlarmComponent* a)
{
	return timeline.emplace(a->GetTriggerTime() + GameTimer::GetElapsedTime(), a);
}

void AlarmManager::Deregister(AlarmComponent* a)
{
	timeline.erase(AlarmAttorney::GetTimelineRef(a));
}
