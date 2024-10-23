#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class descuento {
private:
	int cursosMinimos;
	float porcentajeDescuento;
public:
	descuento(int, float);
	~descuento();
	int getCursos();
	float getPorcentaje();
	void setCursos(int);
	void setPorcentaje(float);
	float calcularDescuento(float, int);
};