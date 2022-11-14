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
	// �}������Z��
	BookLoanHistory* newCell = new BookLoanHistory;
	newCell->Initialize(next.name_, next.borrowDay_, next.returnDay_);

	// �Ō���̃|�C���^
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
	printf("���� : %s\n", name_);
	printf("�ݏo�� : %d\n", borrowDay_);
	printf("�ԋp�� : %d\n", returnDay_);
	printf("--------------------\n");

	if (next_) { next_->Draw(); }
}
