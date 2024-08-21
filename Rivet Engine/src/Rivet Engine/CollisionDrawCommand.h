#ifndef CollisionDrawCommand_H
#define CollisionDrawCommand_H

#include "CollisionVolume.h"
#include "Command.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	CollisionDrawCommand
///
/// \brief	A command to register collision volumes for drawing.
///
/// \author	Mike Piunti
/// \date	04/11/2023
////////////////////////////////////////////////////////////////////////////////////////////////////

class CollisionDrawCommand : public Command {
public:
	CollisionDrawCommand() = default;
	CollisionDrawCommand(const CollisionDrawCommand&) = delete;
	CollisionDrawCommand& operator=(const CollisionDrawCommand&) = delete;
	virtual ~CollisionDrawCommand() = default;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void CollisionDrawCommand::Execute();
	///
	/// \brief	Registers the stored object for drawing.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void Execute() = 0;
};

#endif
