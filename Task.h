#pragma once
#include "Rep.h"

// タスク
struct Task
{
public:
	// 優先度
	enum class Priority
	{
		None,
		High,	 // 高
		Normal,	 // 普通
		Low,	 // 低
	};
public:
	// ID
	unsigned int id_ = 0;
	// 担当者
	Rep rep_{};
	// 題名
	char title_[64]{};
	// 内容
	char content_[256]{};
	// 優先度
	char priority_[16]{};
	// 完了したか
	bool isCompleted_ = false;
public:
	// 題名設定
	void SetTitle(const char title[64]);
	// 内容設定
	void SetContent(const char content[256]);
	// 優先度設定
	void SetPriority(const Priority& priority);
	// 描画
	void Draw();
public:
	// コンストラクタ
	Task() :
		id_(0), rep_(), title_(""), content_(""), priority_(""), isCompleted_(false)
	{}
	// デストラクタ
	~Task() = default;
};