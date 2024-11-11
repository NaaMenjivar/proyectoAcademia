#ifndef INTERFAZ_H
#define INTERFAZ_H
#pragma once
#include "academia.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class interfaz {
private:
	academia* acad;
public:
	interfaz();
	~interfaz();
	
	//Menú Principal
	void menuPrincipal();

	//Submenús
	void submenuAdministracion();
	void submenuMatricula();
	void submenuInformes();

	//Métodos para ingresar
	void ingresarProfesor();
	void ingresarEstudiante();
	void ingresarPeriodo();
	void ingresarCurso(); 
	void ingresarGrupo();
	void asignarProfesorAGrupo();

	//Métodos de matrícula
	void matricularEstudiante();
	void desmatricularEstudiante();

	//Métodos para mostrar
	void mostrarInformeProfesores();
	void mostrarInformeEstudiantes();
	void mostrarInformeCursosEstudiante();
	void mostrarInformeProfesorEspecifico();
	void mostrarInformePeriodos();
	void mostrarInformeGrupoEspecifico();

};

#endif