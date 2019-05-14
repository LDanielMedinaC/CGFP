#include "Player.h"



Player::Player()
{
}

Player::Player(float x, float z)
{
	p = new Point(x,0,z,1,0,0);
}

Player::Player(float x, float z, float r, float g, float b)
{

}

Player::~Player()
{
}

void Player::move(float _x, float _z) {
	p->x += _x;
	p->z += _z;
}

void Player::update() {

}

void Player::draw() {
	p->draw();
}
