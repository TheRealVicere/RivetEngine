#include "InputComponent.h"

#include "IInputCallback.h"
#include "SceneAttorney.h"

InputComponent::InputComponent(IInputCallback* cb, AZUL_KEY key, KeyboardManager::EventType et)
{
	assert(("Callback cannot be null!", cb));
	callback = cb;
	inputEvent.first = key;
	inputEvent.second = et;
}

const KeyboardManager::InputEvent& InputComponent::GetInputEvent()
{
	return inputEvent;
}

KeyboardManager::InputListRef& InputComponent::GetInputListRef()
{
	return ref;
}

void InputComponent::OnRegistration()
{
	ref = SceneAttorney::InputRegistry::Register(this);
}

void InputComponent::OnDeregistration()
{
	SceneAttorney::InputRegistry::Deregister(this);
}

void InputComponent::KeyEvent()
{
	callback->KeyEvent();
}
