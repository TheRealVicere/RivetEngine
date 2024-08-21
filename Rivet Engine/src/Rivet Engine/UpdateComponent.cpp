#include "UpdateComponent.h"

#include "IUpdateCallback.h"
#include "SceneAttorney.h"

void UpdateComponent::OnRegistration()
{
	ref = SceneAttorney::UpdateRegistry::Register(this);
}

void UpdateComponent::OnDeregistration()
{
	SceneAttorney::UpdateRegistry::Deregister(this);
}

void UpdateComponent::Update()
{
	callback->Update();
}

UpdateComponent::UpdateComponent(IUpdateCallback* cb)
{
	assert(("Callback cannot be null!", cb));
	callback = cb;
}

UpdateManager::StorageListRef& UpdateComponent::GetStorageListRef()
{
	return ref;
}
