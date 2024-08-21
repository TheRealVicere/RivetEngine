#include "KeyHandler.h"

#include "InputAttorney.h"

KeyHandler::KeyHandler(AZUL_KEY k) :
	key(k), isPressed(false) {}

KeyHandler::~KeyHandler()
{
	pressList.clear();
	releaseList.clear();
}

KeyboardManager::InputListRef KeyHandler::Register(InputComponent* i,
	KeyboardManager::InputEvent e)
{
	if ((bool)e.second) return pressList.emplace(pressList.end(), i);
	else return releaseList.emplace(releaseList.end(), i);
}

void KeyHandler::Deregister(InputComponent* i, KeyboardManager::InputEvent e)
{
	if ((bool)e.second)	pressList.erase(InputAttorney::GetInputListRef(i));
	else releaseList.erase(InputAttorney::GetInputListRef(i));
}

void KeyHandler::ProcessKeyEvent()
{
	bool wasJustPressed = isPressed;
	isPressed = Keyboard::GetKeyState(key);
	if (isPressed == wasJustPressed) return;
	if (isPressed) {
		for (InputComponent* i : pressList)
			InputAttorney::KeyEvent(i);
	} else {
		for (InputComponent* i : releaseList)
			InputAttorney::KeyEvent(i);
	}
}

bool KeyHandler::isEmpty()
{
	return (pressList.empty() && releaseList.empty());
}
