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
	size_t CreateTask(const size_t repIndex, const char title[64], const char content[256], const Task::Priority& priority);
	// �^�X�N���e�ݒ�
	void SetTaskContent(const size_t index, const char content[256]);
	// �^�X�N�����ݒ�
	void SetTaskIsCompleted(const size_t index, const bool isCompleted);
	// �^�X�N�D��x�ݒ�
	void SetTaskPriority(const size_t index, const Task::Priority& priority);
public:
	// �V�K�S���ҍ쐬
	size_t CreateRep(const char name[32], const Rep::StudentNumber& stuNum);
	// �S���Җ��ݒ�
	void SetRepName(const size_t index, const char name[32]);
	// �S���Ҋw�Дԍ��ݒ�
	void SetRepStudentNumber(const size_t index, const Rep::StudentNumber& stuNum);
public:
	// �`��
	void Draw();
	// �^�X�N�`��
	void DrawTasks();
	// �S���ҕ`��
	void DrawReps();
};

