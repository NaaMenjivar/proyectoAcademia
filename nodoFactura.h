#pragma once
#include "factura.h"

class nodoFactura {
private:
	factura* fact;
	nodoFactura* sig;
public:
	nodoFactura(factura*, nodoFactura*);
	~nodoFactura();

	factura* getFactura();
	nodoFactura* getSig();

	void setFactura(factura*);
	void setSig(nodoFactura*);

	string toString();
};