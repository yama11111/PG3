#include <stdio.h>
#include <cstdlib>
#include "BookLoanHistory.h"

int main()
{
	BookLoanHistory history;
	history.Initialize();

	history.PushBack({ "�R�c���Y", 20221031, 20221107 });
	history.PushBack({ "�c����", 20221111, 20221118 });

	history.Draw();

	system("PAUSE");
	return 0;
}
