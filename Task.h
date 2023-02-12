#pragma once
#include "Rep.h"

// �^�X�N
struct Task
{
public:
	// �D��x
	enum class Priority
	{
		None,
		High,	 // ��
		Normal,	 // ����
		Low,	 // ��
	};
public:
	// ID
	unsigned int id_ = 0;
	// �S����
	Rep rep_{};
	// �薼
	char title_[64]{};
	// ���e
	char content_[256]{};
	// �D��x
	char priority_[16]{};
	// ����������
	bool isCompleted_ = false;
public:
	// �薼�ݒ�
	void SetTitle(const char title[64]);
	// ���e�ݒ�
	void SetContent(const char content[256]);
	// �D��x�ݒ�
	void SetPriority(const Priority& priority);
	// �`��
	void Draw();
public:
	// �R���X�g���N�^
	Task() :
		id_(0), rep_(), title_(""), content_(""), priority_(""), isCompleted_(false)
	{}
	// �f�X�g���N�^
	~Task() = default;
};