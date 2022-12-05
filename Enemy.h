#pragma once
class Enemy
{
private:
	int hp_ = 10;
	static bool isDeath_;
public:
	void Initialize();
	void Update();
	void Draw();
	void Hit(const int damage) { hp_ -= damage; }
	static bool IsDeath() { return isDeath_; }
};

