#include <stdio.h>
#include <cstdlib>
#include "ListManager.h"

int main()
{
	ListManager listMan_;
	listMan_.Initialize(); // ������

	while (true)
	{
		listMan_.Update(); // �X�V
		listMan_.Draw();   // �`��

		// �I������
		if (listMan_.isEnd()) { break; }
	}

	system("PAUSE");
	return 0;
}
