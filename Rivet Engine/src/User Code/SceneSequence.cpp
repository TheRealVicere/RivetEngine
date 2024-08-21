#include "SceneSequence.h"

#include "../Rivet Engine/Scene.h"
#include "../Rivet Engine/SceneManager.h"

#include "DemoScene.h"
#include "DemoScene2.h"
#include "KillScene.h"

int SceneSequence::current = 0;

void SceneSequence::Next()
{
	Set(current + 1);
}

void SceneSequence::Set(const int num)
{
	current = num;

	switch (num) {
	case 0:
		SceneManager::SetNextScene(new DemoScene);
		break;
	case 1:
		SceneManager::SetNextScene(new DemoScene2);
		break;
	case 2:
	default:
		SceneManager::SetNextScene(new KillScene);
	}
}
