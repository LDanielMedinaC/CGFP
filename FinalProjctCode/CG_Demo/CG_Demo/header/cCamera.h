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
#include "vecs.h"


class Camera
{
public:
	Camera();
	~Camera();

	void setView();
	void move(float dist, float angle);
	void moveAround(float angle, vector3f p);
	bool pointInFrustum(vector3f p);
	void rotate(float angle, vector3f p);
	void setCamDef();

	vector3f pos;        // Position of camera
	vector3f dir;        // Z unit in camera space
	vector3f up;        // Y unit in camera space
	vector3f pivot;        // Where the camera is looking at
	float nearDist;        // Near plane distance
	float farDist;        // Far plane distance
	float fov;            // Field of view, lens aperture in Y
	int viewportDims[4];
	float ratio;

	vector3f xref, yref, zref;
};
