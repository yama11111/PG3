#pragma once

class StationLine
{
public:
	// 駅構造体
	struct Station
	{
		const char* name_ = nullptr; // 名前
	};
private:
	// セル構造体
	struct Cell 
	{
		Station station_;
		Cell* prev_ = nullptr; // 前のセル
		Cell* next_ = nullptr; // 次のセル
	};
public:
	// 先頭セル
	Cell* head_ = nullptr;
	// 最後尾セル
	Cell* end_ = nullptr;
	// セル数
	size_t size_ = 0;
public:
	// 初期化
	void Initialize();
	// 最後尾に追加
	void PushBack(const Station& station);
	// 挿入
	void Insert(const Station& station, const size_t itr);
	// 全消去
	void Clear();
	// 上り描画
	void DrawUp();
	// 下り描画
	void DrawDown();
private:
	// セルの中身描画 (次へ)
	static void DrawCellPrev(Cell* cells);
	// セルの中身描画 (前へ)
	static void DrawCellNext(Cell* cells);
public:
	// デストラクタ
	~StationLine();
};

