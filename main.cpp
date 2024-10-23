#include <iostream>
#include "listaPeriodo.h"
#include "periodo.h"

using namespace std;

int main() {
    // Crear objetos periodo
    periodo* periodo1 = new periodo(1);  // Primer trimestre
    periodo* periodo2 = new periodo(2);  // Segundo trimestre
    periodo* periodo3 = new periodo(3);  // Tercer trimestre
    periodo* periodo4 = new periodo(4);  // Cuarto trimestre

    // Crear la lista de periodos
    listaPeriodo listaPeriodos;

    // Test case: Insertar periodos en la lista
    cout << "Agregando periodos a la lista:" << endl;
    if (listaPeriodos.insertarPrimero(periodo1)) {
        cout << "Periodo 1 (Trimestre 1) agregado correctamente al principio." << endl;
    }
    if (listaPeriodos.insertarFinal(periodo2)) {
        cout << "Periodo 2 (Trimestre 2) agregado correctamente al final." << endl;
    }
    if (listaPeriodos.insertarFinal(periodo3)) {
        cout << "Periodo 3 (Trimestre 3) agregado correctamente al final." << endl;
    }
    if (listaPeriodos.insertarFinal(periodo4)) {
        cout << "Periodo 4 (Trimestre 4) agregado correctamente al final." << endl;
    }

    // Mostrar la lista completa
    cout << "\nContenido de la lista de periodos después de agregar periodos:" << endl;
    cout << listaPeriodos.toString() << endl;

    // Test case: Buscar un periodo por su número de trimestre
    int numBuscar = 2;
    cout << "\nBuscando periodo con número de trimestre: " << numBuscar << endl;
    if (listaPeriodos.buscarPorNumPeriodo(numBuscar)) {
        cout << "Periodo encontrado." << endl;
    }
    else {
        cout << "Periodo no encontrado." << endl;
    }

    // Test case: Eliminar un periodo de la lista
    int numEliminar = 1;  // Eliminar el primer periodo
    cout << "\nEliminando periodo con número de trimestre: " << numEliminar << endl;
    listaPeriodos.eliminarPeriodo(numEliminar);

    // Mostrar la lista después de la eliminación
    cout << "\nContenido de la lista de periodos después de eliminar el periodo 1:" << endl;
    cout << listaPeriodos.toString() << endl;

    // Vaciar la lista
    cout << "\nVaciando la lista de periodos..." << endl;
    listaPeriodos.vaciarLista();
    cout << "Lista vaciada correctamente." << endl;

    // Mostrar la lista vacía
    cout << "\nContenido de la lista de periodos después de vaciarla:" << endl;
    cout << listaPeriodos.toString() << endl;

    // Liberar memoria
    delete periodo1;
    delete periodo2;
    delete periodo3;
    delete periodo4;

    return 0;
}


