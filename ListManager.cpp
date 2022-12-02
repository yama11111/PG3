#include "ListManager.h"
#include <cassert>
#include <stdio.h>
#include <cstdlib>

void ListManager::Initialize()
{
	list_.Clear();
	list_.PushBack(0);
	list_.PushBack(1);
	list_.PushBack(2);
	list_.PushBack(3);
	list_.PushBack(4);
	list_.PushBack(5);
	list_.PushBack(6);

	ope_ = Operation::Select;
	disp_ = DisplayDesc::Select;

	isDispSelected_ = false;
	isDispInputed_ = false;

	isInsertItrInputed_ = false;
	isInsertFailed_ = false;
	isInsertNumInputed_ = false;
	insertItr_ = -1;

	isEditItrInputed_ = false;
	isEditFailed_ = false;
	isEditNumInputed_ = false;
	editItr_ = -1;

	isDeleteItrInputed_ = false;
	isDeleteFailed_ = false;
	deleteItr_ = -1;
	deleteNum_ = 0;

	isDrew_ = false;
}

#pragma region 更新処理
void ListManager::UpdateSelect()
{
	switch (inputNum_)
	{
	case 1:
		ope_ = Operation::Display;
		disp_ = DisplayDesc::Select;
		isDispSelected_ = false;
		isDispInputed_ = false;
		break;
	case 2:
		ope_ = Operation::Insert;
		isInsertItrInputed_ = false;
		isInsertFailed_ = false;
		isInsertNumInputed_ = false;
		insertItr_ = -1;
		break;
	case 3:
		ope_ = Operation::Edit;
		isEditItrInputed_ = false;
		isEditFailed_ = false;
		isEditNumInputed_ = false;
		editItr_ = -1;
		break;
	case 4:
		ope_ = Operation::Delete;
		isDeleteItrInputed_ = false;
		isDeleteFailed_ = false;
		deleteItr_ = -1;
		deleteNum_ = 0;
		break;
	case 9:
		ope_ = Operation::End;
		break;
	default:
		printf("もう一度入力してください。\n");
		break;
	}
}

void ListManager::UpdateDisplay()
{
	if (isDispSelected_ == false)
	{
		switch (inputNum_)
		{
		case 1:
			disp_ = DisplayDesc::All;
			isDispSelected_ = true;
			isDispInputed_ = true;
			break;
		case 2:
			disp_ = DisplayDesc::Specified;
			isDispSelected_ = true;
			break;
		case 9:
			ope_ = Operation::Select;
			break;
		default:
			printf("もう一度入力してください。\n");
			break;
		}
	}
	else if (isDispInputed_ == false) 
	{
		isDispInputed_ = true;
	}
	else
	{
		switch (inputNum_)
		{
		case 1:
			disp_ = DisplayDesc::Select;
			isDispSelected_ = false;
			isDispInputed_ = false;
			break;
		case 2:
			ope_ = Operation::Select;
			disp_ = DisplayDesc::Select;
			isDispSelected_ = false;
			isDispInputed_ = false;
			break;
		default:
			printf("もう一度入力してください。\n");
			break;
		}
	}
}

void ListManager::UpdateInsert()
{
	if (isInsertItrInputed_ == false)
	{
		if (inputNum_ - 1 > static_cast<int>(list_.Size()) ||
			inputNum_ < 0) 
		{
			isInsertFailed_ = true;
			return;
		}
		if(inputNum_ == 0)
		{
			insertItr_ = list_.Size();
		}
		else
		{
			insertItr_ = inputNum_ - 1; 
		}
		isInsertItrInputed_ = true;
	}
	else if (isInsertNumInputed_ == false)
	{
		list_.Insert(inputNum_, insertItr_);
		isInsertNumInputed_ = true;
	}
	else
	{
		switch (inputNum_)
		{
		case 1:
			isInsertItrInputed_ = false;
			isInsertFailed_ = false;
			isInsertNumInputed_ = false;
			insertItr_ = -1;
			break;
		case 2:
			ope_ = Operation::Select;
			isInsertItrInputed_ = false;
			isInsertFailed_ = false;
			isInsertNumInputed_ = false;
			insertItr_ = -1;
			break;
		default:
			printf("もう一度入力してください。\n");
			break;
		}
	}
}

void ListManager::UpdateEdit()
{
	if (isEditItrInputed_ == false)
	{
		if (inputNum_ - 1 > static_cast<int>(list_.Size()) ||
			inputNum_ <= 0)
		{
			isEditFailed_ = true;
			return;
		}
		else
		{
			editItr_ = inputNum_ - 1;
		}
		isEditItrInputed_ = true;
	}
	else if (isEditNumInputed_ == false)
	{
		list_[editItr_] = inputNum_;
		isEditNumInputed_ = true;
	}
	else
	{
		switch (inputNum_)
		{
		case 1:
			isEditItrInputed_ = false;
			isEditFailed_ = false;
			isEditNumInputed_ = false;
			editItr_ = -1;
			break;
		case 2:
			ope_ = Operation::Select;
			isEditItrInputed_ = false;
			isEditFailed_ = false;
			isEditNumInputed_ = false;
			editItr_ = -1;
			break;
		default:
			printf("もう一度入力してください。\n");
			break;
		}
	}
}

void ListManager::UpdateDelete()
{
	if (isDeleteItrInputed_ == false)
	{
		if (inputNum_ - 1 > static_cast<int>(list_.Size()) ||
			inputNum_ <= 0)
		{
			isDeleteFailed_ = true;
			return;
		}
		else
		{
			deleteItr_ = inputNum_ - 1;
		}
		deleteNum_ = list_[deleteItr_];
		list_.Delete(deleteItr_);
		isDeleteItrInputed_ = true;
	}
	else
	{
		switch (inputNum_)
		{
		case 1:
			isDeleteItrInputed_ = false;
			isDeleteFailed_ = false;
			deleteItr_ = -1;
			break;
		case 2:
			ope_ = Operation::Select;
			isDeleteItrInputed_ = false;
			isDeleteFailed_ = false;
			deleteItr_ = -1;
			break;
		default:
			printf("もう一度入力してください。\n");
			break;
		}
	}
}

void ListManager::Update()
{
	// 描画完了していないなら更新しない
	if (isDrew_ == false) { return; }

	scanf_s("%d", &inputNum_);

	switch (ope_)
	{
	case Operation::Select:
		UpdateSelect();
		break;
	case Operation::Display:
		UpdateDisplay();
		break;
	case Operation::Insert:
		UpdateInsert();
		break;
	case Operation::Edit:
		UpdateEdit();
		break;
	case Operation::Delete:
		UpdateDelete();
		break;
	}
}
#pragma endregion

#pragma region 描画処理
void ListManager::DrawSelect()
{
	printf("[要素の操作]\n");
	printf("1.要素の表示\n");
	printf("2.要素の挿入\n");
	if (list_.Size() > 0)
	{
		printf("3.要素の編集\n");
		printf("4.要素の削除\n");
	}
	printf("5.要素の並び替え\n");
	printf("9.終了\n");
	printf("\n");
	printf("--------------------------------------\n");
	printf("操作を選択してください。\n");
}

void ListManager::DrawDisplay()
{
	if (disp_ == DisplayDesc::Select)
	{
		printf("[要素の表示]\n");
		printf("1.要素の一覧表示\n");
		printf("2.順番を指定して要素を表示\n");
		printf("9.要素操作に戻る\n");
		printf("\n");
		printf("操作を選択してください。\n");
	}
	else if (disp_ == DisplayDesc::All)
	{
		printf("[要素の一覧表示]\n");
		printf("要素一覧:{\n");

		size_t num = 0;
		while (true)
		{
			if (num >= list_.Size()) { break; }
			int listNum = list_[num];
			printf(" %d: %d\n", num, listNum);
			num++;
		}

		printf("}\n");
		printf("\n");
		printf("要素数: %d\n", list_.Size());
		printf("\n");
		printf("--------------------------------------\n");
		printf("1.要素の表示に戻る\n");
		printf("2.要素の操作に戻る\n");
	}
	else if (disp_ == DisplayDesc::Specified)
	{
		printf("[順番を指定して要素を表示]\n");
		if (isDispInputed_ == false)
		{
			printf("表示したい要素の順番を指定して下さい。\n");
		}
		else
		{
			printf("%d: %d\n", inputNum_, list_[inputNum_ - 1]);
			printf("\n");
			printf("--------------------------------------\n");
			printf("1.要素の表示に戻る\n");
			printf("2.要素の操作に戻る\n");
		}
	}
}

void ListManager::DrawInsert()
{
	printf("[要素の挿入]\n");
	if (isInsertItrInputed_ == false)
	{
		if (isInsertFailed_)
		{
			printf("%d番目の要素が見つかりませんでした。\n", inputNum_);
			printf("\n");
		}
		printf("要素を追加する場所を指定してください。");
		printf("最後尾に追加する場合は0を入力してください。\n");
	}
	else if (isInsertNumInputed_ == false)
	{
		printf("%d番目の要素に追加する値を入力してください。\n", insertItr_ + 1);
	}
	else
	{
		printf("要素\"%d\"が%d番目に挿入されました。\n", inputNum_, insertItr_ + 1);
		printf("\n");
		printf("--------------------------------------\n");
		printf("1.要素の挿入に戻る\n");
		printf("2.要素の操作に戻る\n");
	}
}

void ListManager::DrawEdit()
{
	printf("[要素の編集]\n");
	if (isEditItrInputed_ == false)
	{
		if (isEditFailed_)
		{
			printf("%d番目の要素が見つかりませんでした。\n", inputNum_);
			printf("\n");
		}
		printf("編集したい要素の番号を指定してください。\n");
	}
	else if (isEditNumInputed_ == false)
	{
		printf("%d番目の要素の変更する値を入力してください。\n", inputNum_);
	}
	else
	{
		printf("%d番目の要素の値が\"%d\"に変更されました。\n", editItr_ + 1, inputNum_);
		printf("\n");
		printf("--------------------------------------\n");
		printf("1.要素の編集に戻る\n");
		printf("2.要素の操作に戻る\n");
	}
}

void ListManager::DrawDelete()
{
	printf("[要素の削除]\n");
	if (isDeleteItrInputed_ == false)
	{
		if (isDeleteFailed_)
		{
			printf("%d番目の要素が見つかりませんでした。\n", inputNum_);
			printf("\n");
		}
		printf("削除したい要素の番号を指定してください。\n");
	}
	else
	{
		printf("%d番目の要素\"%d\"を削除しました。\n", inputNum_, deleteNum_);
		printf("\n");
		printf("--------------------------------------\n");
		printf("1.要素の削除に戻る\n");
		printf("2.要素の操作に戻る\n");
	}
}

void ListManager::Draw()
{
	system("cls");

	switch (ope_)
	{
	case Operation::Select:
		DrawSelect();
		break;
	case Operation::Display:
		DrawDisplay();
		break;
	case Operation::Insert:
		DrawInsert();
		break;
	case Operation::Edit:
		DrawEdit();
		break;
	case Operation::Delete:
		DrawDelete();
		break;
	}

	isDrew_ = true;
}
#pragma endregion
