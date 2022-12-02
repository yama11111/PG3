#pragma once
#include "List.h"

class ListManager
{
private:
	// 機能列挙体
	enum class Operation
	{
		Select,	 // 選択
		Display, // 表示
		Insert,  // 挿入
		Edit,	 // 編集
		Delete,  // 削除
		End,	 // 終了
	};
	// 表示設定列挙体
	enum class DisplayDesc
	{
		Select, // 選択
		All, // 一覧表示
		Specified, // 指定表示
	};
private:
	// リスト
	List list_;

	// 入力を受け取る用
	int inputNum_ = 0;

	// 機能
	Operation ope_ = Operation::Select;
	// 表示設定
	DisplayDesc disp_ = DisplayDesc::Select;

	// 選択完了フラグ (表示用)
	bool isDispSelected_ = false;
	// 入力完了フラグ (表示用)
	bool isDispInputed_ = false;

	// 配列番号入力完了フラグ (挿入用)
	bool isInsertItrInputed_ = false;
	// 失敗フラグ (挿入用)
	bool isInsertFailed_ = false;
	// 入力完了フラグ (挿入用)
	bool isInsertNumInputed_ = false;
	// 配列番号 (挿入用)
	int insertItr_ = -1;

	// 配列番号入力完了フラグ (編集用)
	bool isEditItrInputed_ = false;
	// 失敗フラグ (編集用)
	bool isEditFailed_ = false;
	// 入力完了フラグ (編集用)
	bool isEditNumInputed_ = false;
	// 配列番号 (編集用)
	int editItr_ = -1;

	// 配列番号入力完了フラグ (削除用)
	bool isDeleteItrInputed_ = false;
	// 失敗フラグ (削除用)
	bool isDeleteFailed_ = false;
	// 配列番号 (削除用)
	int deleteItr_ = -1;
	// 削除した要素の値 (削除用)
	int deleteNum_ = 0;

	// 描画完了フラグ
	bool isDrew_ = false;
public:
	// 初期化
	void Initialize();
	// 更新
	void Update();
	// 描画
	void Draw();
	// 終了か
	bool isEnd() { return ope_ == Operation::End; }
private:
	void UpdateSelect(); // 選択更新
	void UpdateDisplay();// 表示更新
	void UpdateInsert(); // 挿入更新
	void UpdateEdit();   // 編集更新
	void UpdateDelete(); // 削除更新
private:
	void DrawSelect(); // 選択描画
	void DrawDisplay();// 表示描画
	void DrawInsert(); // 挿入描画
	void DrawEdit();   // 編集描画
	void DrawDelete(); // 削除描画
};

