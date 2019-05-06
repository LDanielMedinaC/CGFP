#include "Bezier.h"



Bezier::Bezier(int _degree, Point **_ctrlPoints)
{
	degree = _degree;
	///copy the crlPoints
	ctrlPoints = new Point*[degree];
	for (int i = 0; i < degree; i++) {
		ctrlPoints[i] = new Point(_ctrlPoints[i]);
	}
	calculateCoefficients();
	degree--;
}

void Bezier::calculateCoefficients() {
	coefficients = new float[degree + 1];
	for (int i = 0; i <= degree; i++) {
		coefficients[i] = (float)factorial(degree) / (float)(factorial(i) * factorial(degree - i));
	}
}


Bezier::~Bezier()
{
	delete ctrlPoints;
}

int Bezier::factorial(int n) {
	int fac = 1;
	for (int i = 1; i <= n; i++)
		fac *= i;
	return fac;
}

int Bezier::combination(int n, int i) {
	return  factorial(n) / (factorial(i) * factorial(n - 1));
}

Point* Bezier::evaluate(float t, float dir) {
	Point *p = new Point(0, 0, 0, 1, 1, 1);
	for (int i = 0; i <= degree; i++) {
		float c = pow(1 - t, degree - i) * pow(t, i);
		p = p->add(ctrlPoints[i]->multiplyByScalar(coefficients[i] * c));
	}
	return p;
}
