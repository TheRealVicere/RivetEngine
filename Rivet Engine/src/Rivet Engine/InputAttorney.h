#ifndef InputAttorney_H
#define InputAttorney_H

#include "InputComponent.h"

class InputAttorney {
private:
	friend class KeyHandler;

	static void KeyEvent(InputComponent* i) { i->KeyEvent(); }
	static KeyboardManager::InputListRef GetInputListRef(InputComponent* i) {
		return i->ref;
	}
};

#endif
