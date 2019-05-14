#include "Particle.h"

void copyArr(float* fromArr, float* toArr, int size) {
	for (int i = 0; i < size; i++) {
		toArr[i] = fromArr[0];
	}
}


Particle::Particle(float _pos[3])
{
	copyArr(_pos, pos, 3);
	for (int i = 0; i < 3; i++) {
		color[i] = 60.f * (float)rand() / (float)RAND_MAX;
	}

}


Particle::Particle(float _pos[3], float _diffuse[3], float _oDiffuse[3], float _specular[3], float _shininess)
{
	copyArr(_pos, pos, 3);
	copyArr(diffuse, _diffuse, 3);
	copyArr(oDiffuse, _oDiffuse, 3);
	copyArr(specular, _specular, 3);
	shininess = _shininess;
}


Particle::Particle()
{

}

Particle::~Particle()
{
}

void drawBodyPart(float*trans, float * scale) {
	glPushMatrix(); {
		glTranslatef(trans[0], trans[1], trans[0]);
		glScaled(scale[0], scale[1], scale[2]);
		glutSolidSphere(1, 10, 10);

	}glPopMatrix();
}


void Particle::draw() {
	//printf("por que no entras aqui");

	glPushMatrix();
	{
		
		glColor3f(color[0], color[1], color[2]);
		
		glTranslatef(pos[0], pos[1], pos[2]);
		float trans[] = {0,2.5f,0};
		float scale[] = {1,1,1};
		drawBodyPart(trans, scale);//head

		trans[1] = 0;
		scale[1] = 0.8;
		scale[2] = 0.5;

		drawBodyPart(trans, scale);//torso

		trans[0] = 2.0f; trans[1] = -0.5f;
		scale[0] = 0.2f; scale[1] = 0.8f; scale[2] = 0.2f;

		drawBodyPart(trans, scale);
		trans[0] = -2.0f; trans[1] = 0.5f;
		drawBodyPart(trans, scale);

	}
	glPopMatrix();
}

