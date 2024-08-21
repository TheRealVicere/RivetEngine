#ifndef NullSceneCommand_H
#define NullSceneCommand_H

#include "SceneCommand.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	NullSceneCommand
///
/// \brief	A scene command that allows changing scenes, but does not itself change scenes.
/// 		Used to allow constant change calls without constant scene changes.
///
/// \author	Mike Piunti
/// \date	02/28/2023
////////////////////////////////////////////////////////////////////////////////////////////////////

class NullSceneCommand : public SceneCommand {
public:
	NullSceneCommand() = default;
	NullSceneCommand(const NullSceneCommand&) = delete;
	NullSceneCommand& operator=(const NullSceneCommand&) = delete;
	~NullSceneCommand() = default;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void NullSceneCommand::SetScene(Scene* s);
	///
	/// \brief	Sets the next scene to be used in the game.
	///
	/// \param	s	The next scene to use.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void SetScene(Scene* s);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void NullSceneCommand::Execute()
	///
	/// \brief	Does nothing. Used to allow constant change calls without constant scene changes.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void Execute() {};

protected:
	/// \brief	The next scene to use.
	Scene* next;
};

#endif
