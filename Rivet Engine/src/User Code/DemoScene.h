#ifndef DemoScene_H
#define DemoScene_H

#include "../Rivet Engine/Scene.h"

class GodCam;
class PlayerTank;

class DemoScene : public Scene {
public:
	DemoScene() = default;
	DemoScene(const DemoScene&) = delete;
	DemoScene& operator=(const DemoScene&) = delete;
	~DemoScene() = default;

	virtual void Initialize();
	virtual void Terminate();

private:
	GodCam* gc;
	PlayerTank* t;
};

#endif
