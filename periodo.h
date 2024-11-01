#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "listaGrupo.h"
#include "listaCurso.h"
#include "descuento.h"
using namespace std;

class periodo {
	string nombre;
	string mesInicio;
	string mesFin;
	int numTrimestre;
	listaGrupo* grupos;
	listaCurso* cursos;
public:
	periodo(int);
	~periodo();

	string getNombre();
	string getMesInicio();
	string getMesFin();
	int getNumTrimestre();
	listaGrupo* getGrupos();
	listaCurso* getCursos();

	void setNombre(string);
	void setMesInicio(string);
	void setMesFin(string);
	void setNumTrimestre(int);

	bool agregarGrupo(grupo*);
	bool buscarGrupo(int);
	void eliminarGrupo(int);

	bool agregarCurso(curso*);
	bool buscarCurso(string);
	void eliminarCurso(string);

	descuento* getDescuentoPorCursos();
	int contarCursosMatriculadosEstudiante(string);

	string toString();
};