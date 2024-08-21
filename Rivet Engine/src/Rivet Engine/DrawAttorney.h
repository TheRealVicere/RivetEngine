#ifndef DrawAttorney_H
#define DrawAttorney_H

#include "DrawComponent.h"

class DrawAttorney {
private:
	friend class DrawManager;

	static void Draw(DrawComponent* d) { d->Draw(); }
	static void Draw2D(DrawComponent* d) { d->Draw2D(); }
	static DrawManager::StorageListRef GetStorageListRef(DrawComponent* d) {
		return d->GetStorageListRef();
	}
};

#endif
