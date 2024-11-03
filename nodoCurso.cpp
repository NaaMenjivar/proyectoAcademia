#include "nodoCurso.h"

//Constructor y Destructor
nodoCurso::nodoCurso(curso* c, nodoCurso* s) : curs(c), sig(s) {}
nodoCurso::~nodoCurso() { delete curs; }

//Métodos Get
curso* nodoCurso::getCurso() { return curs; }
nodoCurso* nodoCurso::getSig() { return sig; }

//Métodos Set
void nodoCurso::setCurso(curso* c) { curs = c; }
void nodoCurso::setSig(nodoCurso* s) { sig = s; }

//toString
string nodoCurso::toString() {
    return curs->toString();
}
