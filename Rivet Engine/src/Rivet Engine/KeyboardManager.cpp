#include "KeyboardManager.h"

#include "InputComponent.h"
#include "KeyHandler.h"

KeyboardManager::~KeyboardManager()
{
	for (KeyMapRef ref = keyMap.begin(); ref != keyMap.end(); ref++)
		delete ref->second;
	keyMap.clear();
}

KeyboardManager::InputListRef KeyboardManager::Register(InputComponent* in)
{
	InputEvent ie = in->GetInputEvent();
	if (keyMap.find(ie.first) == keyMap.end()) {
		keyMap[ie.first] = new KeyHandler(ie.first);
	}
	return keyMap[ie.first]->Register(in, ie);
}

void KeyboardManager::Deregister(InputComponent* in)
{
	InputEvent ie = in->GetInputEvent();
	keyMap[ie.first]->Deregister(in, ie);
	if (keyMap[ie.first]->isEmpty()) {
		delete keyMap[ie.first];
		keyMap.erase(ie.first);
	}
}

void KeyboardManager::ProcessKeyEvents()
{
	for (KeyMapRef ref = keyMap.begin(); ref != keyMap.end(); ref++)
		ref->second->ProcessKeyEvent();
}
