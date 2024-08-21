#include "DebugLog.h"

#include "Rivet.h"
#include "SpriteFontManager.h"
#include "SpriteString.h"

DebugLog* DebugLog::instance = nullptr;
bool DebugLog::debug = false;

DebugLog::DebugLog()
{
	font = SpriteFontManager::Get("Debug");
	anchorX = 16;
	anchorY = Rivet::GetHeight();
	offsetY = 0;
}

DebugLog::~DebugLog()
{
	Instance()->PrivClear();
}

DebugLog* DebugLog::Instance()
{
	if (!instance) instance = new DebugLog;
	return instance;
}

void DebugLog::Terminate()
{
	delete instance;
}

void DebugLog::PrivClear()
{
	for (auto it = list.begin(); it != list.end(); it++)
		delete *it;
	list.clear();
	offsetY = 0;
}

void DebugLog::Render()
{
	if (!debug) return;
	for (auto it = list.begin(); it != list.end(); it++)
		(*it)->Render();
}

void DebugLog::ToggleDebug()
{
	debug = !debug;
}

void DebugLog::PrivAdd()
{
	SpriteString* ss = new SpriteString(font, std::string(buff), anchorX,
		anchorY - offsetY);
	offsetY += ss->GetHeight();
	list.push_back(ss);
}

void DebugLog::Add(const char* A, ...)
{
	va_list args;
	va_start(args, A);
	vsprintf_s(Instance()->buff, A, args);
	va_end(args);
	
	Instance()->PrivAdd();
}

void DebugLog::Clear()
{
	Instance()->PrivClear();
}
