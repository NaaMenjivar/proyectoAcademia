#pragma once
#include "grupo.h"

class nodoGrupo {
private:
	grupo* grup;
	nodoGrupo* sig;
public:
	nodoGrupo(grupo*, nodoGrupo*);
	~nodoGrupo();
	grupo* getGrupo();
	nodoGrupo* getSig();
	void setGrupo(grupo*);
	void setSig(nodoGrupo*);
	string toString();
};