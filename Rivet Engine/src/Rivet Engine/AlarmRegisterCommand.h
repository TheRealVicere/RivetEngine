#ifndef AlarmRegisterCommand_H
#define AlarmRegisterCommand_H

#include "AlarmableManager.h"
#include "Command.h"

class Alarmable;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	AlarmRegisterCommand
///
/// \brief	A command used to register an alarm.
///
/// \author	Mike Piunti
/// \date	02/28/2023
////////////////////////////////////////////////////////////////////////////////////////////////////
class AlarmRegisterCommand : public Command {
public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	AlarmRegisterCommand::AlarmRegisterCommand(Alarmable* al, const int idNum);
	///
	/// \brief	Constructor. Sets the game object whose alarm to register and the ID of said alarm.
	///
	/// \param	al   	The game object whose alarm to register.
	/// \param	idNum	The alarm identifier.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	AlarmRegisterCommand(Alarmable* al, const int idNum);

	AlarmRegisterCommand() = delete;
	AlarmRegisterCommand(const AlarmRegisterCommand&) = delete;
	AlarmRegisterCommand& operator=(const AlarmRegisterCommand&) = delete;
	~AlarmRegisterCommand() = default;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void AlarmRegisterCommand::Execute();
	///
	/// \brief	Registers the stored alarm.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void Execute(); 

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void AlarmRegisterCommand::SetTime(const float t);
	///
	/// \brief	Sets the amount of time to elapse before triggering the alarm callback.
	///
	/// \param 	t	The time to elapse, in seconds.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void SetTime(const float t);

private:
	/// \brief	The object whose alarm to register.
	Alarmable* alarmable;
	
	/// \brief	The identifier of the alarm to register.
	AlarmableManager::AlarmID id;
	
	/// \brief	The amount of time to pass before triggering the alarm.
	float alarmTime;
};

#endif
