#include "ResetInput.h"

#include "SceneSequence.h"
#include "Tank.h"

ResetInput::ResetInput(Tank* t) :
	tank(t) {}

void ResetInput::KeyEvent()
{
	SceneSequence::Set(0);
}
