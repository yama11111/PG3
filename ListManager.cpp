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

#pragma region �X�V����
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
		printf("������x���͂��Ă��������B\n");
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
			printf("������x���͂��Ă��������B\n");
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
			printf("������x���͂��Ă��������B\n");
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
			printf("������x���͂��Ă��������B\n");
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
			printf("������x���͂��Ă��������B\n");
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
			printf("������x���͂��Ă��������B\n");
			break;
		}
	}
}

void ListManager::Update()
{
	// �`�抮�����Ă��Ȃ��Ȃ�X�V���Ȃ�
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

#pragma region �`�揈��
void ListManager::DrawSelect()
{
	printf("[�v�f�̑���]\n");
	printf("1.�v�f�̕\��\n");
	printf("2.�v�f�̑}��\n");
	if (list_.Size() > 0)
	{
		printf("3.�v�f�̕ҏW\n");
		printf("4.�v�f�̍폜\n");
	}
	printf("5.�v�f�̕��ёւ�\n");
	printf("9.�I��\n");
	printf("\n");
	printf("--------------------------------------\n");
	printf("�����I�����Ă��������B\n");
}

void ListManager::DrawDisplay()
{
	if (disp_ == DisplayDesc::Select)
	{
		printf("[�v�f�̕\��]\n");
		printf("1.�v�f�̈ꗗ�\��\n");
		printf("2.���Ԃ��w�肵�ėv�f��\��\n");
		printf("9.�v�f����ɖ߂�\n");
		printf("\n");
		printf("�����I�����Ă��������B\n");
	}
	else if (disp_ == DisplayDesc::All)
	{
		printf("[�v�f�̈ꗗ�\��]\n");
		printf("�v�f�ꗗ:{\n");

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
		printf("�v�f��: %d\n", list_.Size());
		printf("\n");
		printf("--------------------------------------\n");
		printf("1.�v�f�̕\���ɖ߂�\n");
		printf("2.�v�f�̑���ɖ߂�\n");
	}
	else if (disp_ == DisplayDesc::Specified)
	{
		printf("[���Ԃ��w�肵�ėv�f��\��]\n");
		if (isDispInputed_ == false)
		{
			printf("�\���������v�f�̏��Ԃ��w�肵�ĉ������B\n");
		}
		else
		{
			printf("%d: %d\n", inputNum_, list_[inputNum_ - 1]);
			printf("\n");
			printf("--------------------------------------\n");
			printf("1.�v�f�̕\���ɖ߂�\n");
			printf("2.�v�f�̑���ɖ߂�\n");
		}
	}
}

void ListManager::DrawInsert()
{
	printf("[�v�f�̑}��]\n");
	if (isInsertItrInputed_ == false)
	{
		if (isInsertFailed_)
		{
			printf("%d�Ԗڂ̗v�f��������܂���ł����B\n", inputNum_);
			printf("\n");
		}
		printf("�v�f��ǉ�����ꏊ���w�肵�Ă��������B");
		printf("�Ō���ɒǉ�����ꍇ��0����͂��Ă��������B\n");
	}
	else if (isInsertNumInputed_ == false)
	{
		printf("%d�Ԗڂ̗v�f�ɒǉ�����l����͂��Ă��������B\n", insertItr_ + 1);
	}
	else
	{
		printf("�v�f\"%d\"��%d�Ԗڂɑ}������܂����B\n", inputNum_, insertItr_ + 1);
		printf("\n");
		printf("--------------------------------------\n");
		printf("1.�v�f�̑}���ɖ߂�\n");
		printf("2.�v�f�̑���ɖ߂�\n");
	}
}

void ListManager::DrawEdit()
{
	printf("[�v�f�̕ҏW]\n");
	if (isEditItrInputed_ == false)
	{
		if (isEditFailed_)
		{
			printf("%d�Ԗڂ̗v�f��������܂���ł����B\n", inputNum_);
			printf("\n");
		}
		printf("�ҏW�������v�f�̔ԍ����w�肵�Ă��������B\n");
	}
	else if (isEditNumInputed_ == false)
	{
		printf("%d�Ԗڂ̗v�f�̕ύX����l����͂��Ă��������B\n", inputNum_);
	}
	else
	{
		printf("%d�Ԗڂ̗v�f�̒l��\"%d\"�ɕύX����܂����B\n", editItr_ + 1, inputNum_);
		printf("\n");
		printf("--------------------------------------\n");
		printf("1.�v�f�̕ҏW�ɖ߂�\n");
		printf("2.�v�f�̑���ɖ߂�\n");
	}
}

void ListManager::DrawDelete()
{
	printf("[�v�f�̍폜]\n");
	if (isDeleteItrInputed_ == false)
	{
		if (isDeleteFailed_)
		{
			printf("%d�Ԗڂ̗v�f��������܂���ł����B\n", inputNum_);
			printf("\n");
		}
		printf("�폜�������v�f�̔ԍ����w�肵�Ă��������B\n");
	}
	else
	{
		printf("%d�Ԗڂ̗v�f\"%d\"���폜���܂����B\n", inputNum_, deleteNum_);
		printf("\n");
		printf("--------------------------------------\n");
		printf("1.�v�f�̍폜�ɖ߂�\n");
		printf("2.�v�f�̑���ɖ߂�\n");
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
