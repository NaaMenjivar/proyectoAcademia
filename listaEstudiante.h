#include "nodoEstudiante.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class listaEstudiante {
private:
	nodoEstudiante* primero;
	nodoEstudiante* actual;
public:
	listaEstudiante();
	~listaEstudiante();
	bool insertarPrimero(estudiante*);
	bool insertarFinal(estudiante*);
	bool buscarPorId(string);
	bool esVacia();
	void eliminarEstudiante(string);
	void vaciarLista();
	string toString();
};