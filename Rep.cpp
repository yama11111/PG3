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
	printf("------- ’S“–ŽÒ ------\n");
	printf("ID : %i\n", id_);
	printf("–¼‘O : %s\n", name_);
	printf("ŠwÐ”Ô† : %s\n", stuNum_);
	printf("---------------------\n");
}