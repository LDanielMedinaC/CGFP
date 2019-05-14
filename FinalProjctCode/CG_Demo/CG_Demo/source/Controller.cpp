#include "Controller.h"



Controller::Controller()
{	
	FILE * f = fopen("source/BC.txt","r");
	
	
	fscanf(f, "%d", &nbc); 
	bc = new Bezier*[nbc];
	for (int i = 0; i < nbc; i++) {
		int degree;
		fscanf(f,"%d", &degree);
		Point** ctrlPoints = new Point * [degree];
		for (int j = 0; j < degree; j++) {
			float x, y, z;
			fscanf(f,"%f%f%f", &x,&y,&z);
			ctrlPoints[j] = new Point(x,y,z,1,1,0);
		}
		bc[i] = new Bezier(degree, ctrlPoints);
	}
	fclose(f);
	p = new Pedestrian * [PEDESTRIAN];
	for (int i = 0; i < PEDESTRIAN; i++) {
		Point* aux = new Point(0,0,0,1,0,0);
		int index = rand() % nbc;
		p[i] = new Pedestrian(0.0002f, bc[index], aux);
		p[i]->param = (float)rand() / (float)RAND_MAX;
	}
}
Controller::~Controller()
{

}
bool Controller::checkCollition(float a, float b) {
	float sum[] = { 0.501f, -0.501f };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (a + sum[i] < b + sum[j] && a + sum[i] > b + sum[(j + 1) & 1])
				return true;
		}
	}
	return false;
}

void Controller::update() {
	for (int i = 0; i < PEDESTRIAN; i++) {
		if (!checkCollition(p[i]->p->pos[0], *px) && !checkCollition(p[i]->p->pos[2], *pz)) {
			p[i]->update();
		}
		else
			p[i]->dir *= -1;
	}
}

void Controller::draw() {
	for (int i = 0; i < PEDESTRIAN; i++)
		p[i]->draw();
}


