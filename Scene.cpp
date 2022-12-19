#include "Scene.h"
#include <stdio.h>
#include <cstdlib>

void TitleScene::Update()
{
	if (isDrawn_ == false) { return; }
	
	scanf_s("%d", &inputNum_);

	// �w�肳�ꂽ�����ȊO���͂���
	if (inputNum_ == 1 ||
		inputNum_ == 2 ||
		inputNum_ == 3 ||
		inputNum_ == 9)
	{
		isInput_ = true;
	}

	system("cls");
}

void TitleScene::Draw()
{
	if (isInput_) { return; }

	printf("���݂̃V�[�� : TitleScene\n");
	printf("------------------------\n");
	printf("�ԍ��̃L�[�������ăV�[���؂�ւ�\n");
	printf("1 : GameScene\n");
	printf("2 : GameOverScene\n");
	printf("3 : ClearScene\n");
	printf("------------------------\n");
	printf("9 : �I��\n");

	isDrawn_ = true;
}

void GameScene::Update()
{
	if (isDrawn_ == false) { return; }

	scanf_s("%d", &inputNum_);

	// �w�肳�ꂽ�����ȊO���͂���
	if (inputNum_ == 0 ||
		inputNum_ == 2 ||
		inputNum_ == 3 ||
		inputNum_ == 9)
	{
		isInput_ = true;
	}

	system("cls");
}

void GameScene::Draw()
{
	if (isInput_) { return; }

	printf("���݂̃V�[�� : GameScene\n");
	printf("------------------------\n");
	printf("�ԍ��̃L�[�������ăV�[���؂�ւ�\n");
	printf("0 : TitleScene\n");
	printf("2 : GameOverScene\n");
	printf("3 : ClearScene\n");
	printf("------------------------\n");
	printf("9 : �I��\n");

	isDrawn_ = true;
}

void GameOverScene::Update()
{
	if (isDrawn_ == false) { return; }

	scanf_s("%d", &inputNum_);

	// �w�肳�ꂽ�����ȊO���͂���
	if (inputNum_ == 0 ||
		inputNum_ == 1 ||
		inputNum_ == 3 ||
		inputNum_ == 9)
	{
		isInput_ = true;
	}

	system("cls");
}

void GameOverScene::Draw()
{
	if (isInput_) { return; }

	printf("���݂̃V�[�� : GameOverScene\n");
	printf("------------------------\n");
	printf("�ԍ��̃L�[�������ăV�[���؂�ւ�\n");
	printf("0 : TitleScene\n");
	printf("1 : GameScene\n");
	printf("3 : ClearScene\n");
	printf("------------------------\n");
	printf("9 : �I��\n");

	isDrawn_ = true;
}

void ClearScene::Update()
{
	if (isDrawn_ == false) { return; }

	scanf_s("%d", &inputNum_);
	
	// �w�肳�ꂽ�����ȊO���͂���
	if (inputNum_ == 0 ||
		inputNum_ == 1 ||
		inputNum_ == 2 ||
		inputNum_ == 9)
	{
		isInput_ = true;
	}

	system("cls");
}

void ClearScene::Draw()
{
	if (isInput_) { return; }

	printf("���݂̃V�[�� : ClearScene\n");
	printf("------------------------\n");
	printf("�ԍ��̃L�[�������ăV�[���؂�ւ�\n");
	printf("0 : TitleScene\n");
	printf("1 : GameScene\n");
	printf("2 : GameOverScene\n");
	printf("------------------------\n");
	printf("9 : �I��\n");

	isDrawn_ = true;
}
