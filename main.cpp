#include <stdio.h>
#include <cstdlib>
#include "TaskManager.h"

int main()
{
	bool isEnd = false;
	TaskManager taskMan_;
	size_t repIndex1 = taskMan_.CreateRep("�c�� ���Y", Rep::StudentNumber::LE2A);
	size_t repIndex2 = taskMan_.CreateRep("�c�� ���Y", Rep::StudentNumber::LE2B);
	size_t taskIndex1 = taskMan_.CreateTask(repIndex1, "", "", Task::Priority::High);
	size_t taskIndex2 = taskMan_.CreateTask(repIndex2, "", "", Task::Priority::Low);

	while (false)
	{

		if (isEnd) { break; }
	}

	taskMan_.Draw();

	system("PAUSE");
	return 0;
}