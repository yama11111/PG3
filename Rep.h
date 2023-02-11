#pragma once

// 学籍番号
enum class StudentNumber
{
	None,
	LE2A,
	LE2B,
};

// 担当者
struct Rep
{
public:
	// ID
	unsigned int id_;
	// 名前
	char name_[32];
	// 学籍番号
	StudentNumber stuNum_;
public:
	// 名前設定
	void SetName(const char name[32]);
	// 描画
	void Draw();
public:
	// コンストラクタ
	Rep() :
		id_(0), name_(""), stuNum_(StudentNumber::None)
	{}
};

