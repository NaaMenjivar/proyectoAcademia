#pragma once
#include "profesor.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class nodoProfesor {
private:
	profesor* prof;
	nodoProfesor* sig;
public:
	nodoProfesor(profesor*, nodoProfesor*);
	~nodoProfesor();

	profesor* getProfesor();
	nodoProfesor* getSiguiente();

	void setProfesor(profesor*);
	void setSiguiente(nodoProfesor*);

	string toString();
};