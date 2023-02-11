#include "TaskManager.h"
#include <cassert>

#pragma region Task

// 新規タスク作成
size_t TaskManager::CreateTask(const Rep& rep, const char title[64], const char content[256], unsigned short priority)
{
	// Nullチェック
	assert(title);
	assert(content);

	// 新規タスク
	std::unique_ptr<Task> newTask = std::make_unique<Task>();

	newTask->id_ = tasks_.size();
	newTask->rep_ = rep;
	newTask->SetTitle(title);
	newTask->SetContent(content);
	newTask->priority_ = priority;

	// 最後尾に挿入
	tasks_.push_back(newTask);

	// 要素番号を返す
	return tasks_.size() - 1;
}

// タスク内容設定
void TaskManager::SetTaskContent(const size_t index, const char content[256])
{
	// 範囲チェック
	assert(0 <= index && index < tasks_.size());

	// Nullチェック
	assert(content);

	tasks_[index]->SetContent(content);
}

// タスク完了設定
void TaskManager::SetTaskIsCompleted(const size_t index, const bool isCompleted)
{
	// 範囲チェック
	assert(0 <= index && index < tasks_.size());

	tasks_[index]->isCompleted_ = isCompleted;
}

#pragma endregion

#pragma region Rep

// 新規担当者作成
size_t TaskManager::CreateRep(const char name[32], const StudentNumber& stuNum)
{
	// Nullチェック
	assert(name);

	// 新規担当者
	std::unique_ptr<Rep> newRep = std::make_unique<Rep>();

	newRep->id_ = reps_.size();
	newRep->SetName(name);
	newRep->stuNum_ = stuNum;

	// 最後尾に挿入
	reps_.push_back(newRep);

	// 要素番号を返す
	return reps_.size() - 1;
}

// 担当者名設定
void TaskManager::SetRepName(const size_t index, const char name[32])
{
	// 範囲チェック
	assert(0 <= index && index < tasks_.size());

	// Nullチェック
	assert(name);

	reps_[index]->SetName(name);
}

// 担当者学籍番号設定
void TaskManager::SetRepStudentNumber(const size_t index, const StudentNumber& stuNum)
{
	// 範囲チェック
	assert(0 <= index && index < tasks_.size());

	reps_[index]->stuNum_ = stuNum;
}

#pragma endregion
void TaskManager::Draw()
{

}
