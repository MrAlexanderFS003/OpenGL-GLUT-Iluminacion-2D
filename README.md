# ILUMINACION 2D
## Solucion a Errores y otros
Al momento de querer ejecutar el programa les saldra error, pero tranquilos, este error tiene una solución sencilla,
para solucionarlo tenemos que seguir lo siguiente:
> Copia lo siguiente: _CRT_SECURE_NO_WARNINGS

![Solucion](https://user-images.githubusercontent.com/96871746/212933383-9f5548fb-c07f-4a61-9e86-019d7020e7e3.gif)

### Modificar fuente de letras
El siguiente código solo es para ejemplo , no esta completo.
Para modificar la fuente de letra nos guiaremos de esta pag.

> https://www.opengl.org/resources/libraries/glut/spec3/node76.html#SECTION000111000000000000000

Cada *font_style* guarda el tipo de fuente de la letra , quizas no hay muchas fuentes , pero hay librerias que ayudan con mas variedad.
```C++
void Texto::printw(int val, float x, float y, float z, const char* format, ...) {
	if (val == 1) {
		font_style = GLUT_BITMAP_TIMES_ROMAN_10; 
	}
	else {
		font_style = GLUT_BITMAP_TIMES_ROMAN_24;
	}
}
```
## RAY CASTING
Ray casting hace referencia al uso de la intersección rayo-superficie para solucionar una variedad de problemas en gráficos por ordenador y geometría computacional. En
otras palabras es crear una escena 3D en un plano 2D , ¿ Que loco verdad ?, sin embargo , para este proyecto solo usaremos la lógica que este mismo tiene. Si bien sabemos
el ray casting lo que hace es trazar un rayo y cuando este rayo golpea/colisiona con una Linea Horizontal o vertical esta genera punto de golpe/colision, estos puntos 
de colision/golpe son importantes para crear las primitivas y generar la iluminacion.

> Para entender, se tiene lo siguiente:
![RayCasting](https://user-images.githubusercontent.com/96871746/224180617-dbf92ebe-b86a-4cb0-bcb6-77a2fccddfc1.gif)

> Lo malo de esta técnica es que no puede ser configurada en plano 3D. Sin embargo con un poco mas de conocimiento en matrices podriamos modificar este proyecto
para algo mas complejo.

### PROGRAMA EN EJECUCION

![GIF](https://user-images.githubusercontent.com/96871746/224181777-ebf516a9-21c7-43e6-af1f-136975af8b39.gif)


