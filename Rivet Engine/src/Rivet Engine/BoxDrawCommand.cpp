#include "BoxDrawCommand.h"

#include "DebugAttorney.h"

BoxDrawCommand::BoxDrawCommand(const CollisionBox& b, const Vect& col) :
	box(b), color(col) {}

void BoxDrawCommand::Execute()
{
	Matrix w(SCALE, box.Max() - box.Min());
	w *= Matrix(TRANS, (box.Max() + box.Min()) * 0.5f);
	w *= box.World();
	DebugAttorney::RenderBox(w, color);
}
