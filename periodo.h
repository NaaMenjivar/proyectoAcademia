#ifndef PERIODO_H
#define PERIODO_H
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

	void setCursos(listaCurso*);
	bool agregarGrupo(grupo*);
	bool buscarGrupo(int);
	void eliminarGrupo(int);

	void setGrupos(listaGrupo*);
	bool agregarCurso(curso*);
	bool buscarCurso(string);
	void eliminarCurso(string);

	descuento* getDescuentoPorCursos();
	int contarCursosMatriculadosEstudiante(string); 

	string toString();
};

#endif