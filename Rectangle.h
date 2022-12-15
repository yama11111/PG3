#pragma once
#include "IShape.h"

class Rectangle :public IShape
{
private:
	float horizontal_ = 0.0f;
	float vertical_ = 0.0f;
public:
	Rectangle(const float horizontal,const float vertical) :
		horizontal_(horizontal), vertical_(vertical)
	{};
	float size() override;
	void draw() override;
};
