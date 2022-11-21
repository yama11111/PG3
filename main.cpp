#include <stdio.h>
#include "SceneManager.h"

int main()
{
	SceneManager* sceneMan = SceneManager::GetInstance();

	sceneMan->DrawNext();
	sceneMan->Change(Scene::NewPlay);

	sceneMan->DrawNext();
	sceneMan->Change(Scene::GamePlay);

	sceneMan->DrawNext();
	sceneMan->Change(Scene::GameClear);

	sceneMan->DrawNext();

	return 0;
}