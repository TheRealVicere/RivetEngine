#ifndef CollisionTestCommand_H
#define CollisionTestCommand_H

#include "Command.h"

class CollisionDispatchBase;
class CollisionGroup;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	CollisionTestCommand
///
/// \brief	A command to test collisions.
///
/// \author	Mike Piunti
/// \date	02/28/2023
////////////////////////////////////////////////////////////////////////////////////////////////////

class CollisionTestCommand : public Command {
public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	CollisionTestCommand::CollisionTestCommand(CollisionGroup* g1, CollisionDispatchBase* d);
	///
	/// \brief	Constructor.
	///
	/// \param	g1	The considered type's collision group.
	/// \param	d 	The dispatch responsible for collision callbacks.
	/////////////////////////////////////////////////////////////////////////////////////////////////
	CollisionTestCommand(CollisionGroup* g1, CollisionDispatchBase* d);

	CollisionTestCommand() = delete;
	CollisionTestCommand(const CollisionTestCommand&) = delete;
	CollisionTestCommand& operator=(const CollisionTestCommand&) = delete;
	virtual ~CollisionTestCommand();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void CollisionTestCommand::Execute() override;
	///
	/// \brief	Executes the collision test on the stored group.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void Execute();

protected:
	/// \brief	The object type's collision group. Used for the first type in pair commands.
	CollisionGroup* group1;

	/// \brief	The dispatch responsible for collision callbacks.
	CollisionDispatchBase* dispatch;
};

#endif
