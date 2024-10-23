#pragma once
#include "nodoFactura.h"
#include "factura.h"
#include "descuento.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class nodoFactura;
class factura;
class descuento;

class listaFactura {
private:
	nodoFactura* primero;
	nodoFactura* actual;
public:
	listaFactura();
	~listaFactura();
	bool insertarPrimero(factura*);
	bool insertarFinal(factura*);
	bool buscarPorNumFactura(int);
	bool vacia();
	void vaciar();
	void eliminarFactura(int);
	string toString();
};