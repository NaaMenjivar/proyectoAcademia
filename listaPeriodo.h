#pragma once
#include "periodo.h"
#include <iostream>
#include <sstream>
#include <string>
#include "listaGrupo.h"
#include "listaCurso.h"
#include "nodoPeriodo.h"

class periodo;
class nodoPeriodo;
class listaGrupo;
class listaCurso;

class listaPeriodo {
private:
	nodoPeriodo* primero;
	nodoPeriodo* actual;
public:
	listaPeriodo();
	~listaPeriodo();
	bool insertarPrimero(periodo*);
	bool insertarFinal(periodo*);
	bool buscarPorNumPeriodo(int);
	bool esVacia();
	void eliminarPeriodo(int);
	void vaciarLista();
	string toString();
};