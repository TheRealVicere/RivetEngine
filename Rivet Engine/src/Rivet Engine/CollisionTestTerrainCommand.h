#ifndef CollisionTestTerrainCommand_H
#define CollisionTestTerrainCommand_H

#include "CollisionTestCommand.h"

class Terrain;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	CollisionTestTerrainCommand
///
/// \brief	A command to test collision with terrain.
///
/// \author	Mike Piunti
/// \date	05/08/2023
////////////////////////////////////////////////////////////////////////////////////////////////////
class CollisionTestTerrainCommand : public CollisionTestCommand {
public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	CollisionTestTerrainCommand::CollisionTestTerrainCommand(CollisionGroup* g1);
	///
	/// \brief	Constructor.
	///
	/// \param	g1	The considered type's collision group.
	/////////////////////////////////////////////////////////////////////////////////////////////////
	CollisionTestTerrainCommand(CollisionGroup* g1, Terrain* t);

	CollisionTestTerrainCommand() = delete;
	CollisionTestTerrainCommand(const CollisionTestTerrainCommand&) = delete;
	CollisionTestTerrainCommand& operator=(const CollisionTestTerrainCommand&) = delete;
	virtual ~CollisionTestTerrainCommand() = default;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void CollisionTestTerrainCommand::Execute() override;
	///
	/// \brief	Executes the collision test on the stored groups.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void Execute() override;

private:
	/// \brief	The terrain used to process collision.
	Terrain* terrain;
};

#endif
