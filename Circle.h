#pragma once
#include "IShape.h"

class Circle :public IShape
{
private:
	float radius_ = 0.0f;
public:
	Circle(const float radius) : 
		radius_(radius)
	{};
	float size() override;
	void draw() override;
};

