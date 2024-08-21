#ifndef SceneChangeAttorney_H
#define SceneChangeAttorney_H

#include "SceneManager.h"

class SceneChangeAttorney {
public:
	class Commands {
		friend class SceneChangeCommand;
		friend class NullSceneCommand;
	private:
		static void ChangeScene(Scene* s) { SceneManager::ChangeScene(s); }
		static void SetScene(Scene* s) { SceneManager::PrivSetNextScene(s); }
	};

	class Engine {
		friend class Rivet;
	private:
		static void ChangeScene() { SceneManager::ExecuteSceneChange(); }
	};
};

#endif
