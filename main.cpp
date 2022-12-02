#include <stdio.h>
#include <cstdlib>
#include "ListManager.h"

int main()
{
	ListManager listMan_;
	listMan_.Initialize(); // ‰Šú‰»

	while (true)
	{
		listMan_.Update(); // XV
		listMan_.Draw();   // •`‰æ

		// I—¹ˆ—
		if (listMan_.isEnd()) { break; }
	}

	system("PAUSE");
	return 0;
}
