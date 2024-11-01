#pragma once
#include "nodoGrupo.h"
#include "grupo.h"
#include "horario.h"
#include "profesor.h"
#include "listaEstudiante.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class nodoGrupo;
class grupo;
class horario;
class profesor;
class listaEstudiante;

class listaGrupo {
private:
	nodoGrupo* actual;
	nodoGrupo* primero;
public:
	listaGrupo();
	~listaGrupo();
	bool vacia();
	void vaciar();
	bool insertarPrimero(grupo*);
	bool insertarFinal(grupo*);
	bool buscarPorNumGrupo(int);
	void eliminarGrupo(int);
	grupo* getGrupo(int);
	nodoGrupo* getPrimero();
	nodoGrupo* getSig(nodoGrupo*);
	string toString();
};