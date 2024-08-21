#include "AITank.h"

#include "../Rivet Engine/GameObject.h"

#include "AITankDraw.h"
#include "AITankUpdate.h"
#include "DemoScene.h"
#include "ResetInput.h"

AITank::AITank() : Tank()
{
	Vect main(16.0f, 64.0f, 16.0f);
	Vect accent(1.0f, 32.0f, 1.0f);
	aiDr = new AITankDraw(this, main, accent);
	dr = aiDr;
	go->AddDraw("AI", aiDr);

	CollisionSetup();

	aiUp = new AITankUpdate(this);
	up = aiUp;
	go->AddUpdate("AI", aiUp);

	reset = new ResetInput(this);
	go->AddInput(KEY_SPACE, KeyboardManager::EventType::KeyPressed, reset);
	go->Spawn();
}

AITank::~AITank()
{
	delete reset;
}

void AITank::EnterScene()
{
	go->SetCurrentUpdate("AI");
	go->SetCurrentDraw("AI");
	go->EnableInput(KEY_SPACE, KeyboardManager::EventType::KeyPressed);
}

void AITank::ExitScene()
{
	go->SetCurrentUpdate("Null");
	go->SetCurrentDraw("Null");
	go->DisableInput(KEY_SPACE, KeyboardManager::EventType::KeyPressed);
}
