#include "periodo.h"

//Constructor y Destructor
periodo::periodo(int num) : numTrimestre(num), grupos(new listaGrupo()), cursos(new listaCurso()) {
    switch (numTrimestre) {
    case 1:
        nombre = "Periodo I";
        mesInicio = "Enero";
        mesFin = "Marzo";
        break;
    case 2:
        nombre = "Periodo II";
        mesInicio = "Abril";
        mesFin = "Junio";
        break;
    case 3:
        nombre = "Periodo III";
        mesInicio = "Julio";
        mesFin = "Septiembre";
        break;
    case 4:
        nombre = "Periodo IV";
        mesInicio = "Octubre";
        mesFin = "Diciembre";
        break;
    default:
        throw invalid_argument("Número de trimestre inválido");
    }
}
periodo::~periodo() {
    delete grupos;
    delete cursos;
}

//Métodos Get
string periodo::getNombre() { return nombre; }
string periodo::getMesInicio() { return mesInicio; }
string periodo::getMesFin() { return mesFin; }
int periodo::getNumTrimestre() { return numTrimestre; }
listaGrupo* periodo::getGrupos() { return grupos; }
listaCurso* periodo::getCursos() { return cursos; }

//Métodos Set
void periodo::setNombre(string n) { nombre = n; }
void periodo::setMesInicio(string m) { mesInicio = m; }
void periodo::setMesFin(string m) { mesFin = m; }
void periodo::setNumTrimestre(int n) { numTrimestre = n; }

bool periodo::agregarGrupo(grupo* g) {
    return grupos->insertarPrimero(g);
}

bool periodo::buscarGrupo(int n) {
    return grupos->buscarPorNumGrupo(n);
}

void periodo::eliminarGrupo(int n) {
    grupos->eliminarGrupo(n);
}

bool periodo::agregarCurso(curso* c) {
    return cursos->insertarPrimero(c);
}

bool periodo::buscarCurso(string id) {
    return cursos->buscarPorId(id);
}

void periodo::eliminarCurso(string id) {
    cursos->eliminarCurso(id);
}

string periodo::toString() {
    stringstream s;
    s << "Nombre del periodo: " << nombre << " (" << mesInicio << " - " << mesFin << ")" << endl;
    s << "Cursos disponibles:\n" << cursos->toString() << endl;
    s << "Grupos disponibles:\n" << grupos->toString() << endl;
    return s.str();
}
