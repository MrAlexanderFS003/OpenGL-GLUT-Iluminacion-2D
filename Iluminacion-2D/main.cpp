/*
	Hecho por Max Flores Saldaña , Usando la programación orientada a Objetos en C++.
	Si desea ver la documentacion de GLUT: https://www.opengl.org/resources/libraries/glut/spec3/spec3.html
*/

#include "Circulo.h"
#include "Texto.h"
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

#define PI 3.14159265359
#define P2 PI/2
#define P3 3*PI/2
#define DR 0.0174533 // Radianes

Circulo cir;
Texto txt;

//Crea Estructura para teclado (Control de la figura/Objeto)
typedef struct {
	int w, a, s, d;
}BotonTeclas; BotonTeclas tecla;

const int tam = 10;

//Mapa Matriz
int mapS = 64;
int mapX = 10;
int mapY = 10;

/*
int map[] = {
	1,1,1,1,1,1,1,1,1,1,
	1,0,1,0,0,0,0,0,0,1,
	1,0,1,0,0,1,0,0,0,1,
	1,0,1,0,0,0,0,0,0,1,
	1,0,0,1,0,1,0,1,0,1,
	1,0,0,0,0,1,0,0,0,1,
	1,0,1,0,0,1,0,0,0,1,
	1,0,1,0,0,0,0,1,0,1,
	1,0,1,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,
};
*/

int map[] = {
	1,1,1,1,1,1,1,1,1,1,
	1,0,2,0,0,0,0,0,0,1,
	1,0,2,0,0,2,0,0,0,1,
	1,0,2,0,0,0,0,0,0,1,
	1,0,0,2,0,2,0,2,0,1,
	1,0,0,0,0,2,0,0,0,1,
	1,0,2,0,0,2,0,0,0,1,
	1,0,2,0,0,0,0,2,0,1,
	1,0,2,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,
};


//Variables usadas para almacenar los calculos obtenidos
float objX = 0.0f, objY = 0.0f, MobjX = 0.0f, MobjY = 0.0f;
int valor = 0, win = 0, val = 0, AnguloLuz = 90;

//Color 0|1
float r = 0.8, g = 0.8, b = 0.0;

void init() {
	glClearColor(0.2f, 0.2f, 0.2f, 0);

	/// Colores Alpha (Ajusta la opacidad con glColor4f)
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	///

    gluOrtho2D(0, 800, 650, 0);
}

void Mapa2D() {
	int xo, yo;
	for (int i = 0; i < tam; i++) {
		for (int j = 0; j < tam; j++) {
			
			if (map[i * tam + j] == 2) {
				glColor4f(r,g,b, 0.1f);
				xo = j * mapS;
				yo = i * mapS;
				glBegin(GL_QUADS);
				glVertex2i(xo, yo);
				glVertex2i(xo, yo + mapS);
				glVertex2i(xo + mapS, yo + mapS);
				glVertex2i(xo + mapS, yo);
				glEnd();
			}

			/*
			glBegin(GL_QUADS);
			glVertex2i(xo + 1, yo + 1);
			glVertex2i(xo + 1, yo + mapS - 1);
			glVertex2i(xo + mapS - 1, yo + mapS - 1);
			glVertex2i(xo + mapS - 1, yo + 1);
			glEnd();
			*/
		}
	}
}

void Accion() {
	// Mapas 

	if (val == 1) {
		int map2[] = {
			1,1,1,1,1,1,1,1,1,1,
			1,0,0,0,0,0,0,0,0,1,
			1,0,0,0,0,2,0,0,0,1,
			1,0,0,0,0,0,0,0,0,1,
			1,0,0,2,0,0,0,0,0,1,
			1,0,0,0,0,0,0,0,0,1,
			1,0,2,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,2,0,1,
			1,0,2,0,0,0,0,0,0,1,
			1,1,1,1,1,1,1,1,1,1,
			};
		for (int i = 0; i < 100; i++) {
			map[i] = map2[i];
		}
	}
	if (val == 2) {
		int map3[] = {
			1,1,1,1,1,1,1,1,1,1,
			1,0,0,0,0,0,0,0,0,1,
			1,0,0,0,0,2,0,0,0,1,
			1,0,0,0,0,0,2,0,0,1,
			1,0,2,2,2,0,0,2,0,1,
			1,0,2,0,2,0,0,0,0,1,
			1,0,2,0,2,0,0,2,0,1,
			1,0,0,0,0,0,2,2,0,1,
			1,0,2,0,0,0,0,0,0,1,
			1,1,1,1,1,1,1,1,1,1,
		};
		for (int i = 0; i < 100; i++) {
			map[i] = map3[i];
		}
	}
	if (val == 3) {
		int map4[] = {
			1,1,1,1,1,1,1,1,1,1,
			1,0,0,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,2,0,1,
			1,0,0,2,0,2,0,0,0,1,
			1,0,0,2,2,2,0,2,0,1,
			1,0,0,2,0,2,0,0,0,1,
			1,0,0,0,0,0,0,0,0,1,
			1,0,2,0,2,0,0,2,0,1,
			1,0,0,0,0,0,0,0,0,1,
			1,1,1,1,1,1,1,1,1,1,
		};
		for (int i = 0; i < 100; i++) {
			map[i] = map4[i];
		}
	}
	if (val == 4) {
		int mapP[] = {
			1,1,1,1,1,1,1,1,1,1,
			1,0,2,0,0,0,0,0,0,1,
			1,0,2,0,0,2,0,0,0,1,
			1,0,2,0,0,0,0,0,0,1,
			1,0,0,2,0,2,0,2,0,1,
			1,0,0,0,0,2,0,0,0,1,
			1,0,2,0,0,2,0,0,0,1,
			1,0,2,0,0,0,0,2,0,1,
			1,0,2,0,0,0,0,0,0,1,
			1,1,1,1,1,1,1,1,1,1,
		};
		for (int i = 0; i < 100; i++) {
			map[i] = mapP[i];
		}
	}

	//Angulo Luz
	if (val == 5) {
		AnguloLuz = 180;
	}
	
	if (val == 6) {
		AnguloLuz = 270;
	}
	
	if (val == 7) {
		AnguloLuz = 361;
	}
	
	if (val == 8) {
		AnguloLuz = 90;
		r = 0.8f; g = 0.8f; b = 0.0f;
	}

	if (val == 9) {
		r = 0.8f; g = 0.0f; b = 0.0f;
	}

	if (val == 10) {
		r = 0.8f; g = 0.8f; b = 0.0f;
	}
	
	if (val == 11) {
		exit(0);
	}

	glutPostRedisplay();
}

float Dist(float ax, float ay, float bx, float by, float ang) {
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

float GradoARadianes(int a) { return a * 3.14159265359 / 180.0; }
float FixAng(float a) { if (a > 359) { a -= 360; } if (a < 0) { a += 360; } return a; }

void Linea2D() {

	int r, mx, my, mp, dof, side; float vx, vy, rx = 0.0f, ry = 0.0f, ra, xo, yo, disV, disH;
	float AuxRxI = 0.0f, AuxRyI = 0.0f ,AuxRxF = 0.0f, AuxRyF = 0.0f ;
	ra = FixAng(cir.getPa() + 30); // Rayo retrocedido 30 grados

	for (r = 0; r < AnguloLuz; r++) {
		//---Vertical--- 
		dof = 0; side = 0; disV = 100000;
		float Tan = tan(GradoARadianes(ra));
		if (cos(GradoARadianes(ra)) > 0.001) { rx = (((int)cir.getPosCX() >> 6) << 6) + 64;      ry = (cir.getPosCX() - rx) * Tan + cir.getPosCY(); xo = 64; yo = -xo * Tan; }//Mirando a la Izquierda
		else if (cos(GradoARadianes(ra)) < -0.001) { rx = (((int)cir.getPosCX() >> 6) << 6) - 0.0001; ry = (cir.getPosCX() - rx) * Tan + cir.getPosCY(); xo = -64; yo = -xo * Tan; }//Mirando a la Derecha
		else { rx = cir.getPosCX(); ry = cir.getPosCY(); dof = 8; }  // Mirando hacia arriba o hacia abajo. no golpear

		while (dof < 8)
		{
			mx = (int)(rx) >> 6; my = (int)(ry) >> 6; mp = my * mapX + mx;
			if (mp > 0 && mp < mapX * mapY && map[mp] == 1 || map[mp] == 2) { dof = 8; disV = cos(GradoARadianes(ra)) * (rx - cir.getPosCX()) - sin(GradoARadianes(ra)) * (ry - cir.getPosCY()); }// Golpear        
			else { rx += xo; ry += yo; dof += 1; }  // Comprobar siguiente horizontal
		}

		vx = rx; vy = ry;

		//---Horizontal---
		dof = 0; disH = 100000;
		Tan = 1.0 / Tan;
		if (sin(GradoARadianes(ra)) > 0.001) { ry = (((int)cir.getPosCY() >> 6) << 6) - 0.0001; rx = (cir.getPosCY() - ry) * Tan + cir.getPosCX(); yo = -64; xo = -yo * Tan; }// Mirando Arriba 
		else if (sin(GradoARadianes(ra)) < -0.001) { ry = (((int)cir.getPosCY() >> 6) << 6) + 64;      rx = (cir.getPosCY() - ry) * Tan + cir.getPosCX(); yo = 64; xo = -yo * Tan; }// Mirando Abajo
		else { rx = cir.getPosCX(); ry = cir.getPosCY(); dof = 8; }  // Mirando directamente a la izquierda o a la derecha

		while (dof < 8)
		{
			mx = (int)(rx) >> 6; my = (int)(ry) >> 6; mp = my * mapX + mx;
			if (mp > 0 && mp < mapX * mapY && map[mp] == 1 || map[mp] == 2) { dof = 8; disH = cos(GradoARadianes(ra)) * (rx - cir.getPosCX()) - sin(GradoARadianes(ra)) * (ry - cir.getPosCY()); }// Golpear       
			else { rx += xo; ry += yo; dof += 1; }  // Comprobar siguiente horizontal
		}
		
		if (disV < disH) { rx = vx; ry = vy; disH = disV; } // Golpe horizontal primero

		// Uniando Punto de golpe
		
		if (AuxRxI > 0 && AuxRyI > 0) {
			glPointSize(4);
			glBegin(GL_POINTS);
			glColor4f(r,g,b, 1.0f);
			glVertex2i(rx, ry);
			glVertex2i(AuxRxI, AuxRyI);
			glEnd();
		}
		

		// Dibuja Poligonos 2D
		if (AuxRxI > 0 || AuxRyI > 0) {	
			glPushMatrix();
			glLineWidth(1);
			glBegin(GL_TRIANGLES);
			glColor4f(r,g,b, 0.4f);
			glVertex2i(cir.getPosCX(), cir.getPosCY());
			glVertex2i(rx, ry);
			glVertex2i(AuxRxI, AuxRyI);			
			glEnd();
			glPopMatrix();
		}
		
		//Colision
		float distancia = sqrt(pow(rx - cir.getPosCX(),2) + pow(ry - cir.getPosCY(), 2));
		if (distancia <= 2) {
			if (tecla.w == 1) {
				cir.setPosCX(cir.getPosCX() - (cir.getPdx() * 5) / 100);
				cir.setPosCY(cir.getPosCY() - (cir.getPdy() * 5) / 100);
			}

			if (tecla.s == 1) {
				cir.setPosCX(cir.getPosCX() + (cir.getPdx() * 5) / 100);
				cir.setPosCY(cir.getPosCY() + (cir.getPdy() * 5) / 100);
			}
		}

		//Guardamos el punto anterior
		AuxRxI = rx;
		AuxRyI = ry;

		ra = FixAng(ra - 1); // Ir al siguiente rayo
	}
}

void TextoEnPantalla() {
	if (tecla.a == 1) {
		txt.printw(2, 30, 130, 0, "A");
	}

	if (tecla.d == 1) {
		txt.printw(2, 30, 160, 0, "D");
	}

	if (tecla.w == 1) {
		txt.printw(2, 26, 70, 0, "W");
	}

	if (tecla.s == 1) {
		txt.printw(2, 30, 100, 0, "S");
	}
}

void Dibujar() {
    glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glTranslated(80,0,0); // Translacion para centrar la escena.
	Accion();
	Mapa2D();
	Linea2D();
	cir.Dibuja();
	TextoEnPantalla();
	glPopMatrix();

    glutSwapBuffers();
}

// Cuando la tecla es presionada
void TeclaAbajo(unsigned char teclas, int x, int y) {
	if (teclas == 'w') { tecla.w = 1; }
	if (teclas == 's') { tecla.s = 1; }
	if (teclas == 'a') { tecla.a = 1; }
	if (teclas == 'd') { tecla.d = 1; }
	
	switch (teclas) {
	case 27:
		exit(0); // Al precionar escape (Esc) se cierra el progrma 
		//Visita la pagina de codigo ASCII: https://elcodigoascii.com.ar/
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

//Cuando la tecla deja de estar presionada
void TeclaArriba(unsigned char teclas, int x, int y) {
	if (teclas == 'w') { tecla.w = 0; }
	if (teclas == 's') { tecla.s = 0; }
	if (teclas == 'a') { tecla.a = 0; }
	if (teclas == 'd') { tecla.d = 0; }
	glutPostRedisplay();
}

//Creamos una funcion "Menu" para comprobar cada valor 
void Menu(int value) {
	//Si al crear el menu el valor es 0 : destruye la ventana y la cierra 
	if (value == 0) { glutDestroyWindow(win); exit(0); }
	else { val = value; } // de otro modo el valor se agrega a otra variable 
	glutPostRedisplay();
}

/*
	glutAddMenuEntry(Nombre, Numero de orden);

	glutAddSubMenu(Nombre, Variable del menu Creado);
*/

void CrearMenu() {
	int OpcMap = glutCreateMenu(Menu); // Crea el Menu
	glutAddMenuEntry("Mapa [1] ", 1); // En este caso SubMenu
	glutAddMenuEntry("Mapa [2] ", 2);
	glutAddMenuEntry("Mapa [3] ", 3);
	glutAddMenuEntry("Mapa Predeterminado ", 4);
	int OpcLuz = glutCreateMenu(Menu);
	glutAddMenuEntry("Luz 180", 5);
	glutAddMenuEntry("Luz 270", 6);
	glutAddMenuEntry("Luz 360", 7);
	glutAddMenuEntry("Luz Predeterminado", 8);
	glutAddMenuEntry("Luz Rojo", 9);
	glutAddMenuEntry("Luz Amarillo", 10);
	int OpcVent = glutCreateMenu(Menu);
	glutAddMenuEntry("Salir", 11);
	int subMenu = glutCreateMenu(Menu);// Crea el Menu
	glutAddSubMenu("Mapas", OpcMap); // Aqui se crea el menu principal del submenu
	glutAddSubMenu("Luz", OpcLuz);
	glutAddSubMenu("Ventana", OpcVent);

	//Cada vez que hagamos click derecho saldra el submenu
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void Actualiza() {
	if (tecla.a == 1) {
		cir.setPa(cir.getPa() + 0.2 ); cir.setPa(FixAng(cir.getPa()));
		//if (cir.getPa() < 0) { cir.setPa(cir.getPa() + 2 * PI); }
		cir.setPdx(cos(GradoARadianes(cir.getPa())));
		cir.setPdy(-sin(GradoARadianes(cir.getPa())));
	}

	if (tecla.d == 1) {
		cir.setPa(cir.getPa() - 0.2 ); cir.setPa(FixAng(cir.getPa()));
		//if (cir.getPa() > 2 * PI) { cir.setPa(cir.getPa() - 2 * PI); }
		cir.setPdx(cos(GradoARadianes(cir.getPa())));
		cir.setPdy(-sin(GradoARadianes(cir.getPa())));
	}

	if (tecla.w == 1) {
		cir.setPosCX(cir.getPosCX() + (cir.getPdx() * 5) / 100);
		cir.setPosCY(cir.getPosCY() + (cir.getPdy() * 5) / 100);
	}

	if (tecla.s == 1) {
		cir.setPosCX(cir.getPosCX() - (cir.getPdx() * 5) / 100);
		cir.setPosCY(cir.getPosCY() - (cir.getPdy() * 5) / 100);
	}

	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    win = glutCreateWindow("LUCES 2D");

    init();
	CrearMenu();
	glutDisplayFunc(Dibujar);
    glutIdleFunc(Actualiza);
	glutKeyboardFunc(TeclaAbajo); 
	glutKeyboardUpFunc(TeclaArriba);
    glutMainLoop();
}
