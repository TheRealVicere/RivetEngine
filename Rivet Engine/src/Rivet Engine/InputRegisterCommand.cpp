#include "InputRegisterCommand.h"

#include "InputAttorney.h"

InputRegisterCommand::InputRegisterCommand(Inputable* in, 
	KeyboardManager::InputEvent ev) :
	inputable(in), inEvent(ev) {}

void InputRegisterCommand::Execute()
{
	InputAttorney::Registration::Register(inputable, inEvent);
}
