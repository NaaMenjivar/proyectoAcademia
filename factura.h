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
	int numFactura;
public:
	factura(float, float, descuento*, int, int);
	~factura();

	float getSubtotal();
	float getIva();
	descuento* getDescuento();
	int getCantCursos();
	float getTotal();
	int getNumFactura();

	void setSubtotal(float);
	void setIva(float);
	void setDescuento(descuento*);
	void setCantCursos(int);
	void setNumFactura(int);

	void calcularTotal();

	string toString();
};