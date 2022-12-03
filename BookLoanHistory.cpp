#include "BookLoanHistory.h"
#include <stdio.h>

void BookLoanHistory::Initialize()
{
	Clear();

}

void BookLoanHistory::PushBack(const Status& state)
{
	// �}������Z��
	Cell* newCell = new Cell();
	newCell->state_ = state;

	// �擪�� nullptr �Ȃ� ���̂܂ܑ}��
	if (cells_ == nullptr)
	{
		cells_ = newCell;
		return;
	}

	// �Z���̏I�[�܂�
	Cell* current = cells_;
	while (true)
	{
		// �����I�[�Ȃ�
		if (current->next_ == nullptr)
		{
			current->next_ = newCell;
			break;
		}
		// ���̃Z����
		current = current->next_;
	}

	size_++;
}

void BookLoanHistory::Clear()
{
	if (cells_ == nullptr) { return; }

	// �Z���̏I�[�܂ō폜
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
	printf("����   : %s\n", cell->state_.name_);
	printf("�ݏo�� : %d\n", cell->state_.borrowDay_);
	printf("�ԋp�� : %d\n", cell->state_.returnDay_);
	printf("--------------------\n");

	// ���̃Z���� nullptr ����Ȃ��Ȃ������x�`��
	if (cell->next_) { DrawCell(cell->next_); }
}

BookLoanHistory::~BookLoanHistory()
{
	Clear();
}
