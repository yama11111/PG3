#pragma once

// �w�Дԍ�
enum class StudentNumber
{
	None,
	LE2A,
	LE2B,
};

// �S����
struct Rep
{
public:
	// ID
	unsigned int id_;
	// ���O
	char name_[32];
	// �w�Дԍ�
	StudentNumber stuNum_;
public:
	// ���O�ݒ�
	void SetName(const char name[32]);
	// �`��
	void Draw();
public:
	// �R���X�g���N�^
	Rep() :
		id_(0), name_(""), stuNum_(StudentNumber::None)
	{}
};

