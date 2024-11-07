#pragma once
#include "nodoCurso.h"
#include "curso.h"
#include "listaGrupo.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class nodoCurso;
class curso;
class listaGrupo;

class listaCurso {
private:
	nodoCurso* actual;
	nodoCurso* primero;
public:
	listaCurso();
	~listaCurso();
	bool vacia();
	void vaciar();
	bool insertarPrimero(curso*);
	bool insertarFinal(curso*);
	bool buscarPorId(string);
	void eliminarCurso(string);
	nodoCurso* getPrimero();
	curso* getCurso(string id);
	float calcularSubtotal();
	int cantidadNodos();
	string toString();
};
