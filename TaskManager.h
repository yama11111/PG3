#pragma once
#include "Task.h"
#include <vector>
#include <memory>

// �^�X�N�}�l�[�W���[
class TaskManager
{
private:
	// �^�X�N
	std::vector<std::unique_ptr<Task>> tasks_;
	// �S����
	std::vector<std::unique_ptr<Rep>> reps_;
public:
	// �V�K�^�X�N�쐬
	size_t CreateTask(const Rep& rep, const char title[64], const char content[256],unsigned short priority);
	// �^�X�N���e�ݒ�
	void SetTaskContent(const size_t index, const char content[256]);
	// �^�X�N�����ݒ�
	void SetTaskIsCompleted(const size_t index, const bool isCompleted);
public:
	// �V�K�S���ҍ쐬
	size_t CreateRep(const char name[32], const StudentNumber& stuNum);
	// �S���Җ��ݒ�
	void SetRepName(const size_t index, const char name[32]);
	// �S���Ҋw�Дԍ��ݒ�
	void SetRepStudentNumber(const size_t index, const StudentNumber& stuNum);
public:
	// �`��
	void Draw();
};

