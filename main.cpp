#include <stdio.h>
#include <cstdlib>
#include "Enemy.h"

int main()
{
	const size_t EnemyNum= 5;
	Enemy enemys[EnemyNum]{};
	for (size_t i = 0; i < EnemyNum; i++)
	{
		enemys[i].Initialize();
	}

	while (true)
	{
		system("cls");

		for (int i = 0; i < EnemyNum; i++)
		{
			// 敵がいないなら 更新+描画 しない
			if (Enemy::IsDeath()) { break; }

			enemys[i].Update();
			printf("Enemy : %d\n", i);
			enemys[i].Draw();
		}

		printf("------------------\n");
		printf("1 : 攻撃する\n");
		printf("2 : 終わる\n");

		int receiver = 0;
		scanf_s("%d", &receiver);

		if (receiver == 1) // 攻撃
		{
			enemys[0].Hit(2);
		}
		else if (receiver == 2) // ループを抜ける
		{
			break;
		}
	}


	system("PAUSE");
	return 0;
}