#include "SpriteString.h"

#include "Scene.h"
#include "SceneManager.h"

SpriteString::SpriteString(SpriteFont* sf, std::string s, int x, int y)
{
	Set(sf, s, x, y);
}

int SpriteString::GetHeight()
{
	return height;
}

int SpriteString::GetWidth()
{
	return width;
}

void SpriteString::SetPos(const int x, const int y)
{
	posX = x;
	posY = y;
}

void SpriteString::Set(SpriteFont* sf, std::string s, const int x, const int y)
{
	glyphs.clear();
	height = width = 0;
	posX = x;
	posY = y;

	if (sf == nullptr || s == "") return;
	else {
		char next;
		SpriteFont::Glyph* g = nullptr;

		for (size_t i = 0; i < s.length(); i++) {
			next = s.at(i);
			g = sf->GetGlyph(next);
			if (g) {
				width += (int)g->GetWidth();
				if (height < (int)g->GetHeight()) height = (int)g->GetHeight();
				glyphs.push_back(g);
			}
		}
	}
}

void SpriteString::Render()
{
	int currX = posX;

	for (auto it = glyphs.begin(); it != glyphs.end(); it++) {
		(*it)->SetPosition((float) currX, (float) posY);
		(*it)->Render(SceneManager::GetCurrent()->GetCurrent2DCamera());
		currX += (int)(*it)->GetWidth();
	}
}
