#include "NullSceneCommand.h"

#include "SceneChangeAttorney.h"

void NullSceneCommand::SetScene(Scene* s)
{
	SceneChangeAttorney::Commands::SetScene(s);
}
