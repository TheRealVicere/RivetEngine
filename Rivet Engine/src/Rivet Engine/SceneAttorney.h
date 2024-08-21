#ifndef SceneAttorney_H
#define SceneAttorney_H

#include "Scene.h"
#include "SceneManager.h"

class Command;

class SceneAttorney {
public:
	class Commands {
		friend class CollisionComponent;
		friend class Component;

	private:
		static void SubmitCommand(Command* c) {
			SceneManager::GetCurrent()->SubmitCommand(c); }
	};

	class UpdateRegistry {
		friend class UpdateComponent;
	private:
		static UpdateManager::StorageListRef Register(UpdateComponent* up) {
			return SceneManager::GetCurrent()->Register(up);
		}
		static void Deregister(UpdateComponent* up) {
			SceneManager::GetCurrent()->Deregister(up);
		}
	};

	class DrawRegistry {
		friend class DrawComponent;
	private:
		static DrawManager::StorageListRef Register(DrawComponent* dr) {
			return SceneManager::GetCurrent()->Register(dr);
		}
		static void Deregister(DrawComponent* dr) {
			SceneManager::GetCurrent()->Deregister(dr);
		}
	};

	class AlarmRegistry {
		friend class AlarmComponent;
	private:
		static AlarmManager::TimelineRef Register(AlarmComponent* al) {
			return SceneManager::GetCurrent()->Register(al);
		}
		static void Deregister(AlarmComponent* al) {
			SceneManager::GetCurrent()->Deregister(al);
		}
	};

	class InputRegistry {
		friend class InputComponent;
	private:
		static KeyboardManager::InputListRef Register(InputComponent* i) {
			return SceneManager::GetCurrent()->Register(i);
		}
		static void Deregister(InputComponent* i) {
			SceneManager::GetCurrent()->Deregister(i);
		}
	};

	class SpawnRegistry {
		friend class SpawnComponent;
	private:
		static Scene::SpawnListRef Register(SpawnComponent* sp) {
			return SceneManager::GetCurrent()->Register(sp);
		}
		static void Deregister(SpawnComponent* go) {
			SceneManager::GetCurrent()->Deregister(go);
		}
	};

	class CollisionRegistry {
		friend class CollisionComponent;
	private:
		static CollisionManager* GetCollisionManager() {
			return &SceneManager::GetCurrent()->colMan;
		}
	};
};

#endif
