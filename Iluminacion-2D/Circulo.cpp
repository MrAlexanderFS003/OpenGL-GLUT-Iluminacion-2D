#include "Circulo.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

void Circulo::Dibuja() {

	glPushMatrix();

	glColor3ub(255,255,255);
	glPointSize(8);
	glBegin(GL_POINTS);
	glVertex2f(posCX,posCY);
	glEnd();

	//Linea/Vector al que a punta
	glColor3f(1,1,1);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2i(posCX,posCY);
	glVertex2i(posCX + pdx * 20, posCY + pdy * 20);
	glEnd();

	glPopMatrix();
}

void Circulo::Actualiza() {
	glutPostRedisplay();
}