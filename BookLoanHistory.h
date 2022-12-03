#pragma once

class BookLoanHistory
{
public:
	// �X�e�[�^�X
	struct Status
	{
		const char* name_ = nullptr; // ����
		unsigned int borrowDay_ = 0; // �ݏo��
		unsigned int returnDay_ = 0; // �ԋp��
	};
private:
	// �Z���\����
	struct Cell 
	{
		Status state_;
		Cell* next_ = nullptr; // ���̃Z��
	};
public:
	// �Z��
	Cell* cells_ = nullptr;
	// �Z����
	size_t size_ = 0;
public:
	// ������
	void Initialize();
	// �Ō���ɒǉ�
	void PushBack(const Status& state);
	// �S����
	void Clear();
	// �`��
	void Draw();
private:
	// �Z���̒��g�`��
	static void DrawCell(Cell* cells);
public:
	// �f�X�g���N�^
	~BookLoanHistory();
};

