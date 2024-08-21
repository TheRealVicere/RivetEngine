#ifndef SceneCommand_H
#define SceneCommand_H

#include "Command.h"

class Scene;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	SceneCommand
///
/// \brief	The base scene change command.
///
/// \author	Mike Piunti
/// \date	02/28/2023
////////////////////////////////////////////////////////////////////////////////////////////////////

class SceneCommand : public Command {
public:
	SceneCommand() = default;
	SceneCommand(const SceneCommand&) = delete;
	SceneCommand& operator=(const SceneCommand&) = delete;
	virtual ~SceneCommand() = default;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void SceneCommand::SetScene(Scene* s) = 0;
	///
	/// \brief	Sets the next scene.
	///
	/// \param	s	The next scene.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void SetScene(Scene* s) = 0;

protected:
	/// \brief	The next scene to use.
	Scene* next;
};

#endif
