#ifndef InputRegisterCommand_H
#define InputRegisterCommand_H

#include "Command.h"
#include "KeyboardManager.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	InputRegisterCommand
///
/// \brief	An command to register keyboard inputs.
///
/// \author	Mike Piunti
/// \date	02/28/2023
////////////////////////////////////////////////////////////////////////////////////////////////////

class InputRegisterCommand : public Command {
public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	InputRegisterCommand::InputRegisterCommand(Inputable* in, KeyboardManager::InputEvent ev);
	///
	/// \brief	Constructor.
	///
	/// \param	in	The object whose input to register.
	/// \param	ev	The input event to register.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	InputRegisterCommand(Inputable* in, KeyboardManager::InputEvent ev);

	InputRegisterCommand() = delete;
	InputRegisterCommand(const InputRegisterCommand&) = delete;
	InputRegisterCommand& operator=(const InputRegisterCommand&) = delete;
	~InputRegisterCommand() = default;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void InputRegisterCommand::Execute();
	///
	/// \brief	Registers the stored input for the stored object.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void Execute();

private:
	/// \brief	The object whose input to register.
	Inputable* inputable;

	/// \brief	The input event to register.
	KeyboardManager::InputEvent inEvent;
};

#endif
