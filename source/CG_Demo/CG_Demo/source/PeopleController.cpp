#include "PeopleController.h"



PeopleController::PeopleController(float* up, float* bottom, int number)
{

	limitUp.x = up[0];
	limitUp.y = up[1];
	limitUp.z = up[2];
	limitBottom.x = bottom[0];
	limitBottom.y = bottom[1];
	limitBottom.z = bottom[2];

	numberPpl = number;
	ppl = new Pedestrian * [number];

	for (int i = 0; i < number; i++) {
		Point** ctrlP = getPoints(4);
		ppl[i] = new Pedestrian(0.0001, ctrlP, 4, ctrlP[0]);
	}

}

Point ** PeopleController::getPoints(int degree) {
	Point** ctrlP = new Point*[degree];
	Point* aux;
	float upx = rand() / (float)RAND_MAX * (limitUp.x - limitBottom.x);
	float upz = rand() / (float)RAND_MAX * (limitUp.z - limitBottom.z);
	float bottomx = rand() / (float)RAND_MAX * (limitUp.x - limitBottom.x);
	float bottomz = rand() / (float)RAND_MAX * (limitUp.z - limitBottom.z);
	
	float dx = upx - bottomx;
	float dz = upz - bottomz;
	
	if (dz == 0)
		return getPoints(4);

	ctrlP[0] = new Point(bottomx, 0, bottomz, 1, 1, 0);

	for (int i = 1; i < degree; i++) {
		float x = rand() / (float)RAND_MAX * (limitUp.x - ctrlP[i - 1]->x);
		float z = dx/dz*x + rand() / (float)RAND_MAX * 2;
		aux = new Point(x, 0, z, 1, 1, 0);
	}
	return ctrlP;
}

bool PeopleController::checkCollition(Pedestrian *a, Pedestrian *b) {
	Point* pa = a->traveler;
	Point* pb = b->traveler;
	float dist = (pa->x - pb->x) * (pa->x - pb->x) + (pa->y - pb->y) * (pa->y - pb->y) + (pa->z - pb->z) * (pa->z - pb->z);
	float rad = (pa->r + pb->r) * (pa->r + pb->r);
	return dist < (rad - 0.001);
}
void PeopleController::update() {
	for (int i = 0; i < numberPpl; i++) {
		bool col = false;
		for (int j = 0; j < numberPpl; j++) {
			if (checkCollition(ppl[i], ppl[j])) {
				if (i > j)
					col = true;
			}
		}
		if (!col) {
			ppl[i]->update();
		}
	}
}

void PeopleController::draw() {
	for (int i = 0; i < numberPpl; i++) {
		ppl[i]->update();
	}
}

PeopleController::~PeopleController()
{
}
