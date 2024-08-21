#ifndef KeyHandler_H
#define KeyHandler_H

#include "KeyboardManager.h"

class InputComponent;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	KeyHandler
///
/// \brief	An input handler for a specific keyboard key.
///
/// \author	Mike Piunti
/// \date	02/28/2023
////////////////////////////////////////////////////////////////////////////////////////////////////
class KeyHandler {
private:
	/// \brief	The key to handle.
	AZUL_KEY key;

	/// \brief	List of objects listening for this key to be pressed.
	KeyboardManager::InputList pressList;

	/// \brief	List of objects listening for this key to be released.
	KeyboardManager::InputList releaseList;

	/// \brief	True if the key is held down, false if not.
	bool isPressed;

public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	KeyHandler::KeyHandler(AZUL_KEY k);
	///
	/// \brief	Constructor.
	///
	/// \param 	k	The keyboard key to handle.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	KeyHandler(AZUL_KEY k);

	KeyHandler() = delete;
	KeyHandler(const KeyHandler&) = delete;
	KeyHandler& operator=(const KeyHandler&) = delete;
	~KeyHandler();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	KeyboardManager::InputListRef KeyHandler::Register(InputComponent* i, KeyboardManager::InputEvent e);
	///
	/// \brief	Registers the given object for input handling.
	///
	/// \param	i	The object to register.
	/// \param	e	The input event to handle.
	///
	/// \returns	A reference to the object's location on the requested event map.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	KeyboardManager::InputListRef Register(InputComponent* i,
		KeyboardManager::InputEvent e);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void KeyHandler::Deregister(InputComponent* i, KeyboardManager::InputEvent e);
	///
	/// \brief	Deregisters the given object for input handling.
	///
	/// \param	i	The object to deregister.
	/// \param	e	The input event to stop handling.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void Deregister(InputComponent* i, KeyboardManager::InputEvent e);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void KeyHandler::ProcessKeyEvent();
	///
	/// \brief	Checks if the stored key was just pressed or released, then process callbacks if it was.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void ProcessKeyEvent();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	bool KeyHandler::isEmpty();
	///
	/// \brief	Checks if there are no more objects listening for this key.
	///
	/// \returns	True if empty, false if not.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	bool isEmpty();
};

#endif
