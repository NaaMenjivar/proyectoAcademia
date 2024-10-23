#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "listaGrupo.h"
using namespace std;

class curso {
private:
	string nombre;
	string id;
	int horas;
	float precio;
	bool disponible;
	listaGrupo* grupos;
public:
	curso(string, string, int, float, bool, listaGrupo*);
	~curso();

	string getNombre();
	string getId();
	int getHoras();
	float getPrecio();
	bool getDiponibilidad();
	listaGrupo* getGrupos();

	void setNombre(string);
	void setId(string);
	void setHoras(int);
	void setPrecio(float);
	void setDisponibilidad(bool);
	void setGrupos(listaGrupo*);

	bool agregarGrupo(grupo*);
	void eliminarGrupo(int);
	bool buscarGrupo(int);

	string toString();
};