#include <iostream>
#include <fstream>
#include <string>
#include "academia.h"
#include "interfaz.h"
#include "archivo.h"
using namespace std;

int main() {
    academia acad;
    interfaz inter;

    inter.menuPrincipal();

    // Guardar datos en archivos físicos antes de salir
    acad.guardarDatos();

    return 0;
}










