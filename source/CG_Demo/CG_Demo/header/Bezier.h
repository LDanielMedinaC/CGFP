#pragma once
#include "Point.h"
class Bezier
{
public:
	Bezier(int _degree, Point** _ctrlPoints);
	// Point** _ctrlPoints is a pointer to an array of control points.
	~Bezier();

	// evaluate: returns a point on the Bézier curve for parameter "t".
	Point* evaluate(float t, float dir);
	void calculateCoefficients();
	int factorial(int n);
	int combination(int n, int i);

	int degree;
	Point** ctrlPoints;
	float* coefficients;
};
