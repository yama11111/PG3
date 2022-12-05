#include "Enemy.h"
#include <stdio.h>

void Enemy::Initialize()
{
	phase_ = Phase::AttackP;
}

void Enemy::Update()
{
	// �֐��Ăяo��
	size_t index = static_cast<size_t>(phase_);
	(this->*pActTable_[index])();
}

void Enemy::ChangePhase()
{
	// �s���ω�
	switch (phase_)
	{
	case Phase::AttackP:
		phase_ = Phase::ShotP;
		break;
	case Phase::ShotP:
		phase_ = Phase::EscapeP;
		break;
	case Phase::EscapeP:
		phase_ = Phase::AttackP;
		break;
	}
}

void Enemy::Draw()
{
	printf("------------\n");

	switch (phase_)
	{
	case Phase::AttackP:
	printf("Phase : �ߐ�\n");
		break;
	case Phase::ShotP:
	printf("Phase : �ˌ�\n");
		break;
	case Phase::EscapeP:
	printf("Phase : ���E\n");
		break;
	}

	printf("------------\n");
}

void Enemy::Attack()
{
	phase_ = Phase::AttackP;
}
void Enemy::Shot()
{
	phase_ = Phase::ShotP;
}
void Enemy::Escape()
{
	phase_ = Phase::EscapeP;
}

void (Enemy::* Enemy::pActTable_[])() =
{
	&Enemy::Attack,
	&Enemy::Shot,
	&Enemy::Escape,
};
