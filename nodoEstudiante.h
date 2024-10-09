#pragma once
#include "estudiante.h"

class nodoEstudiante {
private:
    estudiante* est;
    nodoEstudiante* sig;

public:
    nodoEstudiante(estudiante* e, nodoEstudiante* s);
    ~nodoEstudiante();

    estudiante* getEstudiante();
    nodoEstudiante* getSiguiente();

    void setEstudiante(estudiante* e);
    void setSiguiente(nodoEstudiante* s);
};

