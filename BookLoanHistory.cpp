#include "BookLoanHistory.h"
#include <stdio.h>

void BookLoanHistory::Initialize()
{
	Clear();

}

void BookLoanHistory::PushBack(const Status& state)
{
	// 挿入するセル
	Cell* newCell = new Cell();
	newCell->state_ = state;

	// 先頭が nullptr なら そのまま挿入
	if (cells_ == nullptr)
	{
		cells_ = newCell;
		return;
	}

	// セルの終端まで
	Cell* current = cells_;
	while (true)
	{
		// 次が終端なら
		if (current->next_ == nullptr)
		{
			current->next_ = newCell;
			break;
		}
		// 次のセルへ
		current = current->next_;
	}

	size_++;
}

void BookLoanHistory::Clear()
{
	if (cells_ == nullptr) { return; }

	// セルの終端まで削除
	Cell* current = cells_;
	while (true)
	{
		if (current == nullptr) { break; }
		Cell* del = current;
		current = current->next_;
		delete del;
	}

	size_ = 0;
}

void BookLoanHistory::Draw()
{
	DrawCell(cells_);
}

void BookLoanHistory::DrawCell(Cell* cell)
{
	printf("--------------------\n");
	printf("氏名   : %s\n", cell->state_.name_);
	printf("貸出日 : %d\n", cell->state_.borrowDay_);
	printf("返却日 : %d\n", cell->state_.returnDay_);
	printf("--------------------\n");

	// 次のセルが nullptr じゃないならもう一度描画
	if (cell->next_) { DrawCell(cell->next_); }
}

BookLoanHistory::~BookLoanHistory()
{
	Clear();
}
