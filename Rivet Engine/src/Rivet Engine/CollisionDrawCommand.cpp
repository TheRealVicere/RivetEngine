#include "CollisionDrawCommand.h"

#include "DebugAttorney.h"

CollisionDrawCommand::CollisionDrawCommand(const BSphere& S, const Vect& col) :
	sphere(S), color(col) {}

void CollisionDrawCommand::Execute()
{
	float r = sphere.Radius();
	Vect c = sphere.Center();
	Matrix world(SCALE, r, r, r);
	world *= Matrix(TRANS, c);
	DebugAttorney::RenderSphere(world, color);
}
