#pragma once

class Seasoning
{
public:
	virtual void DrawTaste() = 0;
};

class Salt : public Seasoning
{
public:
	void DrawTaste() override;
};

class Pepper : public Seasoning
{
public:
	void DrawTaste() override;
};

class Sugar : public Seasoning
{
public:
	void DrawTaste() override;
};