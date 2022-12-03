#include <stdio.h>
#include "BookLoanHistory.h"

int main()
{
	BookLoanHistory history;
	history.Initialize();

	history.PushBack({ "山田太郎", 20221031, 20221107 });
	history.PushBack({ "田中武", 20221111, 20221118 });

	history.Draw();

	return 0;
}
