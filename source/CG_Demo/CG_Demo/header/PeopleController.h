#include "Pedestrian.h"
#include "Point.h"

class PeopleController
{
public:
	
	struct vec3 {
		float x, y, z;
	};
	
	PeopleController(float * up, float * bottom, int number);
	~PeopleController();
	

	Pedestrian ** ppl;
	int numberPpl;
	vec3 limitUp;///limit top
	vec3 limitBottom;///limit bottom
	
	Point ** getPoints(int degree);
	void update();
	bool checkCollition(Pedestrian * a, Pedestrian * b);
	void draw();
};
