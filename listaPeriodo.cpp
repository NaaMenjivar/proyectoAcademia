#include "listaPeriodo.h"

listaPeriodo::listaPeriodo() : primero(nullptr), actual(nullptr) {}
listaPeriodo::~listaPeriodo() {
	while (!esVacia()) {
		vaciarLista();
	}
}

bool listaPeriodo::insertarPrimero(periodo* p) {
	if (buscarPorNumPeriodo(p->getNumTrimestre())) {
		return false;
	}
	primero = new nodoPeriodo(p, primero);
	return true;
}

bool listaPeriodo::insertarFinal(periodo* p) {
	if (buscarPorNumPeriodo(p->getNumTrimestre())) {
		return false;
	}
	if (esVacia()) {
		primero = new nodoPeriodo(p, nullptr);
	}
	else {
		actual = primero;
		while (actual != nullptr && actual->getSig() != nullptr) {
			actual = actual->getSig();
		}
		actual->setSig(new nodoPeriodo(p, nullptr));
	}
	return true;
}

bool listaPeriodo::buscarPorNumPeriodo(int num) {
	if (esVacia()) {
		return false;
	}
	actual = primero;
	while (actual != nullptr) {
		if (actual->getPeriodo()->getNumTrimestre() == num) {
			return true;
		}
		actual = actual->getSig();
	}
	return false;
}

bool listaPeriodo::esVacia() {
	return primero == nullptr;
}

void listaPeriodo::eliminarPeriodo(int num) {
	actual = primero;
	if (buscarPorNumPeriodo(num)) {
		if (actual->getPeriodo()->getNumTrimestre() == num) {
			primero = primero->getSig();
			delete actual;
		}
		else {
			while (actual->getSig()->getPeriodo()->getNumTrimestre() != num) {
				actual = actual->getSig();
			}
			nodoPeriodo* nodo = actual->getSig(); 
			actual->setSig(actual->getSig()->getSig());
			delete nodo;
		}
	}
}

void listaPeriodo::vaciarLista() {
	while (!esVacia()) {
		actual = primero;
		primero = primero->getSig();
		delete actual;
	}
}

string listaPeriodo::toString() {
	stringstream s; 
	int t = 1; 
	if (esVacia()) { 
		s << "No hay informacion que mostrar, la lista esta vacia." << endl; 
	}
	else {
		actual = primero;
		while (actual != nullptr) {
			s << "---------------- " << t << " ----------------" << endl; 
			s << actual->toString(); 
			t++;
			actual = actual->getSig(); 
		}
	}
	return s.str(); 
}
