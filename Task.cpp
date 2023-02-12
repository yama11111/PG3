#include "Task.h"
#include <stdio.h>

static const char DefPriorities[4][16]
{
	"",
	"高",
	"普通",
	"低",
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
	printf("------- タスク ------\n");
	printf("ID : %i\n", id_);
	printf("担当者 : %s\n", rep_.name_);
	printf("題名 : %s\n", title_);
	printf("内容 : %s\n", content_);
	printf("優先度 : %s\n", priority_);

	if (isCompleted_)
	{
		printf("ステータス : 完了\n");
	}
	else
	{
		printf("ステータス : 未完了\n");
	}

	printf("---------------------\n");
}