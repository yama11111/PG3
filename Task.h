#pragma once
#include "Rep.h"

// タスク
struct Task
{
public:
	// ID
	unsigned int id_;
	// 担当者
	Rep rep_;
	// 題名
	char title_[64];
	// 内容
	char content_[256];
	// 優先度
	unsigned short priority_;
	// 完了したか
	bool isCompleted_;
public:
	// 題名設定
	void SetTitle(const char title[64]);
	// 内容設定
	void SetContent(const char content[256]);
	// 描画
	void Draw();
public:
	// コンストラクタ
	Task() :
		id_(0), rep_(), title_(""), priority_(0), isCompleted_(false)
	{}
};