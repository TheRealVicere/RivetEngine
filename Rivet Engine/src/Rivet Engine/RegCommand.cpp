#include "RegCommand.h"

#include "Component.h"
#include "RegistryAttorney.h"

RegCommand::RegCommand(Component* c) :
	RegDeregCommand(c) {}

void RegCommand::Execute()
{
	RegistryAttorney::Register(component);
}
