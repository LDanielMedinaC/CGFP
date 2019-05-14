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
#include <string.h>
#include <math.h>
#include <stdlib.h>

//own libraries
#include "Player.h"

Player* p;


void init() {
	
	p = new Player(0,0);

	glEnable(GL_DEPTH_TEST);			// Enable check for close and far objects.
	glClearColor(0.0, 0.0, 0.0, 0.0);	// Clear the color state.
	glMatrixMode(GL_MODELVIEW);			// Go to 3D mode.
	glLoadIdentity();					// Reset 3D view matrix.
}

void display()							// Called for each frame (about 60 times per second).
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);				// Clear color and depth buffers.
	glLoadIdentity();												// Reset 3D view matrix.
	gluLookAt(0.0, 30.0, 10.0,										// Where the camera is.
		0.0, 0.0, 0.0,										// To where the camera points at.
		0.0, 1.0, 0.0);
	p->draw();
	glutSwapBuffers();
}

void idle()															// Called when drawing is finished.
{
	glutPostRedisplay();											// Display again.
}

void reshape(int x, int y)											// Called when the window geometry changes.
{
	glMatrixMode(GL_PROJECTION);									// Go to 2D mode.
	glLoadIdentity();												// Reset the 2D matrix.
	gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 50.0);		// Configure the camera lens aperture.
	glMatrixMode(GL_MODELVIEW);										// Go to 3D mode.
	glViewport(0, 0, x, y);											// Configure the camera frame dimensions.
	gluLookAt(0.0, 0.0, 20.0,
		0.0, 0.0, 0.0,
		0.0, 0.0, 1.0);
	display();
}


/*
	This can help on having an interactive keyboard
*/
void littleKey(unsigned char key, int x, int y) {
	float _x = 0, _z = 0;
	switch (key) {
	case GLUT_KEY_UP:
		_z += 0.001f;
		break;
	case GLUT_KEY_DOWN:
		_z -= 0.001f;
		break;
	case GLUT_KEY_LEFT:
		_x += 0.001f;
		break;
	case GLUT_KEY_RIGHT:
		_z -= 0.001f;
		break;
	}
	p->move(_x, _z);
	
	glutPostRedisplay();
}

void specialKey(int key, int x, int y) {
	float _x = 0, _z = 0;
	switch (key) {
	case GLUT_KEY_UP:
		_z += 0.1f;
		break;
	case GLUT_KEY_DOWN:
		_z -= 0.1f;
		break;
	case GLUT_KEY_LEFT:
		_x += 0.1f;
		break;
	case GLUT_KEY_RIGHT:
		_x -= 0.1f;
		break;
	}
	p->move(-_x*2, -_z*2);

	glutPostRedisplay();

}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);											// Init GLUT with command line parameters.
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);		// Use 2 buffers (hidden and visible). Use the depth buffer. Use 3 color channels.
	glutInitWindowSize(800, 600);
	glutCreateWindow("Final Project");

	init();
	glutKeyboardFunc(littleKey);
	glutSpecialFunc(specialKey);
	glutReshapeFunc(reshape);										// Reshape CALLBACK function.
	glutDisplayFunc(display);										// Display CALLBACK function.
	glutIdleFunc(idle);												// Idle CALLBACK function.
	glutMainLoop();													// Begin graphics program.
	return 0;														// ANSI C requires a return value.
}