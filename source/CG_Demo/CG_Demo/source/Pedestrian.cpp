#include "Pedestrian.h"



Pedestrian::Pedestrian(float _dt, Point ** crlPoints, int degree, Point * _p)
{
	dt = _dt;
	bez = new Bezier(degree, crlPoints);
	traveler = new Point(_p);
	dir = 1;
	param = 0.001f;
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
}

void Pedestrian::draw() {
	//printf("%f %f \n", traveler->x, traveler->z);
	traveler->draw();
}
