#pragma once

class List
{
private:
	// �Z���\����
	struct Cell
	{
		int val_ = int(); // �l
		Cell* prev_ = nullptr; // �O
		Cell* next_ = nullptr; // ��
	};
private:
	// �Z��
	Cell* cells_ = nullptr;
	// �Z����
	size_t size_ = 0;
public:
	// �I�[�ɒǉ�
	void PushBack(int val);
	// �}��
	void Insert(int val, size_t itr);
	// �폜
	void Delete(size_t itr);
	// �S����
	void Clear();
public:
	// �Z�����擾
	size_t Size() const { return size_; }
public:
	~List();
public:
	int& operator[] (size_t itr);
};

