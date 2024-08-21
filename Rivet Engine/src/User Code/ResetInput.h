#ifndef ResetInput_H
#define ResetInput_H

#include "../Rivet Engine/IInputCallback.h"

class Tank;

class ResetInput : public IInputCallback {
public:
	ResetInput(Tank* t);
	ResetInput() = delete;
	ResetInput(const ResetInput&) = delete;
	ResetInput& operator=(const ResetInput&) = delete;
	~ResetInput() = default;

	void KeyEvent() override;

private:
	Tank* tank;
};

#endif
