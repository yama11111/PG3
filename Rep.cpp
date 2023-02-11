#include "Rep.h"

void Rep::SetName(const char name[32])
{
	for (size_t i = 0; i < 32; i++)
	{
		name_[i] = name[i];
	}
}

void Rep::Draw()
{

}