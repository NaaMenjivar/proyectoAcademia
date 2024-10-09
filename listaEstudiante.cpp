#include "listaEstudiante.h"

listaEstudiante::listaEstudiante() {
	primero = nullptr;
	actual = nullptr;
}

listaEstudiante::~listaEstudiante() {
	if (!esVacia()) {
		vaciarLista();
	}
}

bool listaEstudiante::insertarPrimero(estudiante* est) {
	if (buscarPorId(est->getId())) {
		return false;
	}
	primero = new nodoEstudiante(est, primero); 
		return true;
}

bool listaEstudiante::insertarFinal(estudiante* est) {
	if (buscarPorId(est->getId())) {
		return false;
	}
	actual = primero;
	if (esVacia()) {
		primero = new nodoEstudiante(est, primero);
	}
	else {
		while (actual->getSiguiente() != nullptr) {
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(new nodoEstudiante(est, nullptr));
	}
	return true;
}

string listaEstudiante::toString() {
	stringstream s;
	actual = primero;
	while (actual != nullptr) {
		s << actual->getEstudiante()->toString();
		actual = actual->getSiguiente();
	}
	return s.str();
}

bool listaEstudiante::buscarPorId(string id) {
	actual = primero;
	while (actual != nullptr) {
		if (actual->getEstudiante()->getId() == id) {
			return true;
		}
		actual = actual->getSiguiente();
	}
	return false;
}

bool listaEstudiante::esVacia() {
	return primero == nullptr;
}

void listaEstudiante::eliminarEstudiante(string id) {
	actual = primero;
	if (buscarPorId(id)) {
		if (actual->getEstudiante()->getId() == id) {
			primero = primero->getSiguiente();
			delete actual;
		}
		else {
			while (actual->getSiguiente()->getEstudiante()->getId() != id) {
				actual = actual->getSiguiente();
			}
			nodoEstudiante* nodo = actual->getSiguiente();
			actual->setSiguiente(actual->getSiguiente()->getSiguiente());
			delete nodo;
		}
	}
}

void listaEstudiante::vaciarLista() {
	while (primero != nullptr) {
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
	}
}
