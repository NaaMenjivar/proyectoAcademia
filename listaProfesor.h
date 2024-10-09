#pragma once
#include "nodoProfesor.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class listaProfesor {
private:
	nodoProfesor* primero;
	nodoProfesor* actual;
public:
	listaProfesor();
	~listaProfesor();
	bool insertarPrimero(profesor*);
	bool insertarFinal(profesor*);
	string toString();
	bool buscarPorId(string);
	bool esVacia();
	void eliminarProfesor(string);
	void vaciarLista();
};