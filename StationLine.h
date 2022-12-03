#pragma once

class StationLine
{
public:
	// �w�\����
	struct Station
	{
		const char* name_ = nullptr; // ���O
	};
private:
	// �Z���\����
	struct Cell 
	{
		Station station_;
		Cell* prev_ = nullptr; // �O�̃Z��
		Cell* next_ = nullptr; // ���̃Z��
	};
public:
	// �擪�Z��
	Cell* head_ = nullptr;
	// �Ō���Z��
	Cell* end_ = nullptr;
	// �Z����
	size_t size_ = 0;
public:
	// ������
	void Initialize();
	// �Ō���ɒǉ�
	void PushBack(const Station& station);
	// �}��
	void Insert(const Station& station, const size_t itr);
	// �S����
	void Clear();
	// ���`��
	void DrawUp();
	// ����`��
	void DrawDown();
private:
	// �Z���̒��g�`�� (����)
	static void DrawCellPrev(Cell* cells);
	// �Z���̒��g�`�� (�O��)
	static void DrawCellNext(Cell* cells);
public:
	// �f�X�g���N�^
	~StationLine();
};

