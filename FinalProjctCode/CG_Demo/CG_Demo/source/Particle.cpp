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
	ka = new GLfloat[4];
	ka[0] = 0.05 + (0.2 - 0.05) * (float)rand() / RAND_MAX;
	ka[1] = 0.05 + (0.2 - 0.05) * (float)rand() / RAND_MAX;
	ka[2] = 0.05 + (0.2 - 0.05) * (float)rand() / RAND_MAX;
	ka[3] = 1.0f;

	kd = new GLfloat[4];
	kd[0] = 0.2 + (0.8 - 0.2) * (float)rand() / RAND_MAX;
	kd[1] = 0.2 + (1.0 - 0.2) * (float)rand() / RAND_MAX;
	kd[2] = 0.2 + (1.0 - 0.2) * (float)rand() / RAND_MAX;
	kd[3] = 1.0f;

	kd2 = new GLfloat[4];
	kd2[0] = 1.0;
	kd2[1] = 0.0f;
	kd2[2] = 0.0f;
	kd2[3] = 1.0f;

	ks = new GLfloat[4];
	ks[0] = 0.4 + (0.8 - 0.4) * (float)rand() / RAND_MAX;
	ks[1] = 0.4 + (0.8 - 0.4) * (float)rand() / RAND_MAX;
	ks[2] = 0.4 + (0.8 - 0.4) * (float)rand() / RAND_MAX;
	ks[3] = 1.0f;

	alpha = new GLfloat[1];
	alpha[0] = 100;
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

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ka);
		/*if (isColliding) {
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, kd2);
		}*/
		//else {
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, kd);
		//}
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ks);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, alpha);
		//glColor3f(color[0], color[1], color[2]);
		
		glTranslatef(pos[0], 0.01f, pos[2]);
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

