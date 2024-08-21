#ifndef RegistryAttorney_H
#define RegistryAttorney_H

#include "Component.h"
#include "Scene.h"

class RegistryAttorney {
	friend class RegCommand;
	friend class DeregCommand;
private:
	static void Register(Component* c) { c->Register(); }
	static void Deregister(Component* c) { c->Deregister(); }
};

#endif
