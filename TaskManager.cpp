#include "TaskManager.h"
#include <cassert>

#pragma region Task

// �V�K�^�X�N�쐬
size_t TaskManager::CreateTask(const Rep& rep, const char title[64], const char content[256], unsigned short priority)
{
	// Null�`�F�b�N
	assert(title);
	assert(content);

	// �V�K�^�X�N
	std::unique_ptr<Task> newTask = std::make_unique<Task>();

	newTask->id_ = tasks_.size();
	newTask->rep_ = rep;
	newTask->SetTitle(title);
	newTask->SetContent(content);
	newTask->priority_ = priority;

	// �Ō���ɑ}��
	tasks_.push_back(newTask);

	// �v�f�ԍ���Ԃ�
	return tasks_.size() - 1;
}

// �^�X�N���e�ݒ�
void TaskManager::SetTaskContent(const size_t index, const char content[256])
{
	// �͈̓`�F�b�N
	assert(0 <= index && index < tasks_.size());

	// Null�`�F�b�N
	assert(content);

	tasks_[index]->SetContent(content);
}

// �^�X�N�����ݒ�
void TaskManager::SetTaskIsCompleted(const size_t index, const bool isCompleted)
{
	// �͈̓`�F�b�N
	assert(0 <= index && index < tasks_.size());

	tasks_[index]->isCompleted_ = isCompleted;
}

#pragma endregion

#pragma region Rep

// �V�K�S���ҍ쐬
size_t TaskManager::CreateRep(const char name[32], const StudentNumber& stuNum)
{
	// Null�`�F�b�N
	assert(name);

	// �V�K�S����
	std::unique_ptr<Rep> newRep = std::make_unique<Rep>();

	newRep->id_ = reps_.size();
	newRep->SetName(name);
	newRep->stuNum_ = stuNum;

	// �Ō���ɑ}��
	reps_.push_back(newRep);

	// �v�f�ԍ���Ԃ�
	return reps_.size() - 1;
}

// �S���Җ��ݒ�
void TaskManager::SetRepName(const size_t index, const char name[32])
{
	// �͈̓`�F�b�N
	assert(0 <= index && index < tasks_.size());

	// Null�`�F�b�N
	assert(name);

	reps_[index]->SetName(name);
}

// �S���Ҋw�Дԍ��ݒ�
void TaskManager::SetRepStudentNumber(const size_t index, const StudentNumber& stuNum)
{
	// �͈̓`�F�b�N
	assert(0 <= index && index < tasks_.size());

	reps_[index]->stuNum_ = stuNum;
}

#pragma endregion
void TaskManager::Draw()
{

}
