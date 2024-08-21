#ifndef KillScene_H
#define KillScene_H

#include "../Rivet Engine/Scene.h"

class GodCam;
class PlayerTank;

class KillScene : public Scene {
public:
	KillScene() = default;
	KillScene(const KillScene&) = delete;
	KillScene& operator=(const KillScene&) = delete;
	~KillScene() = default;

	virtual void Initialize();
	virtual void Terminate();

private:
	GodCam* gc;
	PlayerTank* t;
};

#endif
