#pragma once

class BookLoanHistory
{
public:
	// ステータス
	struct Status
	{
		const char* name_ = nullptr; // 氏名
		unsigned int borrowDay_ = 0; // 貸出日
		unsigned int returnDay_ = 0; // 返却日
	};
private:
	// セル構造体
	struct Cell 
	{
		Status state_;
		Cell* next_ = nullptr; // 次のセル
	};
public:
	// セル
	Cell* cells_ = nullptr;
	// セル数
	size_t size_ = 0;
public:
	// 初期化
	void Initialize();
	// 最後尾に追加
	void PushBack(const Status& state);
	// 全消去
	void Clear();
	// 描画
	void Draw();
private:
	// セルの中身描画
	static void DrawCell(Cell* cells);
public:
	// デストラクタ
	~BookLoanHistory();
};

