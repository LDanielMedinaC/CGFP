#pragma once

#include "Point.h"
#include "Bezier.h"
#include "Particle.h"


class Pedestrian
{
public:
	Pedestrian(float _dt, Point** crlPoints, int degree, Point* _p);
	Pedestrian(float _dt, Bezier* bez , Point* _p);
	~Pedestrian();
	float dt;
	Point* traveler;
	Bezier* bez;
	Particle* p;


	int dir;
	float param;
	void update();
	void draw();
};

