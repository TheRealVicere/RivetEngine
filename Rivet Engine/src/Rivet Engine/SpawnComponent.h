#ifndef SpawnComponent_H
#define SpawnComponent_H

#include "Component.h"
#include "Scene.h"

class ISpawnCallback;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	SpawnComponent
///
/// \brief	An actor or other object used in a game scene.
///
/// \author	Mike Piunti
/// \date	02/28/2023
////////////////////////////////////////////////////////////////////////////////////////////////////
class SpawnComponent : public Component {
	friend class SpawnAttorney;
public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	SpawnComponent::SpawnComponent(ISpawnCallback* cb);
	///
	/// \brief	Creates a spawn component using the given callback.
	///
	/// \param	cb	The callback carrying out the actual spawn and despawn operations.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	SpawnComponent(ISpawnCallback* cb);

	SpawnComponent() = delete;
	SpawnComponent(const SpawnComponent&) = delete;
	SpawnComponent& operator=(const SpawnComponent&) = delete;
	virtual ~SpawnComponent() = default;

private:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void SpawnComponent::OnRegistration();
	///
	/// \brief	Spawns this object into the scene.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void OnRegistration();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void SpawnComponent::OnDeregistration();
	///
	/// \brief	Despawns this object out of the scene.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void OnDeregistration();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void SpawnComponent::EnterScene()
	///
	/// \brief	Used to enable functionality of an object.
	///
	/// All of an object's components should be enabled here.
	/// 
	/// \par Example:
	/// Suppose a game object MySpawnComponent needs to respond to pressing the Enter key and needs update,
	/// draw, and collision functionality. This can be implemented as follows:
	/// \code
	/// 	void MySpawnComponent::EnterScene()
	///		{
	///			EnableUpdates();
	///			EnableDrawing();
	///			EnableCollision();
	///			AddInput(AZUL_KEY::KEY_ENTER, KeyboardManager::EventType::KeyPressed);
	///		}
	///	\endcode
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void EnterScene();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void SpawnComponent::ExitScene()
	///
	/// \brief	Used to disable functionality of this object.
	///
	/// All inputs and alarms should be cleared here. Collision, updates, and drawing should also be
	/// disabled here if needed.
	/// 
	/// \par Example:
	/// Suppose a game object MySpawnComponent was responding to pressing the Enter key and used update,
	/// draw, and collision functionality. Safely disabling these can be implemented as follows:
	/// \code
	/// 	void MySpawnComponent::EnterScene()
	///		{
	///			DisableUpdates();
	///			DisableDrawing();
	///			DisableCollision();
	///			ClearInput(AZUL_KEY::KEY_ENTER, KeyboardManager::EventType::KeyPressed);
	///		}
	///	\endcode
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void ExitScene();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	Scene::SpawnListRef SpawnComponent::GetSpawnListRef();
	///
	/// \brief	Gets a reference to this object's location in the spawn list.
	///
	/// \returns	The object's storage list reference.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	Scene::SpawnListRef GetSpawnListRef();

	/// \brief	The object's storage list reference.
	Scene::SpawnListRef ref;

	/// \brief	The callback carrying out the actual spawn and despawn operations.
	ISpawnCallback* callback;
};

#endif
