#include "Rep.h"
#include <stdio.h>

static const char DefStuNums[3][32] =
{
	"",
	"LE2A",
	"LE2B",
};

void Rep::SetName(const char name[32])
{
	for (size_t i = 0; i < 32; i++)
	{
		name_[i] = name[i];
	}
}

void Rep::SetStudentNumber(const StudentNumber& stuNum)
{
	size_t index = static_cast<size_t>(stuNum);
	for (size_t i = 0; i < 32; i++)
	{
		stuNum_[i] = DefStuNums[index][i];
	}
}

void Rep::Draw()
{
	printf("------- 担当者 ------\n");
	printf("ID : %i\n", id_);
	printf("名前 : %s\n", name_);
	printf("学籍番号 : %s\n", stuNum_);
	printf("---------------------\n");
}