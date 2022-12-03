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

	// �}������Z��
	Cell* newCell = new Cell();
	newCell->station_ = station;

	// �擪�� nullptr �Ȃ� ���̂܂ܑ}��
	if (head_ == nullptr)
	{
		head_ = newCell;
		end_ = newCell;
		return;
	}

	// end - newCell �ɂȂ�悤��
	end_->next_ = newCell;
	newCell->prev_ = end_;

	// �I�[�ɒǉ�
	end_ = newCell;
}

void StationLine::Insert(const Station& station, const size_t itr)
{
	// itr �� size_ ���傫���Ȃ�Ō���ɒǉ�
	if (itr >= size_)
	{
		PushBack(station);
		return;
	}

	size_++;

	// �}������Z��
	Cell* newCell = new Cell();
	newCell->station_ = station;

	// �Z����itr�Ԗڂ܂�
	Cell* current = head_;
	for (size_t i = 0; i < itr; i++)
	{
		// ���̃Z����
		current = current->next_;
	}

	// current - newCell - current->next �ɂȂ�悤��
	newCell->prev_ = current->prev_;
	current->prev_->next_ = newCell;
	newCell->next_ = current;
	current->prev_ = newCell;

	// 0�Ԗڂɑ}���������̂ݐ擪�Z���ɑ��
	if (itr == 0) { head_ = newCell; }
}

void StationLine::Clear()
{
	size_ = 0;
	
	if (head_ == nullptr) { return; }

	// �Z���̏I�[�܂ō폜
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

	// �O�̃Z���� nullptr ����Ȃ��Ȃ������x�`��
	if (cell->prev_) { DrawCellPrev(cell->prev_); }
}

void StationLine::DrawCellNext(Cell* cell)
{
	printf("%s\n", cell->station_.name_);
	
	// ���̃Z���� nullptr ����Ȃ��Ȃ������x�`��
	if (cell->next_) { DrawCellNext(cell->next_); }
}

StationLine::~StationLine()
{
	Clear();
}
