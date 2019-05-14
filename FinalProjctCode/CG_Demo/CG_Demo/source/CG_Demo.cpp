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

#include "Player.h"
#include "cCamera.h"
#include "vecs.h"
//TODO agregar las fuentes de luz

Player * p;
Camera* mainCam;
int mouseCords[2];
int mouseMotionType = 0;

void init() {
	mainCam = new Camera();
	mainCam->dir.y = -45;
	mainCam->pos.y = 30;
	mainCam->pos.z = 0;
	mainCam->fov = 150;
	mainCam->farDist = 250;

	float pos[] = { 0,0,0 };
	p = new Player(pos);

	glEnable(GL_DEPTH_TEST);			// Enable check for close and far objects.
	glClearColor(0.0, 0.0, 0.0, 0.0);	// Clear the color state.
	glMatrixMode(GL_MODELVIEW);			// Go to 3D mode.
	glLoadIdentity();					// Reset 3D view matrix.
}

void display()							// Called for each frame (about 60 times per second).
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);				// Clear color and depth buffers.
	glLoadIdentity();												// Reset 3D view matrix.
	mainCam->setView();
	//gluLookAt(0, 10, 20, 0, 0, 0, 0, 1, 0);
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
	gluLookAt(0.0, 1.0, 4.0,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);
	display();
}


/*
	This can help on having an interactive keyboard
*/
void littleKey(unsigned char key, int x, int y) {
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
	p->move(-_x * 2, -_z * 2);

	glutPostRedisplay();

}
void motion(int x, int y) {
	switch (mouseMotionType) {
	case 1:
		mainCam->moveAround(-(mouseCords[1] - y) * 0.01, vector3f(1, 0, 0));
		mainCam->moveAround(-(mouseCords[0] - x) * 0.01, vector3f(0, 1, 0));
		break;
	case 2:
		mainCam->moveAround(-(mouseCords[1] - x) * 0.01, vector3f(0, 0, 1));
		break;
	case 3:
		mainCam->moveAround(-(mouseCords[1] - y) * 0.01, vector3f(0, 0, 1));
		break;
	case 4:

		break;
	}
}

void mouse(int button, int state, int x, int y) {
	mouseCords[0] = x;
	mouseCords[1] = y;
	int mods;

	if (state == GLUT_DOWN) {
		mods = glutGetModifiers();
		if (mods & GLUT_ACTIVE_SHIFT) {
			mouseMotionType = 2;
		}
		else if (mods & GLUT_ACTIVE_ALT) {
			mouseMotionType = 3;
		}
		else if (mods & GLUT_ACTIVE_CTRL) {
			mouseMotionType = 4;
		}
		else {
			mouseMotionType = 1;
		}
	}
}



int main(int argc, char* argv[])
{
	glutInit(&argc, argv);											// Init GLUT with command line parameters.
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);		// Use 2 buffers (hidden and visible). Use the depth buffer. Use 3 color channels.
	glutInitWindowSize(800, 600);
	glutCreateWindow("Algo");

	init();
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	
	glutKeyboardFunc(littleKey);
	glutSpecialFunc(specialKey);
	glutReshapeFunc(reshape);										// Reshape CALLBACK function.
	glutDisplayFunc(display);										// Display CALLBACK function.
	glutIdleFunc(idle);												// Idle CALLBACK function.
	glutMainLoop();													// Begin graphics program.
	return 0;														// ANSI C requires a return value.
}