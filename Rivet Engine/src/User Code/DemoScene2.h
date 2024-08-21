#ifndef DemoScene2_H
#define DemoScene2_H

#include "../Rivet Engine/Scene.h"

class PlayerTank;
class GodCam;

class DemoScene2 : public Scene {
public:
	DemoScene2() = default;
	DemoScene2(const DemoScene2&) = delete;
	DemoScene2& operator=(const DemoScene2&) = delete;
	~DemoScene2() = default;

	virtual void Initialize();
	virtual void Terminate();

private:
	PlayerTank* t;
	GodCam* gc;
};

#endif
