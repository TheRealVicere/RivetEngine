#include "AITankDraw.h"

#include "../Rivet Engine/Rivet.h"
#include "../Rivet Engine/SpriteFontManager.h"
#include "../Rivet Engine/SpriteString.h"

AITankDraw::AITankDraw(Tank* t, const Vect& mainCol, const Vect& accentCol) :
	TankDraw(t, mainCol, accentCol)
{
	titleFont = SpriteFontManager::Get("Title");
	hudFont = SpriteFontManager::Get("HUD");
	splash1 = new SpriteString(titleFont, "RIVET RAMPAGE");
	splash1->SetPos(Rivet::GetWidth() / 2 - splash1->GetWidth() / 2,
		Rivet::GetHeight());
	splash2 = new SpriteString(hudFont, "Press SPACE to Start");
	splash2->SetPos(Rivet::GetWidth() / 2 - splash2->GetWidth() / 2,
		splash2->GetHeight());
}

AITankDraw::~AITankDraw()
{
	delete splash1;
	delete splash2;
}

void AITankDraw::Draw2D()
{
	splash1->Render();
	splash2->Render();
}
