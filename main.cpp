#include <stdio.h>
#include <cstdlib>
#include "ListManager.h"

int main()
{
	ListManager listMan_;
	listMan_.Initialize(); // 初期化

	while (true)
	{
		listMan_.Update(); // 更新
		listMan_.Draw();   // 描画

		// 終了処理
		if (listMan_.isEnd()) { break; }
	}

	system("PAUSE");
	return 0;
}
