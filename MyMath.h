#pragma once

template<typename T, typename U>
class MyMath
{
public:
	T Min(const T a, const U b) 
	{
		return a > b ? a : b;
	}
};