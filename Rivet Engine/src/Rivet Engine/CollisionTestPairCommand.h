#ifndef CollisionTestPairCommand_H
#define CollisionTestPairCommand_H

#include "CollisionTestCommand.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	CollisionTestPairCommand
///
/// \brief	A collision test command for two objects of different types.
///
/// \author	Mike Piunti
/// \date	02/28/2023
////////////////////////////////////////////////////////////////////////////////////////////////////

class CollisionTestPairCommand : public CollisionTestCommand {
public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	CollisionTestPairCommand::CollisionTestPairCommand(CollisionGroup* g1, CollisionGroup* g2, CollisionDispatchBase* d);
	///
	/// \brief	Constructor.
	///
	/// \param	g1	The first type's collision group.
	/// \param	g2	The second type's CollisionGroup.
	/// \param	d 	The dispatch responsible for collision callbacks.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	CollisionTestPairCommand(CollisionGroup* g1, CollisionGroup* g2,
		CollisionDispatchBase* d);

	CollisionTestPairCommand() = delete;
	CollisionTestPairCommand(const CollisionTestPairCommand&) = delete;
	CollisionTestPairCommand& operator=(const CollisionTestPairCommand&)
		= delete;
	~CollisionTestPairCommand() = default;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void CollisionTestPairCommand::Execute() override;
	///
	/// \brief	Executes the collision test on the stored groups.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void Execute() override;

private:
	/// \brief	The second type's collision group.
	CollisionGroup* group2;
};

#endif
