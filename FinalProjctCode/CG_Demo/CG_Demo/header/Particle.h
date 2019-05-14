#pragma once 

// Please don't change lines 9-31 (It helps me to grade)
#ifdef _APPLE_
// For XCode only: New C++ terminal project. Build phases->Compile with libraries: add OpenGL and GLUT
// Import this whole code into a new C++ file (main.cpp, for example). Then run.
// Reference: https://en.wikibooks.org/wiki/OpenGL_Programming/Installation/Mac
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#endif
#ifdef _WIN32
// For VS on Windows only: Download CG_Demo.zip. UNZIP FIRST. Double click on CG_Demo/CG_Demo.sln
// Run
#include "freeglut.h"
#endif
#ifdef _unix_
// For Linux users only: g++ CG_Demo.cpp -lglut -lGL -o CG_Demo
// ./CG_Demo
// Reference: https://www.linuxjournal.com/content/introduction-opengl-programming
#include "GL/freeglut.h"
#include "GL/gl.h"
#endif

#include <stdio.h>

//TODO animar manos, rotar el modelo con forme avanza y poner iluminaci[on

class Particle
{
public:
	Particle();
	Particle(float _pos[3]);
	Particle(float pos[3], float diffuse[3], float oDiffuse[3], float specular[3], float shininess);
	~Particle();
	
	float diffuse[3];
	float oDiffuse[3];
	float specular[3];
	float shininess;
	float pos[3];
	float color[3];

	GLfloat* ka, * ks, * kd, * kd2, * alpha;



	void draw();
	void update(float * pos);
	
};
