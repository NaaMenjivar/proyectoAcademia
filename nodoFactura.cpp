#include "nodoFactura.h"

//Constructor y Destructor
nodoFactura::nodoFactura(factura* f, nodoFactura* s) : fact(f), sig(s) {}
nodoFactura::~nodoFactura() { delete fact; }

//Métodos Get
factura* nodoFactura::getFactura() { return fact; }
nodoFactura* nodoFactura::getSig() { return sig; }

//Métodos Set
void nodoFactura::setFactura(factura* f) { fact = f; }
void nodoFactura::setSig(nodoFactura* s) { sig = s; }

//toString
string nodoFactura::toString() {
	return fact->toString();
}
