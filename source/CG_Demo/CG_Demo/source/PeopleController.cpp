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
	ppl = new Pedestrian * [number + 1];

	for (int i = 1; i <= number; i++) {
		printf("%d: \n", i);
		Point** ctrlP = getPoints(4);
		ppl[i] = new Pedestrian(0.0001f, ctrlP, 4, ctrlP[0]);
	}

}

Point** PeopleController::getPoints(int degree) {
	Point** ctrlP = new Point * [degree];
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
	ctrlP[degree - 1] = new Point(upx, 0, upz, 1, 1, 0);
	for (int i = 1; i < degree - 1; i++) {
		float x = rand() / (float)RAND_MAX*(limitUp.x - ctrlP[i - 1]->x) + ctrlP[i - 1]->x;
		float z = dx/dz*x + rand() / (float)RAND_MAX * 2;
		
		printf("\t\t%d: %.3f %.3f\n", i, x, z);
		
		aux = new Point(x, 0, z, 1, 1, 0);
		ctrlP[i] = new Point(x, 0, z, 1, 1, 0);;
		printf("\t\t%d: %.3f %.3f\n", i, aux ->x, aux->z);
		free(aux);
	}

	for (int i = 0; i < degree; i++) {
		printf("\t%d: x = %.4f, y = %.4f, z = %.4f\n", i, ctrlP[i] -> x, ctrlP[i]->y, ctrlP[i]->x);
	}

	return ctrlP;
}

bool PeopleController::checkCollition(Pedestrian *a, Pedestrian *b) {
	Point* pa = a->traveler;
	Point* pb = b->traveler;
	float dist = (pa->x - pb->x) * (pa->x - pb->x) + (pa->y - pb->y) * (pa->y - pb->y) + (pa->z - pb->z) * (pa->z - pb->z);
	float rad = (pa->r + pb->r) * (pa->r + pb->r);
	return dist < (rad - 0.0001);
}
void PeopleController::update() {
	for (int i = 1; i <= numberPpl; i++) {
		bool col = false;
		for (int j = 0; j <= numberPpl; j++) {
			if (i == j)
				continue;
			col |= checkCollition(ppl[i], ppl[j]) && (i > j);
		}
		if (!col || 1) {
			ppl[i]->update();
		}
	}
}

void PeopleController::draw() {
	for (int i = 0; i <= numberPpl; i++) {
		ppl[i]->draw();
		printf("%d: x : %f, y : %f, z : %f\n", i, ppl[i]->traveler->x, ppl[i]->traveler->y, ppl[i]->traveler->z);
	}
}

PeopleController::~PeopleController()
{
}
