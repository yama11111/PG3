#include "TaskManager.h"
#include <cassert>

#pragma region Task

// �V�K�^�X�N�쐬
size_t TaskManager::CreateTask(const size_t repIndex, const char title[64], const char content[256], const Task::Priority& priority)
{
	// Null�`�F�b�N
	assert(reps_.empty() == false);
	assert(title);
	assert(content);

	// �͈̓`�F�b�N
	assert(0 <= repIndex && repIndex < reps_.size());

	// �V�K�^�X�N
	std::unique_ptr<Task> newTask = std::make_unique<Task>();

	newTask->id_ = static_cast<unsigned int>(tasks_.size());
	newTask->rep_ = *reps_[repIndex];
	newTask->SetTitle(title);
	newTask->SetContent(content);
	newTask->SetPriority(priority);

	// �Ō���ɑ}��
	tasks_.push_back(std::move(newTask));

	// �v�f�ԍ���Ԃ�
	return tasks_.size() - 1;
}

// �^�X�N���e�ݒ�
void TaskManager::SetTaskContent(const size_t index, const char content[256])
{
	// Null�`�F�b�N
	assert(tasks_.empty() == false);
	assert(content);
	
	// �͈̓`�F�b�N
	assert(0 <= index && index < tasks_.size());

	tasks_[index]->SetContent(content);
}

// �^�X�N�����ݒ�
void TaskManager::SetTaskIsCompleted(const size_t index, const bool isCompleted)
{
	// Null�`�F�b�N
	assert(tasks_.empty() == false);
	
	// �͈̓`�F�b�N
	assert(0 <= index && index < tasks_.size());

	tasks_[index]->isCompleted_ = isCompleted;
}

// �^�X�N�D��x�ݒ�
void TaskManager::SetTaskPriority(const size_t index, const Task::Priority& priority)
{
	// Null�`�F�b�N
	assert(tasks_.empty() == false);

	// �͈̓`�F�b�N
	assert(0 <= index && index < tasks_.size());

	tasks_[index]->SetPriority(priority);
}

#pragma endregion

#pragma region Rep

// �V�K�S���ҍ쐬
size_t TaskManager::CreateRep(const char name[32], const Rep::StudentNumber& stuNum)
{
	// Null�`�F�b�N
	assert(name);

	// �V�K�S����
	std::unique_ptr<Rep> newRep = std::make_unique<Rep>();

	newRep->id_ = static_cast<unsigned int>(reps_.size());
	newRep->SetName(name);
	newRep->SetStudentNumber(stuNum);

	// �Ō���ɑ}��
	reps_.push_back(std::move(newRep));

	// �v�f�ԍ���Ԃ�
	return reps_.size() - 1;
}

// �S���Җ��ݒ�
void TaskManager::SetRepName(const size_t index, const char name[32])
{
	// Null�`�F�b�N
	assert(reps_.empty() == false);
	assert(name);

	// �͈̓`�F�b�N
	assert(0 <= index && index < tasks_.size());

	reps_[index]->SetName(name);
}

// �S���Ҋw�Дԍ��ݒ�
void TaskManager::SetRepStudentNumber(const size_t index, const Rep::StudentNumber& stuNum)
{
	// Null�`�F�b�N
	assert(reps_.empty() == false);

	// �͈̓`�F�b�N
	assert(0 <= index && index < tasks_.size());

	reps_[index]->SetStudentNumber(stuNum);
}

#pragma endregion

void TaskManager::Draw()
{
	DrawTasks();
	DrawReps();
}

void TaskManager::DrawTasks()
{
	for (size_t i = 0; i < tasks_.size(); i++)
	{
		tasks_[i]->Draw();
	}
}

void TaskManager::DrawReps()
{
	for (size_t i = 0; i < reps_.size(); i++)
	{
		reps_[i]->Draw();
	}
}
