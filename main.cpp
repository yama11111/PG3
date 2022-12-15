#include <stdio.h>
#include <cstdlib>
#include "Rectangle.h"
#include "Circle.h"

int main()
{
	IShape* shapes[2]{};

	shapes[0] = new Circle(3.5f);
	shapes[1] = new Rectangle(2.0f, 4.5f);

	for (size_t i = 0; i < 2; i++)
	{
		printf("------------------------\n");
		shapes[i]->draw();
		printf("------------------------\n");
	}

	for (size_t i = 0; i < 2; i++)
	{
		delete shapes[i];
	}

	system("PAUSE");
	return 0;
}