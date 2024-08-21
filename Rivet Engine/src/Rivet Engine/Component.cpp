#include "Component.h"

#include "DeregCommand.h"
#include "RegCommand.h"
#include "SceneAttorney.h"

Component::Component() :
	regState(RegistrationState::Deregistered),
	regCmd(new RegCommand(this)), deregCmd(new DeregCommand(this)) {}

Component::~Component()
{
	delete regCmd;
	delete deregCmd;
}

void Component::Enable()
{
	if (regState == RegistrationState::PendingRegistration) return;
	assert(regState == RegistrationState::Deregistered);
	SceneAttorney::Commands::SubmitCommand(regCmd);
	regState = RegistrationState::PendingRegistration;
}

void Component::Disable()
{
	if (regState == RegistrationState::Deregistered ||
		regState == RegistrationState::PendingDeregistration) return;
	assert(regState == RegistrationState::Registered);
	SceneAttorney::Commands::SubmitCommand(deregCmd);
	regState = RegistrationState::PendingDeregistration;
}

void Component::Register()
{
	assert(regState == RegistrationState::PendingRegistration);
	OnRegistration();
	regState = RegistrationState::Registered;
}

void Component::Deregister()
{
	assert(regState == RegistrationState::PendingDeregistration);
	OnDeregistration();
	regState = RegistrationState::Deregistered;
}
