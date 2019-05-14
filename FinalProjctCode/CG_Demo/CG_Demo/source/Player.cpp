#include "Player.h"

Player::Player()
{
}

Player::Player(float * pos)
{
	p = new Particle(pos);
}

Player::Player(float x, float z, float r, float g, float b)
{

}

Player::~Player()
{
}

void Player::move(float _x, float _z) {
	p->pos[0] += _x;
	p->pos[2] += _z;
}

void Player::update() {

}

void Player::draw() {
	p->draw();
}