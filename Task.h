#pragma once
#include "Rep.h"

// �^�X�N
struct Task
{
public:
	// ID
	unsigned int id_;
	// �S����
	Rep rep_;
	// �薼
	char title_[64];
	// ���e
	char content_[256];
	// �D��x
	unsigned short priority_;
	// ����������
	bool isCompleted_;
public:
	// �薼�ݒ�
	void SetTitle(const char title[64]);
	// ���e�ݒ�
	void SetContent(const char content[256]);
	// �`��
	void Draw();
public:
	// �R���X�g���N�^
	Task() :
		id_(0), rep_(), title_(""), priority_(0), isCompleted_(false)
	{}
};