#include "List.h"
#include <cassert>

void List::PushBack(int val)
{
	// �V�K�Z���쐬
	Cell* newCell = new Cell();
	newCell->val_ = val;
	
	if (cells_ == nullptr)
	{
		cells_ = newCell;
	}
	else
	{
		// �Z���̏I�[�܂�
		Cell* current = cells_;
		while (true)
		{
			newCell->prev_ = current;
			// �����I�[����Ȃ��Ȃ�
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
	// itr �� size ���傫���Ƃ��x��
	assert(size_ >= itr);

	// �V�K�Z���쐬
	Cell* newCell = new Cell();
	newCell->val_ = val;

	if (cells_ == nullptr)
	{
		cells_ = newCell;
	}
	else if (itr == 0)
	{
		// newCell ���擪�ɂȂ�悤��
		Cell* second = cells_;
		cells_ = newCell;
		cells_->next_ = second;
		second->prev_ = cells_;
	}
	else
	{
		// �Z����itr�Ԗڂ܂�
		Cell* current = cells_;
		for (size_t i = 0; i < itr + 1; i++)
		{
			// current - newCell - current->next �ɂȂ�悤��
			newCell->prev_ = current;
			newCell->next_ = current->next_;
			// �����I�[����Ȃ��Ȃ�
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
	// size �� 0 ���Aitr �� (size - 1) ���傫���Ƃ��x��
	assert((size_ != 0) || ((size_ - 1) >= itr));

	// �Z����itr�Ԗڂ܂�
	Cell* current = cells_;
	for (size_t i = 0; i < itr; i++)
	{
		current = current->next_;
	}

	// current->prev - current->next �ɂȂ�悤��
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

	// �Z���̐擪���폜
	delete cells_;

	// �Z���̏I�[�܂ō폜
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
	// itr �� size ���傫���Ƃ��x��
	assert(size_ >= itr);

	// �Z����itr�Ԗڂ܂�
	Cell* result = cells_;
	for (size_t i = 0; i < itr; i++)
	{
		result = result->next_;
	}
	return result->val_;
}
