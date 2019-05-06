#include "Point.h"
#include "Bezier.h"
class Pedestrian
{
public:
	Pedestrian(float _dt, Point ** crlPoints, int degree, Point * _p);
	~Pedestrian();
	float dt;
	Point * traveler;
	Bezier *bez;

	int dir;
	float param;
	void update();
	void draw();
};

