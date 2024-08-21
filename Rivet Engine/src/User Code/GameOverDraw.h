#ifndef GameOverDraw_H
#define GameOverDraw_H

#include "Matrix.h"

#include "../Rivet Engine/IDrawCallback.h"

class SpriteFont;
class SpriteString;

class Tank;

class GameOverDraw : public IDrawCallback {
public:
	GameOverDraw();
	GameOverDraw(const GameOverDraw&) = delete;
	GameOverDraw& operator=(const GameOverDraw&) = delete;
	~GameOverDraw();

	void Draw() override {};
	void Draw2D() override;
private:
	SpriteFont* hudFont;
	SpriteString* message1;
	SpriteString* message2;
};

#endif
