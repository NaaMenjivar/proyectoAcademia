#pragma once
#include "curso.h"

class nodoCurso {
private:
	curso* curs;
	nodoCurso* sig;
public:
	nodoCurso(curso*, nodoCurso*);
	~nodoCurso();
	curso* getCurso();
	nodoCurso* getSig();
	void setCurso(curso*);
	void setSig(nodoCurso*);
	string toString();
};