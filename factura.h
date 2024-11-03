#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "descuento.h"
using namespace std;

class factura {
private:
	float subtotal;
	float iva;
	descuento* desc;
	int cantCursos;
	float total;
public:
	factura(float, float, descuento*, int);
	~factura();

	float getSubtotal();
	float getIva();
	descuento* getDescuento();
	int getCantCursos();
	float getTotal();

	void setSubtotal(float);
	void setIva(float);
	void setDescuento(descuento*);
	void setCantCursos(int);

	void calcularTotal(float);

	string toString();
};