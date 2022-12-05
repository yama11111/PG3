#include "Enemy.h"
#include <stdio.h>

bool Enemy::isDeath_ = false;

void Enemy::Initialize()
{
	hp_ = 10;
}

void Enemy::Update()
{
	if (hp_ <= 0)
	{
		isDeath_ = true;
		hp_ = 0;
	}
}

void Enemy::Draw()
{
	if (isDeath_) { return; }
	printf("------------\n");
	printf("HP : %d\n", hp_);
	printf("------------\n");
}
