#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

Bullet * Bullet::create()
{
	return nullptr;
}

void Bullet::update(float dt)
{
	if (body != nullptr) {
		this->setPosition(Point(this->body->GetPosition().x*PTM_RATIO, this->body->GetPosition().y*PTM_RATIO));
	}
}

void Bullet::initPhysic(b2World *world, Point pos)
{
	auto size = this->getContentSize();
	shape.SetAsBox(size.width / 2 / PTM_RATIO, size.height/2 / PTM_RATIO);
	fixtureDef.density = 0.5f;
	fixtureDef.friction = 1.0f;
	fixtureDef.restitution = 0.0f;
	fixtureDef.shape = &shape;

	bodyDef.type = b2_dynamicBody;
	bodyDef.userData = this;		// pass sprite to bodyDef with argument: userData

	bodyDef.position.Set(pos.x / PTM_RATIO, pos.y / PTM_RATIO);

	body = world->CreateBody(&bodyDef);
	body->CreateFixture(&fixtureDef);
	body->SetGravityScale(0);
}

void Bullet::setAngel(float radian)
{
	float vx = SCREEN_SIZE.width/2 / 32*cosf(radian);
	float vy = SCREEN_SIZE.width/2 / 32 *sinf(radian);
	this->body->SetLinearVelocity(b2Vec2(vx, vy));
}
