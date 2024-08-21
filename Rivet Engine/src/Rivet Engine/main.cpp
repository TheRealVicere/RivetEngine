#include "Rivet.h"

int CALLBACK WinMain(HINSTANCE , HINSTANCE ,  LPSTR , int)                  
{          
	// create engine instance
	// Rivet engine;

	// start the game
	// engine.run();
	Rivet::Run();

	// cleanup
	// delete engine;
	Rivet::Terminate();

	return 0;                                       
}
