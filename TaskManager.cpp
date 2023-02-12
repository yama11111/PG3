#include "TaskManager.h"
#include <cassert>

#pragma region Task

// 新規タスク作成
size_t TaskManager::CreateTask(const size_t repIndex, const char title[64], const char content[256], const Task::Priority& priority)
{
	// Nullチェック
	assert(reps_.empty() == false);
	assert(title);
	assert(content);

	// 範囲チェック
	assert(0 <= repIndex && repIndex < reps_.size());

	// 新規タスク
	std::unique_ptr<Task> newTask = std::make_unique<Task>();

	newTask->id_ = static_cast<unsigned int>(tasks_.size());
	newTask->rep_ = *reps_[repIndex];
	newTask->SetTitle(title);
	newTask->SetContent(content);
	newTask->SetPriority(priority);

	// 最後尾に挿入
	tasks_.push_back(std::move(newTask));

	// 要素番号を返す
	return tasks_.size() - 1;
}

// タスク内容設定
void TaskManager::SetTaskContent(const size_t index, const char content[256])
{
	// Nullチェック
	assert(tasks_.empty() == false);
	assert(content);
	
	// 範囲チェック
	assert(0 <= index && index < tasks_.size());

	tasks_[index]->SetContent(content);
}

// タスク完了設定
void TaskManager::SetTaskIsCompleted(const size_t index, const bool isCompleted)
{
	// Nullチェック
	assert(tasks_.empty() == false);
	
	// 範囲チェック
	assert(0 <= index && index < tasks_.size());

	tasks_[index]->isCompleted_ = isCompleted;
}

// タスク優先度設定
void TaskManager::SetTaskPriority(const size_t index, const Task::Priority& priority)
{
	// Nullチェック
	assert(tasks_.empty() == false);

	// 範囲チェック
	assert(0 <= index && index < tasks_.size());

	tasks_[index]->SetPriority(priority);
}

#pragma endregion

#pragma region Rep

// 新規担当者作成
size_t TaskManager::CreateRep(const char name[32], const Rep::StudentNumber& stuNum)
{
	// Nullチェック
	assert(name);

	// 新規担当者
	std::unique_ptr<Rep> newRep = std::make_unique<Rep>();

	newRep->id_ = static_cast<unsigned int>(reps_.size());
	newRep->SetName(name);
	newRep->SetStudentNumber(stuNum);

	// 最後尾に挿入
	reps_.push_back(std::move(newRep));

	// 要素番号を返す
	return reps_.size() - 1;
}

// 担当者名設定
void TaskManager::SetRepName(const size_t index, const char name[32])
{
	// Nullチェック
	assert(reps_.empty() == false);
	assert(name);

	// 範囲チェック
	assert(0 <= index && index < tasks_.size());

	reps_[index]->SetName(name);
}

// 担当者学籍番号設定
void TaskManager::SetRepStudentNumber(const size_t index, const Rep::StudentNumber& stuNum)
{
	// Nullチェック
	assert(reps_.empty() == false);

	// 範囲チェック
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
