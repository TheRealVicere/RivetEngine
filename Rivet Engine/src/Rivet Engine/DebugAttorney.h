#ifndef DebugAttorney_H
#define DebugAttorney_H

#include "Matrix.h"

#include "Debugger.h"
#include "DebugLog.h"

class DebugAttorney {
	friend class BoxDrawCommand;
	friend class SphereDrawCommand;
	friend class FreezeTime;
	friend class Rivet;
private:
	static void Draw() {
		Debugger::Instance()->DrawAll();
	}
	
	static void Draw2D() {
		DebugLog::Instance()->Render();
	}

	static void Terminate() { 
		Debugger::Terminate();
		DebugLog::Terminate();
	}

	static void RenderSphere(Matrix& w, const Vect& col) {
		Debugger::Instance()->RenderSphere(w, col);
	}

	static void RenderBox(Matrix& w, const Vect& col) {
		Debugger::Instance()->RenderBox(w, col);
	}

	static void ToggleDebug() {
		Debugger::ToggleDebug();
		DebugLog::ToggleDebug();
	}
};

#endif
