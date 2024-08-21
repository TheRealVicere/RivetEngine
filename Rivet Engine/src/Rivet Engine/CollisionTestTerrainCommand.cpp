#include "CollisionTestTerrainCommand.h"

#include "CollisionAttorney.h"
#include "CollisionComponent.h"
#include "CollisionDispatchBase.h"
#include "CollisionGroup.h"
#include "Colors.h"
#include "Debugger.h"
#include "MathTools.h"
#include "Terrain.h"
#include "TerrainRect.h"
#include "TerrainRectIterator.h"

CollisionTestTerrainCommand::CollisionTestTerrainCommand(CollisionGroup* g1, Terrain* t) :
	CollisionTestCommand(g1, nullptr), terrain(t) {}

void CollisionTestTerrainCommand::Execute()
{
	const CollisionGroup::CollisionComponentList& collection =
		group1->GetCollisionComponentList();
	for (auto it = collection.begin(); it != collection.end(); it++) {
		BSphere s((*it)->GetDefaultSphere());
		TerrainRect rect = terrain->GetCellsBelow(s);
		bool done = false;
		for (TerrainRectIterator tri = rect.begin(); tri != rect.end()
			&& !done; ++tri) {
			if (MathTools::Intersect(s, tri->getBox())) {
				if (MathTools::Intersect((*it)->GetVolume(), tri->getBox())) {
					CollisionAttorney::CollisionTerrain(*it, terrain);
					done = true;
				}
			}
		}
	}
}
