#include "Rectangle.h"
#include <stdio.h>

float Rectangle::size()
{
    return horizontal_ * vertical_;
}

void Rectangle::draw()
{
	printf("ãÈå`\n");
	printf("â° : %f\n", horizontal_);
	printf("èc : %f\n", vertical_);
	printf("ñ êœ : %f\n", size());
}
