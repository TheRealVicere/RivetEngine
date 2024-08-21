#include "GameOverDraw.h"

#include "../Rivet Engine/Rivet.h"
#include "../Rivet Engine/SpriteFontManager.h"
#include "../Rivet Engine/SpriteString.h"

GameOverDraw::GameOverDraw()
{
	hudFont = SpriteFontManager::Get("HUD");
	message1 = new SpriteString(hudFont, "GAME OVER");
	message1->SetPos(Rivet::GetWidth() / 2 - message1->GetWidth() / 2,
		Rivet::GetHeight() / 2 + message1->GetHeight());
	message2 = new SpriteString(hudFont, "PRESS [SPACE] TO RETRY");
	message2->SetPos(Rivet::GetWidth() / 2 - message2->GetWidth() / 2,
		Rivet::GetHeight() / 2);
}

GameOverDraw::~GameOverDraw()
{
	delete message1;
	delete message2;
}


void GameOverDraw::Draw2D()
{
	message1->Render();
	message2->Render();
}
