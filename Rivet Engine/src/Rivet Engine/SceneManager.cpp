#include "SceneManager.h"

#include "NullSceneCommand.h"
#include "Scene.h"
#include "SceneChangeCommand.h"

SceneManager* SceneManager::instance = nullptr;

SceneManager::SceneManager() :
	nullCommand(new NullSceneCommand),
	changeCommand(nullptr), current(nullptr)
{}

SceneManager::~SceneManager()
{
	assert(("No scene found! (Did you set a start scene?)", current));
	current->Terminate();
	delete current;
	delete nullCommand;
	if (changeCommand != nullCommand) delete changeCommand;
	instance = nullptr;
}

SceneManager* SceneManager::Instance()
{
	if (!instance) instance = new SceneManager;
	return instance;
}

void SceneManager::PrivSetNextScene(Scene* const ns)
{
	Instance()->changeCommand = new SceneChangeCommand(ns);
}

void SceneManager::ChangeScene(Scene* const s)
{
	Instance()->current->Terminate();
	delete Instance()->current;
	Instance()->current = s;
	delete Instance()->changeCommand;
	Instance()->changeCommand = Instance()->nullCommand;
	Instance()->current->Initialize();
}

void SceneManager::Terminate()
{
	assert(instance);
	delete instance;
}

void SceneManager::Draw()
{
	Instance()->current->Draw();
}

Scene* SceneManager::GetCurrent()
{
	return Instance()->current;
}

void SceneManager::InitStartScene()
{
	Instance()->current->Initialize();
	Instance()->changeCommand = Instance()->nullCommand;
}

void SceneManager::SetStartScene(Scene* const ss)
{
	Instance()->current = ss;
}

void SceneManager::SetNextScene(Scene* const ns)
{
	Instance()->changeCommand->SetScene(ns);
}

void SceneManager::ExecuteSceneChange()
{
	Instance()->changeCommand->Execute();
}

void SceneManager::Update()
{
	Instance()->current->Update();
}
