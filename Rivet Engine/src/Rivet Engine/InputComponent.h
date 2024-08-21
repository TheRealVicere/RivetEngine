#ifndef InputComponent_H
#define InputComponent_H

#include "Component.h"
#include "KeyboardManager.h"

class IInputCallback;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	InputComponent
///
/// \brief	Allows functionality for processing specialized inputs (ie. not raw).
///
/// \author	Mike Piunti
/// \date	02/28/2023
////////////////////////////////////////////////////////////////////////////////////////////////////
class InputComponent : public Component {
	friend class InputAttorney;
public:
	InputComponent(IInputCallback* cb, AZUL_KEY key, KeyboardManager::EventType et);

	InputComponent() = delete;
	InputComponent(const InputComponent&) = delete;
	InputComponent& operator=(const InputComponent&) = delete;
	~InputComponent() = default;

	const KeyboardManager::InputEvent& GetInputEvent();
private:
	/// \brief	The callback carrying out the actual input response.
	IInputCallback* callback;

	/// \brief	The input event this component listens for.
	KeyboardManager::InputEvent inputEvent;

	/// \brief	A reference to the object's location on the input list for efficient deletion.
	KeyboardManager::InputListRef ref;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	KeyboardManager::StorageListRef& InputComponent::GetStorageListRef();
	///
	/// \brief	Gets a reference to the object's location on the input list.
	///
	/// \returns	The update list reference.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	KeyboardManager::InputListRef& GetInputListRef();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void InputComponent::OnRegistration();
	///
	/// \brief	Registers this object for input.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void OnRegistration();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void InputComponent::OnDeregistration();
	///
	/// \brief	Deregisters this object for input.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void OnDeregistration();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void InputComponent::KeyEvent();
	///
	/// \brief	Carries out functionality for when the input event is triggered.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void KeyEvent();
};

#endif
