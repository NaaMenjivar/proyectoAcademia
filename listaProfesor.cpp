#include "listaProfesor.h"

listaProfesor::listaProfesor() : primero(nullptr), actual(nullptr) {}
listaProfesor::~listaProfesor() {
	if (!esVacia()) {
		vaciarLista();
	}
}

bool listaProfesor::insertarPrimero(profesor* profe) {
	if (buscarPorId(profe->getId())) {
		return false;
	}
	primero = new nodoProfesor(profe, primero);
		return true;
}

bool listaProfesor::insertarFinal(profesor* prof) {
	if (buscarPorId(prof->getId())) {
		return false;
	}
	if (esVacia()) {
		primero = new nodoProfesor(prof, primero);
	}
	else {
		actual = primero;
		while (actual->getSiguiente() != nullptr) {
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(new nodoProfesor(prof, nullptr));
	}
	return true;
}

string listaProfesor::toString() {
	stringstream s;
	actual = primero;
	while (actual != nullptr) {
		s << actual->getProfesor()->toString();
		actual = actual->getSiguiente();
	}
	return s.str();
}

bool listaProfesor::buscarPorId(string id) {
	actual = primero;
	while (actual != nullptr) {
		if (actual->getProfesor()->getId() == id) {
			return true;
		}
		actual = actual->getSiguiente();
	}
	return false;
}

bool listaProfesor::esVacia() {
	return primero == nullptr;
}

void listaProfesor::eliminarProfesor(string id) {
	actual = primero;
	if (buscarPorId(id)) {
		if (actual->getProfesor()->getId() == id) {
			primero = primero->getSiguiente();
			delete actual;
		}
		else {
			while (actual->getSiguiente()->getProfesor()->getId() != id) {
				actual = actual->getSiguiente();
			}
			nodoProfesor* nodo = actual->getSiguiente();
			actual->setSiguiente(actual->getSiguiente()->getSiguiente());
			delete nodo;
		}
	}
}

void listaProfesor::vaciarLista() {
	while (primero != nullptr) {
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
	}
}
