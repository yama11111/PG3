#pragma once
class Enemy
{
private:
	enum class Phase 
	{
		AttackP,
		ShotP,
		EscapeP,
	};
private:
	Phase phase_ = Phase::AttackP;
public:
	void Initialize();
	void Update();
	void ChangePhase();
	void Draw();
private:
	void Attack(); // �ߐ�
	void Shot();   // �ˌ�
	void Escape(); // ���E
private:
	static void (Enemy::* pActTable_[])();
};

