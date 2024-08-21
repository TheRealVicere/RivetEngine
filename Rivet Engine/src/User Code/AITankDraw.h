#ifndef AITankDraw_H
#define AITankDraw_H

#include "TankDraw.h"

class SpriteFont;
class SpriteString;

class AITankDraw : public TankDraw {
public:
	AITankDraw(Tank* t, const Vect& mainCol, const Vect& accentCol);
	AITankDraw() = delete;
	AITankDraw(const AITankDraw&) = delete;
	AITankDraw& operator=(const AITankDraw&) = delete;
	~AITankDraw();

	void Draw2D() override;
private:
	SpriteFont* titleFont;
	SpriteFont* hudFont;
	SpriteString* splash1;
	SpriteString* splash2;
};

#endif
