#include <stdio.h>
#include <cstdlib>
#include "SceneManager.h"

int main()
{
	SceneManager* sceneMan = SceneManager::GetInstance();
	int receipt = 0;

	for (size_t i = 0; i < 3; i++)
	{
		printf_s("”Žš‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
		printf_s("1 : Title, 2 : NewGame, 3 : GamePlay, 4 : GameClear\n");
		scanf_s("%d", &receipt);

		switch (receipt)
		{
		case 1:
			sceneMan->Change(Scene::Title);
			sceneMan->DrawCurrent();
			sceneMan->DrawNext();
			break;
		case 2:
			sceneMan->Change(Scene::NewPlay);
			sceneMan->DrawCurrent();
			sceneMan->DrawNext();
			break;
		case 3:
			sceneMan->Change(Scene::GamePlay);
			sceneMan->DrawCurrent();
			sceneMan->DrawNext();
			break;
		case 4:
			sceneMan->Change(Scene::GameClear);
			sceneMan->DrawCurrent();
			sceneMan->DrawNext();
			break;
		default:
			break;
		}
	}

	system("PAUSE");

	return 0;
}