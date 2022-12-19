#include <stdio.h>
#include <cstdlib>
#include "Scene.h"

int main()
{
	IScene* scene = nullptr;
	scene = new TitleScene();

	bool isEnd = false;

	while (true)
	{
		scene->Update();
		scene->Draw();


		// ƒV[ƒ“Ø‚è‘Ö‚¦
		if (scene->GetIsInput()) 
		{
			int num = scene->GetInputNum();
			
			switch (num)
			{
			case 0:
				delete scene;
				scene = new TitleScene();
				break;
			case 1:
				delete scene;
				scene = new GameScene();
				break;
			case 2:
				delete scene;
				scene = new GameOverScene();
				break;
			case 3:
				delete scene;
				scene = new ClearScene();
				break;
			case 9:
				isEnd = true;
				break;
			}
		}

		if (isEnd) { break; }
	}

	delete scene;

	system("PAUSE");
	return 0;
}