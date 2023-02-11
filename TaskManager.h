#pragma once
#include "Task.h"
#include <vector>
#include <memory>

// タスクマネージャー
class TaskManager
{
private:
	// タスク
	std::vector<std::unique_ptr<Task>> tasks_;
	// 担当者
	std::vector<std::unique_ptr<Rep>> reps_;
public:
	// 新規タスク作成
	size_t CreateTask(const Rep& rep, const char title[64], const char content[256],unsigned short priority);
	// タスク内容設定
	void SetTaskContent(const size_t index, const char content[256]);
	// タスク完了設定
	void SetTaskIsCompleted(const size_t index, const bool isCompleted);
public:
	// 新規担当者作成
	size_t CreateRep(const char name[32], const StudentNumber& stuNum);
	// 担当者名設定
	void SetRepName(const size_t index, const char name[32]);
	// 担当者学籍番号設定
	void SetRepStudentNumber(const size_t index, const StudentNumber& stuNum);
public:
	// 描画
	void Draw();
};

