#include "Bezier.h"
#include "Pedestrian.h"
#include "Point.h"
#include <stdio.h>
#include <stdlib.h>



#define PEDESTRIAN 5
class Controller
{
public:

	Controller();
	~Controller();
	Bezier** bc;
	Pedestrian** p;
	float* px, * pz;
	int nbc;
	void update();
	void draw();
	bool checkCollition(float a, float b);
};
