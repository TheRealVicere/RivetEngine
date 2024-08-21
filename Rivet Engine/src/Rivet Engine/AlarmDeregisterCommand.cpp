#include "AlarmDeregisterCommand.h"

#include "AlarmAttorney.h"

AlarmDeregisterCommand::AlarmDeregisterCommand(Alarmable* al, const int idNum) :
	alarmable(al), id((AlarmableManager::AlarmID) idNum) {}

void AlarmDeregisterCommand::Execute()
{
	AlarmAttorney::Registration::Deregister(alarmable, id);
}
