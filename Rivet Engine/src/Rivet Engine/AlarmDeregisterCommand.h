#ifndef AlarmDeregisterCommand_H
#define AlarmDeregisterCommand_H

#include "AlarmableManager.h"
#include "Command.h"

class Alarmable;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	AlarmDeregisterCommand
///
/// \brief	A command used to deregister an alarm.
///
/// \author	Mike Piunti
/// \date	02/28/2023
////////////////////////////////////////////////////////////////////////////////////////////////////
class AlarmDeregisterCommand : public Command {
public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	AlarmDeregisterCommand::AlarmDeregisterCommand(Alarmable* al, const int idNum);
	///
	/// \brief	Constructor. Sets the game object whose alarm to deregister and the ID of said alarm.
	///
	/// \param	al   	The game object whose alarm to deregister.
	/// \param	idNum	The alarm identifier.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	AlarmDeregisterCommand(Alarmable* al, const int idNum);

	AlarmDeregisterCommand() = delete;
	AlarmDeregisterCommand(const AlarmDeregisterCommand&) = delete;
	AlarmDeregisterCommand& operator=(const AlarmDeregisterCommand&) = delete;
	~AlarmDeregisterCommand() = default;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void AlarmDeregisterCommand::Execute();
	///
	/// \brief	Deregisters the stored alarm.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void Execute();

private:
	/// \brief	The object whose alarm to deregister.
	Alarmable* alarmable;

	/// \brief	The identifier of the alarm to deregister.
	AlarmableManager::AlarmID id;
};

#endif
