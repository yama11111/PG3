#pragma once

struct BookLoanHistory
{
public:
	char name_[16]; // ����
	unsigned int borrowDay_ = 0; // �ݏo��
	unsigned int returnDay_ = 0; // �ԋp��
	BookLoanHistory* next_ = nullptr; // ���̃Z��
public:
	void Initialize(const char* name, unsigned int borrowDay, unsigned int returnDay);
	void PushBack(const BookLoanHistory& next);
	void Draw();
};

