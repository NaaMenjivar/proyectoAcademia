#include "factura.h"

//Constructor y Destructor
factura::factura(float sub, float i, descuento* d, int c) : 
    subtotal(sub), iva(i), desc(d), cantCursos(c), total(0) {}
factura::~factura() {}

//Métodos Get
float factura::getSubtotal() { return subtotal; }
float factura::getIva() { return iva; }
descuento* factura::getDescuento() { return desc; }
int factura::getCantCursos() { return cantCursos; }
float factura::getTotal() { return total; }

//Métodos Set
void factura::setSubtotal(float s) { subtotal = s; }
void factura::setIva(float i) { iva = i; }
void factura::setDescuento(descuento* d) { desc = d; }
void factura::setCantCursos(int c) { cantCursos = c; }

//Método para calcular el total
void factura::calcularTotal(float total) { this->total = total; }

//toString
string factura::toString() {
    stringstream s;
    s << "Factura:\t\t" << endl; 
    s << "Subtotal:\t\t" << subtotal << endl; 
    s << "Descuento aplicado:\t\t" << desc->calcularDescuento(subtotal, cantCursos) << endl;
    s << "IVA:\t\t" << iva << "%" << endl;
    s << "Total a pagar:\t\t" << total << endl;
    return s.str();
}
