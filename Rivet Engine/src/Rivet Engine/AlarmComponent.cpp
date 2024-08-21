#include "AlarmComponent.h"

#include "IAlarmCallback.h"
#include "SceneAttorney.h"

AlarmComponent::AlarmComponent(IAlarmCallback* cb, const float time)
{
	assert(("Callback cannot be null!", cb));
	callback = cb;
	triggerTime = time;
}

float AlarmComponent::GetTriggerTime()
{
	return triggerTime;
}

void AlarmComponent::SetTriggerTime(const float time)
{
	if (regState == RegistrationState::Deregistered)
		triggerTime = time;
}

AlarmManager::TimelineRef& AlarmComponent::GetTimelineRef()
{
	return ref;
}

void AlarmComponent::Alarm()
{
	regState = RegistrationState::Deregistered;
	callback->Alarm();
}

void AlarmComponent::OnRegistration()
{
	ref = SceneAttorney::AlarmRegistry::Register(this);
}

void AlarmComponent::OnDeregistration()
{
	SceneAttorney::AlarmRegistry::Deregister(this);
}
