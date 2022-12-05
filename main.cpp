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
			// �G�����Ȃ��Ȃ� �X�V+�`�� ���Ȃ�
			if (Enemy::IsDeath()) { break; }

			enemys[i].Update();
			printf("Enemy : %d\n", i);
			enemys[i].Draw();
		}

		printf("------------------\n");
		printf("1 : �U������\n");
		printf("2 : �I���\n");

		int receiver = 0;
		scanf_s("%d", &receiver);

		if (receiver == 1) // �U��
		{
			enemys[0].Hit(2);
		}
		else if (receiver == 2) // ���[�v�𔲂���
		{
			break;
		}
	}


	system("PAUSE");
	return 0;
}