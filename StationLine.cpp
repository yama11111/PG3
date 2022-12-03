#include "StationLine.h"
#include <stdio.h>

void StationLine::Initialize()
{
	Clear();
	head_ = nullptr;
	end_ = nullptr;
}

void StationLine::PushBack(const Station& station)
{
	size_++;

	// 挿入するセル
	Cell* newCell = new Cell();
	newCell->station_ = station;

	// 先頭が nullptr なら そのまま挿入
	if (head_ == nullptr)
	{
		head_ = newCell;
		end_ = newCell;
		return;
	}

	// end - newCell になるように
	end_->next_ = newCell;
	newCell->prev_ = end_;

	// 終端に追加
	end_ = newCell;
}

void StationLine::Insert(const Station& station, const size_t itr)
{
	// itr が size_ より大きいなら最後尾に追加
	if (itr >= size_)
	{
		PushBack(station);
		return;
	}

	size_++;

	// 挿入するセル
	Cell* newCell = new Cell();
	newCell->station_ = station;

	// セルのitr番目まで
	Cell* current = head_;
	for (size_t i = 0; i < itr; i++)
	{
		// 次のセルへ
		current = current->next_;
	}

	// current - newCell - current->next になるように
	newCell->prev_ = current->prev_;
	current->prev_->next_ = newCell;
	newCell->next_ = current;
	current->prev_ = newCell;

	// 0番目に挿入した時のみ先頭セルに代入
	if (itr == 0) { head_ = newCell; }
}

void StationLine::Clear()
{
	size_ = 0;
	
	if (head_ == nullptr) { return; }

	// セルの終端まで削除
	Cell* current = head_;
	while (true)
	{
		if (current == nullptr) { break; }
		Cell* del = current;
		current = current->next_;
		delete del;
	}
}

void StationLine::DrawUp()
{
	printf("-------- UP --------\n");
	DrawCellNext(head_);
	printf("--------------------\n");
}

void StationLine::DrawDown()
{
	printf("------- DOWN -------\n");
	DrawCellPrev(end_);
	printf("--------------------\n");
}

void StationLine::DrawCellPrev(Cell* cell) 
{
	printf("%s\n", cell->station_.name_);

	// 前のセルが nullptr じゃないならもう一度描画
	if (cell->prev_) { DrawCellPrev(cell->prev_); }
}

void StationLine::DrawCellNext(Cell* cell)
{
	printf("%s\n", cell->station_.name_);
	
	// 次のセルが nullptr じゃないならもう一度描画
	if (cell->next_) { DrawCellNext(cell->next_); }
}

StationLine::~StationLine()
{
	Clear();
}
