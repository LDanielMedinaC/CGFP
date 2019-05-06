#include "Point.h"



Point::Point(float _x, float _y, float _z, float _r, float _g, float _b)
{
	x = _x;
	y = _y;
	z = _z;
	r = _r;
	g = _g;
	b = _b;

}

Point::Point(Point *other) {
	x = other->x;
	y = other->y;
	z = other->z;
	r = other->z;
	g = other->g;
	b = other->b;
}


Point::~Point()
{
}

Point* Point::multiplyByScalar(float k) {
	Point *p = new Point(x, y, z, r, g, b);
	p->x *= k;
	p->y *= k;
	p->z *= k;
	return p;
}

Point* Point::add(Point* other) {
	Point *p = new Point(other);
	p->x += x;
	p->y += y;
	p->z += z;
	return p;
}

void Point::draw() {
	glPushMatrix(); {
		glTranslatef(x, y, z);
		glColor3f(r, g, b);
		glutSolidSphere(1.0, 50, 50);
	}glPopMatrix();
}

void Point::update() {

}


