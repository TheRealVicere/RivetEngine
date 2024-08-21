#include "DeregCommand.h"

#include "Component.h"
#include "RegistryAttorney.h"

DeregCommand::DeregCommand(Component* c) :
	RegDeregCommand(c) {}

void DeregCommand::Execute()
{
	RegistryAttorney::Deregister(component);
}
