#include "Rivet.h"

#include <ctime>
#include "AzulCore.h"

#include "AssetAttorney.h"
#include "DebugAttorney.h"
#include "TimeAttorney.h"
#include "SceneChangeAttorney.h"
#include "SceneManager.h"

Rivet* Rivet::instance = nullptr;

Rivet* Rivet::Instance()
{
	if (!instance) instance = new Rivet;
	return instance;
}

//-----------------------------------------------------------------------------
// Rivet::Initialize()
//		Allows the engine to perform any initialization it needs to before 
//      starting to run.  This is where it can query for any required services 
//      and load any non-graphic related content. 
//-----------------------------------------------------------------------------
void Rivet::Initialize()
{
	srand((unsigned int)time(NULL));
	Instance()->GameStart();
}

//-----------------------------------------------------------------------------
// Rivet::LoadContent()
//		Allows you to load all content needed for your engine,
//	    such as objects, graphics, etc.
//-----------------------------------------------------------------------------
void Rivet::LoadContent()
{
	// Load in user-defined assets
	LoadResources();
	SpriteFontManager::Load("Debug", "Consolas20");
	SceneManager::InitStartScene();
}

//-----------------------------------------------------------------------------
// Rivet::Update()
//      Called once per frame, update data, tranformations, etc
//      Use this function to control process order
//      Input, AI, Physics, Animation, and Graphics
//-----------------------------------------------------------------------------
void Rivet::Update()
{
	SceneChangeAttorney::Engine::ChangeScene();
	TimeAttorney::ProcessTime(Instance()->GetTimeInSeconds());
	SceneManager::Update();
}

//-----------------------------------------------------------------------------
// Rivet::Draw()
//		This function is called once per frame
//	    Use this for draw graphics to the screen.
//      Only do rendering here
//-----------------------------------------------------------------------------
void Rivet::Draw() {
	DebugAttorney::Draw();
	SceneManager::Draw();
	DebugAttorney::Draw2D();
}

//-----------------------------------------------------------------------------
// Rivet::UnLoadContent()
//       unload content (resources loaded above)
//       unload all content that was loaded before the Engine Loop started
//-----------------------------------------------------------------------------
void Rivet::UnLoadContent()
{
	// General cleanup
	SceneManager::Terminate();
	AssetAttorney::TerminateAssetManagers();
	TimeAttorney::Terminate();
	DebugAttorney::Terminate();
	GameEnd();
}

void Rivet::Run()
{
	Instance()->run();
}

void Rivet::SetWindowTitle(const std::string title)
{
	Instance()->setWindowName(title.c_str());
}

void Rivet::SetWidthHeight(const int w, const int h)
{
	Instance()->setWidthHeight(w, h);
}

void Rivet::SetTransparency(float r, float g, float b, float a)
{
	Instance()->SetClearColor(r, g, b, a);
}

void Rivet::Terminate()
{
	assert(instance);
	delete instance;
	instance = nullptr;
}

int Rivet::GetWidth()
{
	return Instance()->getWidth();
}

int Rivet::GetHeight()
{
	return Instance()->getHeight();
}
