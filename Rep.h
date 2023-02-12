#pragma once

// 担当者
struct Rep
{
public:
	// 学籍番号
	enum class StudentNumber
	{
		None,
		LE2A,
		LE2B,
	};
public:
	// ID
	unsigned int id_ = 0;
	// 名前
	char name_[32]{};
	// 学籍番号
	char stuNum_[32]{};
public:
	// 名前設定
	void SetName(const char name[32]);
	// 学籍番号設定
	void SetStudentNumber(const StudentNumber& stuNum);
	// 描画
	void Draw();
public:
	// コンストラクタ
	Rep() :
		id_(0), name_(""), stuNum_("")
	{}
	// デストラクタ
	~Rep() = default;
};

