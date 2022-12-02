#pragma once

class List
{
private:
	// セル構造体
	struct Cell
	{
		int val_ = int(); // 値
		Cell* prev_ = nullptr; // 前
		Cell* next_ = nullptr; // 次
	};
private:
	// セル
	Cell* cells_ = nullptr;
	// セル数
	size_t size_ = 0;
public:
	// 終端に追加
	void PushBack(int val);
	// 挿入
	void Insert(int val, size_t itr);
	// 削除
	void Delete(size_t itr);
	// 全消去
	void Clear();
public:
	// セル数取得
	size_t Size() const { return size_; }
public:
	~List();
public:
	int& operator[] (size_t itr);
};

