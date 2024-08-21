#include "SceneChangeCommand.h"

#include "Scene.h"
#include "SceneChangeAttorney.h"

SceneChangeCommand::SceneChangeCommand(Scene* s) 
{
	next = s;
}

SceneChangeCommand::~SceneChangeCommand()
{
	if (next) delete next;
}

void SceneChangeCommand::SetScene(Scene* s)
{
	delete s;
}

void SceneChangeCommand::Execute()
{
	Scene* s = next;
	next = nullptr;
	SceneChangeAttorney::Commands::ChangeScene(s);
}
