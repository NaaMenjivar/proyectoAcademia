#include "nodoEstudiante.h"

//Constructor y Desstructor
nodoEstudiante::nodoEstudiante(estudiante* e, nodoEstudiante* s) : est(e), sig(s) {}
nodoEstudiante::~nodoEstudiante() { delete est; }

//Métodos Get
estudiante* nodoEstudiante::getEstudiante() { return est; }
nodoEstudiante* nodoEstudiante::getSiguiente() { return sig; }

//Métodos Set 
void nodoEstudiante::setEstudiante(estudiante* e) { est = e; }
void nodoEstudiante::setSiguiente(nodoEstudiante* s) { sig = s; }
