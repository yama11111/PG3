#include "Circle.h"
#include <stdio.h>
#define PI 3.141592

float Circle::size()
{
	return radius_ * radius_ * PI;
}

void Circle::draw()
{
	printf("�~\n");
	printf("���a : %f\n", radius_);
	printf("�ʐ� : %f\n", size());
}
