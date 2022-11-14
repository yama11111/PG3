#include <stdio.h>
#include "BookLoanHistory.h"

int main()
{
	BookLoanHistory* historys = new BookLoanHistory;

	BookLoanHistory history, history2;
	history.Initialize("山田太郎", 20221031, 20221107);
	history2.Initialize("田中武", 20221111, 20221118);

	historys->PushBack(history);
	historys->PushBack(history2);

	historys->Draw();

	delete historys;
	return 0;
}
