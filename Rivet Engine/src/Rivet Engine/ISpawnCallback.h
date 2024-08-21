#ifndef ISpawnCallback_H
#define ISpawnCallback_H

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	ISpawnCallback
///
/// \brief	A callback to perform the duties of a spawn component.
/// 		User-defined derived classes should hold the game objects to spawn and despawn.
///
/// \author	Mike Piunti
/// \date	04/26/2023
////////////////////////////////////////////////////////////////////////////////////////////////////
class ISpawnCallback {
public:
	ISpawnCallback() = default;
	ISpawnCallback(const ISpawnCallback&) = delete;
	ISpawnCallback& operator=(const ISpawnCallback&) = delete;
	virtual ~ISpawnCallback() = default;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void ISpawnCallback::EnterScene() = 0;
	///
	/// \brief	Spawns an object.
	/// 		
	/// Usually, this method simply calls the object's enable functions:
	/// \code
	/// 	void MyCallback::EnterScene() {
	/// 		EnableUpdates();
	/// 		EnableDrawing();
	/// 		// And so on...
	/// 	}
	/// \endcode
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void EnterScene() = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void ISpawnCallback::ExitScene() = 0;
	///
	/// \brief	Despawns an object.
	/// 		
	/// Usually, this method simply calls the object's disable functions:
	/// \code
	/// 	void MyCallback::EnterScene() {
	/// 		DisableUpdates();
	/// 		DisableDrawing();
	/// 		// And so on...
	/// 	}
	/// \endcode
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void ExitScene() = 0;
};

#endif
