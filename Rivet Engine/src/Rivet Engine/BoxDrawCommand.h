#ifndef BoxDrawCommand_H
#define BoxDrawCommand_H

#include "CollisionBox.h"
#include "CollisionDrawCommand.h"
#include "OBB.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	BoxDrawCommand
///
/// \brief	A command to register collision boxes for drawing.
///
/// \author	Mike Piunti
/// \date	04/11/2023
////////////////////////////////////////////////////////////////////////////////////////////////////

class BoxDrawCommand : public CollisionDrawCommand {
public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	BoxDrawCommand::BoxDrawCommand(const CollisionBox& b, const Vect& col);
	///
	/// \brief	Constructor.
	///
	/// \param	b	A collision box to register for drawing.
	/// \param	col	The color in which the visual of the box will be rendered.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	BoxDrawCommand(const CollisionBox& b, const Vect& col);

	BoxDrawCommand() = delete;
	BoxDrawCommand(const BoxDrawCommand&) = delete;
	BoxDrawCommand& operator=(const BoxDrawCommand&) = delete;
	~BoxDrawCommand() = default;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void AABBDrawCommand::Execute();
	///
	/// \brief	Registers the stored object for drawing.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void Execute();

private:
	/// \brief	The box to render.
	OBB box;

	/// \brief	The color to use for rendering.
	Vect color;
};

#endif
