#include <stdio.h>
#include <cstdlib>
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

	system("PAUSE");

	return 0;
}