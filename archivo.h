#ifndef ARCHIVO_H
#define ARCHIVO_H
#pragma once
#include "listaEstudiante.h"
#include "listaCurso.h"
#include "listaProfesor.h"
#include "listaPeriodo.h"
#include "conversionDatos.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class archivo
{
private:
	ifstream entrada;
	ifstream entradaAux;
	ifstream entradaAux2;
	ofstream salidaAux;
	ofstream salidaAux2;
	ofstream salida;
	conversionDatos conv;
public:
	void guardarEstudiantes(listaEstudiante*);
	void guardarProfesores(listaProfesor*);
	void guardarGrupos(listaGrupo*);
	void guardarCursos(listaCurso*);
	void guardarPeriodos(listaPeriodo*);
	void guardarEstudiantesGrupo(listaEstudiante*, int);
	void guardarGruposCurso(listaGrupo*, string);
	void guardarGruposPeriodo(listaGrupo*, int);
	void guardarCursosPeriodo(listaCurso*, int);
	listaEstudiante* recuperarEstudiantes();
	listaProfesor* recuperarProfesores(); 
	listaGrupo* recuperarGrupos();
	listaCurso* recuperarCursos();
	listaPeriodo* recuperarPeriodos();
	listaEstudiante* recuperarEstudiantesGrupo(int);
	listaGrupo* recuperarGruposCurso(string);
	listaGrupo* recuperarGruposPeriodo(int);
	listaCurso* recuperarCursosPeriodo(int);
};

#endif