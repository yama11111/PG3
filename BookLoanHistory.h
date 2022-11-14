#pragma once

struct BookLoanHistory
{
public:
	char name_[16]; // 氏名
	unsigned int borrowDay_ = 0; // 貸出日
	unsigned int returnDay_ = 0; // 返却日
	BookLoanHistory* next_ = nullptr; // 次のセル
public:
	void Initialize(const char* name, unsigned int borrowDay, unsigned int returnDay);
	void PushBack(const BookLoanHistory& next);
	void Draw();
};

