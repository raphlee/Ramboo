#include "BombOfEnemy.h"



BombOfEnemy::BombOfEnemy()
{
}

BombOfEnemy::~BombOfEnemy()
{
}

BombOfEnemy * BombOfEnemy::create(float scale)
{
	BombOfEnemy *bullet = new BombOfEnemy();
	bullet->initWithSpriteFrameName("bomb.png");
	bullet->setTag(TAG_BOMB_ENEMY);
	bullet->isDie = false;
	return bullet;
}

