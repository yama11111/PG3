#include "Task.h"
#include <stdio.h>

static const char DefPriorities[4][16]
{
	"",
	"��",
	"����",
	"��",
};

void Task::SetTitle(const char title[64])
{
	for (size_t i = 0; i < 64; i++)
	{
		title_[i] = title[i];
	}
}

void Task::SetContent(const char content[256])
{
	for (size_t i = 0; i < 256; i++)
	{
		content_[i] = content[i];
	}
}

void Task::SetPriority(const Priority& priority)
{
	size_t index = static_cast<size_t>(priority);
	for (size_t i = 0; i < 16; i++)
	{
		priority_[i] = DefPriorities[index][i];
	}
}

void Task::Draw()
{
	printf("------- �^�X�N ------\n");
	printf("ID : %i\n", id_);
	printf("�S���� : %s\n", rep_.name_);
	printf("�薼 : %s\n", title_);
	printf("���e : %s\n", content_);
	printf("�D��x : %s\n", priority_);

	if (isCompleted_)
	{
		printf("�X�e�[�^�X : ����\n");
	}
	else
	{
		printf("�X�e�[�^�X : ������\n");
	}

	printf("---------------------\n");
}