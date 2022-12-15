#include <stdio.h>
#include <cstdlib>
#include "MyMath.h"

int main()
{
	MyMath<int, int>		mathIntAndInt;
	MyMath<float, float>	mathFloatAndFloat;
	MyMath<double, double>	mathDoubleAndDouble;

	MyMath<int, float>		mathIntAndFloat;
	MyMath<float, double>	mathFloatAndDouble;
	MyMath<double, int>		mathDoubleAndInt;

	printf("compare int    and int    : %i\n", mathIntAndInt.Min(5, 4));
	printf("compare float  and float  : %f\n", mathFloatAndFloat.Min(3.3f, 4.7f));
	printf("compare double and double : %lf\n", mathDoubleAndDouble.Min(9.1, 2.5));

	printf("compare int    and float  : %i\n", mathIntAndFloat.Min(4, 1.2f));
	printf("compare float  and double : %f\n", mathFloatAndDouble.Min(6.3f, 5.5));
	printf("compare double and int    : %lf\n", mathDoubleAndInt.Min(7.7, 4));

	system("PAUSE");
	return 0;
}