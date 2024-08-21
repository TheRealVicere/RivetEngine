#ifndef FreezeTime_H
#define FreezeTime_H

#include "AzulCore.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	FreezeTime
///
/// \brief	Handles debug freeze frame mode and pauses the game while the window is moving.
///
/// \author	Mike Piunti
/// \date	02/28/2023
////////////////////////////////////////////////////////////////////////////////////////////////////
class FreezeTime
{
private:
	/// \brief	(Immutable) The key to activate freeze frame mode.
	static const AZUL_KEY FREEZE_KEY = AZUL_KEY::KEY_F10;

	/// \brief	(Immutable) The key used to step forward one frame in freeze frame mode.
	static const AZUL_KEY SINGLE_FRAME_KEY = AZUL_KEY::KEY_F9;

	/// \brief	(Immutable) The key to activate debug mode. Used to prevent tying debug tools to scenes.
	static const AZUL_KEY DEBUG_KEY = AZUL_KEY::KEY_F3;

	/// \brief	(Immutable) How much time, in seconds, between two frames that causes the freeze to happen.
	/// Note that low FPS may trigger freeze frame mode as a result.
	static const float DEAD_TIME_THRESHOLD;

	/// \brief	(Immutable) the default frame time, defined at 60 FPS.
	/// Displays with higher refresh rates may experience time offsets compared to normal gameplay.
	static const float DEFAULT_FRAME_TIME;

	/// \brief	The total elapsed time spent in freeze frame mode.
	float totalFrozenTime;

	/// \brief	True if time is frozen.
	bool timeIsFrozen;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	bool FreezeTime::HackedKeyRelease(AZUL_KEY k);
	///
	/// \brief	A helper function to detect a key press-and-release event outside of engine inputs.
	/// 		Used to check for frame steps or to resume normal time flow.
	///
	/// \param 	k	A keyboard key to process.
	///
	/// \returns	True if the key was released, false otherwise.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	bool HackedKeyRelease(AZUL_KEY k);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void FreezeTime::TestForFreezeKeys();
	///
	/// \brief	Tests whether the freeze frame or frame step keys were pressed and released.
	/// 		Handles freeze frame or frame step if needed.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void TestForFreezeKeys();

public:
	FreezeTime();
	~FreezeTime() {};
	FreezeTime(const FreezeTime&) = delete;
	FreezeTime& operator=(const FreezeTime&) = delete;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	float FreezeTime::ComputeGameTime(float sys_time, float prev_time);
	///
	/// \brief	Calculates the true total game time by subtracting frozen time from total time.
	///
	/// \param 	sys_time 	The current system time, in seconds.
	/// \param 	prev_time	The previous system time, in seconds.
	///
	/// \returns	The true elapsed game time, in seconds.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	float ComputeGameTime(float sys_time, float prev_time);
};

#endif
