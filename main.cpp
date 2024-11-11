#include <iostream>
#include <fstream>
#include <string>
#include "academia.h"
#include "interfaz.h"
#include "archivo.h"
using namespace std;

int main() {
    academia* acad = new academia();
    interfaz* inter = new interfaz();

    inter->menuPrincipal();

    // Guardar datos en archivos físicos antes de salir
    acad->guardarDatos();

    delete acad;
    delete inter;

    return 0;
}










