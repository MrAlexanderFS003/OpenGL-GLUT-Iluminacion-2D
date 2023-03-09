#include <math.h>

class Circulo {
	float posCX = 100.0f, posCY = 100.0f;
	float pdx = cos(GradoARadianes(pa)), pdy = -sin(GradoARadianes(pa)), pa = 0.0f;
public:
	Circulo() {}
	void Dibuja();
	void Actualiza();

	//Setters y Getters 
	void setPosCX(float valor) { posCX = valor; }
	void setPosCY(float valor) { posCY = valor; }

	float getPosCY() { return posCY; }
	float getPosCX() { return posCX; }

	void setPdx(float valor) { pdx = valor; }
	void setPdy(float valor) { pdy = valor; }
	void setPa(float valor) { pa = valor; }

	float getPdx() { return pdx; }
	float getPdy() { return pdy; }
	float getPa() { return pa; }
	
	float GradoARadianes(int a) { return a * 3.14159265359 / 180.0; }
};
