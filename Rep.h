#pragma once

// �S����
struct Rep
{
public:
	// �w�Дԍ�
	enum class StudentNumber
	{
		None,
		LE2A,
		LE2B,
	};
public:
	// ID
	unsigned int id_ = 0;
	// ���O
	char name_[32]{};
	// �w�Дԍ�
	char stuNum_[32]{};
public:
	// ���O�ݒ�
	void SetName(const char name[32]);
	// �w�Дԍ��ݒ�
	void SetStudentNumber(const StudentNumber& stuNum);
	// �`��
	void Draw();
public:
	// �R���X�g���N�^
	Rep() :
		id_(0), name_(""), stuNum_("")
	{}
	// �f�X�g���N�^
	~Rep() = default;
};

