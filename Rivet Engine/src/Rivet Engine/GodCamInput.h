#ifndef GodCamInput_H
#define GodCamInput_H

#include "IInputCallback.h"

#include "GodCam.h"

class GodCamInput : public IInputCallback {
private:
	GodCam* gc;

public:
	GodCamInput(GodCam* c): gc(c) {}
	GodCamInput() = delete;
	GodCamInput(const GodCamInput&) = delete;
	GodCamInput& operator=(const GodCamInput&) = delete;
	~GodCamInput() = default;

	void KeyEvent() override { gc->Toggle(); }
};

#endif
