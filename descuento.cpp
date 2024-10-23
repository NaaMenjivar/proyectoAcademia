#include "descuento.h"

//Constructor y Destructor
descuento::descuento(int cursos, float por) : cursosMinimos(cursos), porcentajeDescuento(por) {}
descuento::~descuento() {}

//Métodos Get
int descuento::getCursos() { return cursosMinimos; }
float descuento::getPorcentaje() { return porcentajeDescuento; }

//Métodods Set
void descuento::setCursos(int m) { cursosMinimos = m; }
void descuento::setPorcentaje(float p) { porcentajeDescuento = p;; }

//Método para calcular descuento por cursos
float descuento::calcularDescuento(float subtotal, int cantidad) {
    if (cantidad >= cursosMinimos) {
        return subtotal * (porcentajeDescuento / 100);
    }
    return 0;
}
