#include "listaCurso.h"

listaCurso::listaCurso() : actual(nullptr), primero(nullptr) {}
listaCurso::~listaCurso() {
    if (!vacia()) {
        vaciar();
    }
}

bool listaCurso::vacia() {
    return primero == nullptr;
}

void listaCurso::vaciar() {
    if (!vacia()) {
        actual = primero;
        primero = primero->getSig();
        delete actual;
    }
}

bool listaCurso::insertarPrimero(curso* c) {
    if (buscarPorId(c->getId())) {
        return false;
    }
    primero = new nodoCurso(c, primero);
    return true;
}

bool listaCurso::insertarFinal(curso* c) {
    if (buscarPorId(c->getId())) {
        return false;
    }
    if (vacia()) {
        primero = new nodoCurso(c, primero);
    }
    else {
        actual = primero;
        while (actual->getSig() != nullptr) {
            actual = actual->getSig();
        }
        actual->setSig(new nodoCurso(c, nullptr));
    }
    return true;
}

bool listaCurso::buscarPorId(string id) {
    if (vacia()) {
        return false;
    }
    actual = primero;
    while (actual != nullptr) {
        if (actual->getCurso()->getId() == id) {
            return true;
        }
        actual = actual->getSig();
    }
    return false;
}

void listaCurso::eliminarCurso(string id) {
    actual = primero;
    if (buscarPorId(id)) {
        if (actual->getCurso()->getId() == id) {
            primero = primero->getSig();
            delete actual;
        }
        else {
            while (actual->getSig()->getCurso()->getId() != id) {
                actual = actual->getSig();
            }
            nodoCurso* nodo = actual->getSig();
            actual->setSig(actual->getSig()->getSig());
            delete nodo;
        }
    }
}

nodoCurso* listaCurso::getPrimero() {
    return primero; 
}

curso* listaCurso::getCurso(string id) {
    actual = primero;
    while (actual != nullptr) {
        if (actual->getCurso()->getId() == id) {
            return actual->getCurso();
        }
        actual = actual->getSig();
    }
    return nullptr;
}

float listaCurso::calcularSubtotal() {
    float subtotal = 0;
    actual = primero;
    while (actual != nullptr) {
        subtotal += actual->getCurso()->getPrecio();
        actual = actual->getSig();
    }
    return subtotal;
}

int listaCurso::cantidadNodos() {
    int count = 0;
    actual = primero; 
    while (actual != nullptr) {
        count++;
        actual = actual->getSig();
    }
    return count;
}

string listaCurso::toString() {
    stringstream s;
    int t = 1;
    actual = primero;
    if (vacia()) {
        s << "No hay informacion que mostrar, la lista esta vacia." << endl;
    }
    else {
        actual = primero; 
        while (actual != nullptr) { 
            if (actual->getCurso() != nullptr) { 
                s << "----------------- " << t << " -----------------" << endl;
                s << actual->toString() << endl;  
                t++;
            }
            actual = actual->getSig();
        }
    }
    return s.str();
}

