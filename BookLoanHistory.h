#pragma once

struct BookLoanHistory
{
public:
	char name_[16]; // –¼
	unsigned int borrowDay_ = 0; // ‘İo“ú
	unsigned int returnDay_ = 0; // •Ô‹p“ú
	BookLoanHistory* next_ = nullptr; // Ÿ‚ÌƒZƒ‹
public:
	void Initialize(const char* name, unsigned int borrowDay, unsigned int returnDay);
	void PushBack(const BookLoanHistory& next);
	void Draw();
};

