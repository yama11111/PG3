#include "BookLoanHistory.h"
#include <string>

void BookLoanHistory::Initialize(const char* name, unsigned int borrowDay, unsigned int returnDay)
{
	strcpy_s(name_, 16, name);
	borrowDay_ = borrowDay;
	returnDay_ = returnDay;
}

void BookLoanHistory::PushBack(const BookLoanHistory& next)
{
	// 挿入するセル
	BookLoanHistory* newCell = new BookLoanHistory;
	newCell->Initialize(next.name_, next.borrowDay_, next.returnDay_);

	// 最後尾のポインタ
	if (next_ != nullptr)
	{
		if (next_->next_ != nullptr)
		{

		}
		else
		{
			next_->next_ = newCell;
		}
	}
	else
	{
		next_ = newCell;
	}
}

void BookLoanHistory::Draw()
{
	printf("--------------------\n");
	printf("氏名 : %s\n", name_);
	printf("貸出日 : %d\n", borrowDay_);
	printf("返却日 : %d\n", returnDay_);
	printf("--------------------\n");

	if (next_) { next_->Draw(); }
}
