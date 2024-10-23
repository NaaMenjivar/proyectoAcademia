#include "nodoGrupo.h"

//Constructor y Destructor
nodoGrupo::nodoGrupo(grupo* g, nodoGrupo* s) : grup(g), sig(s) {}
nodoGrupo::~nodoGrupo() { delete grup; }

//Métodos Get
grupo* nodoGrupo::getGrupo() { return grup; }
nodoGrupo* nodoGrupo::getSig() { return sig; }

//Métodos Set
void nodoGrupo::setGrupo(grupo* g) { grup = g; }
void nodoGrupo::setSig(nodoGrupo* s) { sig = s; }

//toString
string nodoGrupo::toString() {
	return grup->toString();
}
