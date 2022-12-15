#include <stdio.h>
#include <cstdlib>
#include "Seasoning.h"

int main()
{
	Seasoning* seasonings[3]{};

	seasonings[0] = new Salt();
	seasonings[1] = new Pepper();
	seasonings[2] = new Sugar();

	for (size_t i = 0; i < 3; i++)
	{
		seasonings[i]->DrawTaste();
	}

	for (size_t i = 0; i < 3; i++)
	{
		delete seasonings[i];
	}

	system("PAUSE");
	return 0;
}