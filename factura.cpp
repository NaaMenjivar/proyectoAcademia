#include "factura.h"

//Constructor y Destructor
factura::factura(float sub, float i, descuento* d, int c, int n) : 
    subtotal(sub), iva(i), desc(d), cantCursos(c), numFactura(n), total(0) {}
factura::~factura() {}

//Métodos Get
float factura::getSubtotal() { return subtotal; }
float factura::getIva() { return iva; }
descuento* factura::getDescuento() { return desc; }
int factura::getCantCursos() { return cantCursos; }
float factura::getTotal() { return total; }
int factura::getNumFactura() { return numFactura; }

//Métodos Set
void factura::setSubtotal(float s) { subtotal = s; }
void factura::setIva(float i) { iva = i; }
void factura::setDescuento(descuento* d) { desc = d; }
void factura::setCantCursos(int c) { cantCursos = c; }
void factura::setNumFactura(int n) { numFactura = n; }

//Método para calcular el total
void factura::calcularTotal() {
    float montoDescuento = desc->calcularDescuento(subtotal, cantCursos);
    float subtotalConDescuento = subtotal - montoDescuento;
    float montoIVA = subtotalConDescuento * (iva / 100);
    total = subtotalConDescuento + montoIVA;
    if (total < 0) {
        total = 0;
    }
}

//toString
string factura::toString() {
    stringstream s;
    s << "Factura #:" << numFactura << endl << endl; 
    s << "Subtotal:\n" << subtotal << endl;
    s << "Descuento aplicado:\n" << desc->calcularDescuento(subtotal, cantCursos) << endl;
    s << "IVA:\n" << iva << "%" << endl;
    s << "Total a pagar:\n" << total << endl;
    return s.str();
}
