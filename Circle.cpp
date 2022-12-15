#include "Circle.h"
#include <stdio.h>
#define PI 3.141592

float Circle::size()
{
	return radius_ * radius_ * PI;
}

void Circle::draw()
{
	printf("â~\n");
	printf("îºåa : %f\n", radius_);
	printf("ñ êœ : %f\n", size());
}
