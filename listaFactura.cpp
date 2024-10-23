#include "listaFactura.h"

listaFactura::listaFactura() : primero(nullptr), actual(nullptr) {}
listaFactura::~listaFactura() {
    if (!vacia()) {
        vaciar();
    }
}

bool listaFactura::insertarPrimero(factura* f){
    if (buscarPorNumFactura(f->getNumFactura())) {
        return false;
    }
    primero = new nodoFactura(f, primero);
    return true;
}

bool listaFactura::insertarFinal(factura* f) {
    if (buscarPorNumFactura(f->getNumFactura())) {
        return false;
    }
    if (vacia()) {
        primero = new nodoFactura(f, primero);
    }
    else {
        actual = primero;
        while (actual->getSig() != nullptr) {
            actual = actual->getSig();
        }
        actual->setSig(new nodoFactura(f, nullptr));
    }
    return true;
}

bool listaFactura::buscarPorNumFactura(int num) {
    if (vacia()) {
        return false;
    }
    actual = primero;
    while (actual != nullptr) {
        if (actual->getFactura()->getNumFactura() == num) {
            return true;
        }
        actual = actual->getSig();
    }
    return false;
}

bool listaFactura::vacia() {
    return primero == nullptr;
}

void listaFactura::vaciar() {
    if (!vacia()) {
        actual = primero;
        primero = primero->getSig();
        delete actual;
    }
}

void listaFactura::eliminarFactura(int num) {
    actual = primero;
    if (buscarPorNumFactura(num)) {
        if (actual->getFactura()->getNumFactura() == num) {
            primero = primero->getSig();
            delete actual;
        }
        else {
            while (actual->getSig()->getFactura()->getNumFactura() != num) {
                actual = actual->getSig();
            }
            nodoFactura* nodo = actual->getSig();
            actual->setSig(actual->getSig()->getSig());
            delete nodo;
        }
    }
}

string listaFactura::toString() {
    stringstream s;
    int t = 1;
    if (vacia()) {
        s << "No hay informacion que mostrar, la lista esta vacia." << endl;
    }
    else {
        actual = primero;
        while (actual != nullptr) {
            s << "----------------- " << t << " -----------------" << endl;
            s << actual->toString() << endl;
            t++;
            actual = actual->getSig();
        }
    }
    return s.str();
}
