#include "listaGrupo.h"

listaGrupo::listaGrupo() : actual(nullptr), primero(nullptr) {}
listaGrupo::~listaGrupo() {
    if (!vacia()) {
        vaciar();
    }
}

bool listaGrupo::vacia() {
    return primero == nullptr;
}

void listaGrupo::vaciar() {
    if (!vacia()) {
        actual = primero;
        primero = primero->getSig();
        delete actual;
    }
}

bool listaGrupo::insertarPrimero(grupo* g) {
    if (buscarPorNumGrupo(g->getNumeroGrupo())) {
        return false;
    }
    primero = new nodoGrupo(g, primero);
    return true;
}

bool listaGrupo::insertarFinal(grupo* g) {
    if (buscarPorNumGrupo(g->getNumeroGrupo())) {
        return false;
    }
    if (vacia()) {
        primero = new nodoGrupo(g, primero);
    }
    else {
        actual = primero;
        while (actual->getSig() != nullptr) {
            actual = actual->getSig();
        }
        actual->setSig(new nodoGrupo(g, nullptr));
    }
    return true;
}

bool listaGrupo::buscarPorNumGrupo(int num) {
    if (vacia()) {
        return false;
    }
    actual = primero;
    while (actual != nullptr) {
        if (actual->getGrupo()->getNumeroGrupo() == num) {
            return true;
        }
        actual = actual->getSig();
    }
    return false;
}

void listaGrupo::eliminarGrupo(int num) {
    actual = primero;
    if (buscarPorNumGrupo(num)) {
        if (actual->getGrupo()->getNumeroGrupo() == num) {
            primero = primero->getSig();
            delete actual;
        }
        else {
            while (actual->getSig()->getGrupo()->getNumeroGrupo() != num) {
                actual = actual->getSig();
            }
            nodoGrupo* nodo = actual->getSig();
            actual->setSig(actual->getSig()->getSig());
            delete nodo;
        }
    }
}

string listaGrupo::toString() {
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
