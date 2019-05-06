#pragma once 

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
#include <vector>
#include <string>
#include <string.h>

using namespace std;

class Model
{
public:
	Model();
	~Model();


	struct vec3 {
		float x, y, z;
	};

	struct vec2 {
		float x, y;
	};

	struct point{
		vec3 p[3];
	};

	FILE* file;
	vector<vec3> v;
	vector<vec3> vn;
	vector<vec2> vt;
	vector<point> points;
	
	void readOBJ();
	void load();

};
