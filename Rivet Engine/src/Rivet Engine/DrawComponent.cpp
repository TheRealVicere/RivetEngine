#include "DrawComponent.h"

#include "IDrawCallback.h"
#include "SceneAttorney.h"

void DrawComponent::OnRegistration()
{
	ref = SceneAttorney::DrawRegistry::Register(this);
}

void DrawComponent::OnDeregistration()
{
	SceneAttorney::DrawRegistry::Deregister(this);
}

void DrawComponent::Draw()
{
	callback->Draw();
}

void DrawComponent::Draw2D()
{
	callback->Draw2D();
}

DrawComponent::DrawComponent(IDrawCallback* cb)
{
	assert(("Callback cannot be null!", cb));
	callback = cb;
}

DrawManager::StorageListRef& DrawComponent::GetStorageListRef()
{
	return ref;
}
