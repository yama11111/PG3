#include "List.h"
#include <cassert>

void List::PushBack(int val)
{
	// 新規セル作成
	Cell* newCell = new Cell();
	newCell->val_ = val;
	
	if (cells_ == nullptr)
	{
		cells_ = newCell;
	}
	else
	{
		// セルの終端まで
		Cell* current = cells_;
		while (true)
		{
			newCell->prev_ = current;
			// 次が終端じゃないなら
			if (current->next_)
			{
				current = current->next_;
			}
			else
			{
				current->next_ = newCell;
				break;
			}
		}
	}

	size_++;
}

void List::Insert(int val, size_t itr)
{
	// itr が size より大きいとき警告
	assert(size_ >= itr);

	// 新規セル作成
	Cell* newCell = new Cell();
	newCell->val_ = val;

	if (cells_ == nullptr)
	{
		cells_ = newCell;
	}
	else if (itr == 0)
	{
		// newCell が先頭になるように
		Cell* second = cells_;
		cells_ = newCell;
		cells_->next_ = second;
		second->prev_ = cells_;
	}
	else
	{
		// セルのitr番目まで
		Cell* current = cells_;
		for (size_t i = 0; i < itr + 1; i++)
		{
			// current - newCell - current->next になるように
			newCell->prev_ = current;
			newCell->next_ = current->next_;
			// 次が終端じゃないなら
			if (current->next_)
			{
				current = current->next_;
			}
			else
			{
				current->next_ = newCell;
				break;
			}
		}
	}

	size_++;
}

void List::Delete(size_t itr)
{
	// size が 0 か、itr が (size - 1) より大きいとき警告
	assert((size_ != 0) || ((size_ - 1) >= itr));

	// セルのitr番目まで
	Cell* current = cells_;
	for (size_t i = 0; i < itr; i++)
	{
		current = current->next_;
	}

	// current->prev - current->next になるように
	if (current->prev_)
	{
		current->prev_->next_ = current->next_;
	}
	if (current->next_)
	{
		current->next_->prev_ = current->prev_;
	}

	delete current;

	size_--;
}

void List::Clear()
{
	if (cells_ == nullptr) { return; }

	Cell* next = cells_->next_;

	// セルの先頭を削除
	delete cells_;

	// セルの終端まで削除
	while (true)
	{
		if (next == nullptr) { break; }
		Cell* del = next;
		next = next->next_;
		delete del;
	}
}

List::~List()
{
	Clear();
}

int& List::operator[](size_t itr)
{
	// itr が size より大きいとき警告
	assert(size_ >= itr);

	// セルのitr番目まで
	Cell* result = cells_;
	for (size_t i = 0; i < itr; i++)
	{
		result = result->next_;
	}
	return result->val_;
}
