#include "AlarmRegisterCommand.h"

#include "AlarmAttorney.h"
#include "MathTools.h"

AlarmRegisterCommand::AlarmRegisterCommand(Alarmable* al, const int idNum) :
	alarmable(al), id((AlarmableManager::AlarmID)idNum), alarmTime(0) {}

void AlarmRegisterCommand::Execute()
{
	assert(alarmTime > MathTools::EPSILON);
	AlarmAttorney::Registration::Register(alarmTime, alarmable, id);
}

void AlarmRegisterCommand::SetTime(const float t)
{
	alarmTime = t;
}
