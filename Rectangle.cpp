#include "Rectangle.h"
#include <stdio.h>

float Rectangle::size()
{
    return horizontal_ * vertical_;
}

void Rectangle::draw()
{
	printf("��`\n");
	printf("�� : %f\n", horizontal_);
	printf("�c : %f\n", vertical_);
	printf("�ʐ� : %f\n", size());
}
