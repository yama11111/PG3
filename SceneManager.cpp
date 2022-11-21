#include "SceneManager.h"
#include <stdio.h>

void SceneManager::Change(const Scene& scene)
{
	current_ = scene;
	switch (scene)
	{
	case Scene::Title:
		next_ = Scene::NewPlay;
		break;
	case Scene::NewPlay:
		next_ = Scene::GamePlay;
		break;
	case Scene::GamePlay:
		next_ = Scene::GameClear;
		break;
	case Scene::GameClear:
		next_ = Scene::Title;
		break;
	}
}

void SceneManager::DrawNext()
{
	switch (next_)
	{
	case Scene::Title:
		printf_s("NextScene : TItle\n");
		break;
	case Scene::NewPlay:
		printf_s("NextScene : NewPlay\n");
		break;
	case Scene::GamePlay:
		printf_s("NextScene : GamePlay\n");
		break;
	case Scene::GameClear:
		printf_s("NextScene : GameClear\n");
		break;
	}
}

SceneManager* SceneManager::GetInstance()
{
	static SceneManager instance;
	return &instance;
}
