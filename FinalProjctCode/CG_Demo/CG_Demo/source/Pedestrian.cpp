#include "Pedestrian.h"

Pedestrian::Pedestrian(float _dt, Point** crlPoints, int degree, Point* _p)
{
	dt = _dt;
	bez = new Bezier(degree, crlPoints);
	traveler = new Point(_p);
	dir = 1;
	param = 0.001f;
	p = new Particle(traveler->getArrPos());
}

Pedestrian::Pedestrian(float _dt, Bezier * _bez, Point* _p)
{
	dt = _dt;
	bez = _bez;
	traveler = new Point(_p);
	dir = 1;
	param = 0.001f;
	p = new Particle(traveler->getArrPos());
}



Pedestrian::~Pedestrian()
{
}


void Pedestrian::update() {
	if (param >= 1.0 || param <= 0)
		dir *= -1.0f;
	param += dir * dt;

	traveler = bez->evaluate(param, dir);
	traveler->r = 1;
	traveler->g = 1;
	p->pos[0] = traveler->x;
	p->pos[2] = traveler->z;
	
}

void Pedestrian::draw() {
	
	p->draw();
}
