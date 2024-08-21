#ifndef InitScene_H
#define InitScene_H

#include "../Rivet Engine/Scene.h"

class AITank;

class InitScene : public Scene {
public:
	InitScene() = default;
	InitScene(const InitScene&) = delete;
	InitScene& operator=(const InitScene&) = delete;
	~InitScene() = default;

	virtual void Initialize();
	virtual void Terminate();

private:
	AITank* ait;
};

#endif
