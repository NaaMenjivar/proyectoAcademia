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
	
	//Menú Principal
	void menuPrincipal();

	//Submenús
	void submenuAdministracion();
	void submenuMatricula();
	void submenuInformes();
	void guardarDatos();

	//Métodos para ingresar
	void ingresarProfesor();
	void ingresarEstudiante();
	void ingresarPeriodo();
	void agregarCurso(); 
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

	//Métodos para guardar datos

};