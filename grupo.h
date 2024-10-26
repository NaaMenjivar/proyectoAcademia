#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "profesor.h"
#include "listaEstudiante.h"
#include "horario.h"
using namespace std;

class grupo {
private:
	int numeroGrupo;
	int capacidad;
	int cantidadAlumnos;
	horario* h;
	profesor* p;
	listaEstudiante* estudiantes;
public:
	grupo(int, int, int, horario*, profesor*);
	~grupo();

	int getNumeroGrupo();
	int getCapacidad();
	int getCantidadAlumnos();
	horario* getHorario();
	profesor* getProfesor();
	listaEstudiante* getEstudiantes();

	void setNumeroGrupo(int);
	void setCapacidad(int);
	void setCantidadAlumnos(int);
	void setHorario(horario*);
	void setProfesor(profesor*);
	void setEstudiantes(listaEstudiante*);

	bool agregarEstudiante(estudiante*);
	void eliminarEstudiante(string);
	bool buscarEstudiante(string);

	string toString();
};