#include "Task.h"

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

void Task::Draw()
{

}