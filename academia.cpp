#include "academia.h"

// Constructor
academia::academia() {
    cursos = new listaCurso();
    grupos = new listaGrupo();
    estudiantes = new listaEstudiante();
    profesores = new listaProfesor();
    periodos = new listaPeriodo();
}

// Destructor
academia::~academia() {
    delete cursos;
    delete grupos;
    delete estudiantes;
    delete profesores; 
    delete periodos; 
}

//Métodos de acceso a las listas
listaCurso* academia::getCursos() {
    return cursos;
}

listaGrupo* academia::getGrupos() {
    return grupos;
}

listaEstudiante* academia::getEstudiantes() {
    return estudiantes;
}

listaProfesor* academia::getProfesores() {
    return profesores;
}

listaPeriodo* academia::getPeriodos() {
    return periodos;
}

// Métodos de administración de listas
bool academia::agregarCurso(curso* c) {
    return cursos->insertarFinal(c);
}

bool academia::eliminarCurso(string id) {
    if (!cursos->buscarPorId(id)) {
        return false;
    }
    cursos->eliminarCurso(id);
    return true;
}

bool academia::buscarCurso(string id) {
    return cursos->buscarPorId(id);
}

string academia::listarCursos() {
    return cursos->toString();
}

bool academia::agregarGrupo(grupo* g, int numPeriodo) {
    periodo* p = periodos->buscarPorNumPeriodo(numPeriodo) ? periodos->getPeriodo(numPeriodo) : nullptr;
    if (p) return p->getGrupos()->insertarFinal(g);
    return false;
}

bool academia::eliminarGrupo(int numGrupo) {
    if (!grupos->buscarPorNumGrupo(numGrupo)) {
        return false;
    }
    grupos->eliminarGrupo(numGrupo);
    return true;
}

bool academia::buscarGrupo(int numGrupo) {
    return grupos->buscarPorNumGrupo(numGrupo);
}

string academia::listarGrupos() {
    return grupos->toString();
}

bool academia::agregarEstudiante(estudiante* e) {
    return estudiantes->insertarFinal(e);
}

bool academia::eliminarEstudiante(string id) {
    if (!estudiantes->buscarPorId(id)) {
        return false;
    }
    estudiantes->eliminarEstudiante(id);
    return true;
}

bool academia::buscarEstudiante(string id) {
    return estudiantes->buscarPorId(id);
}

string academia::listarEstudiantes() {
    return estudiantes->toString();
}

bool academia::agregarProfesor(profesor* p) {
    return profesores->insertarFinal(p);
}

bool academia::eliminarProfesor(string id) {
    if (!profesores->buscarPorId(id)) {
        return false;
    }
    profesores->eliminarProfesor(id);
    return true;
}

bool academia::buscarProfesor(string id) {
    return profesores->buscarPorId(id);
}

string academia::listarProfesores() {
    return profesores->toString();
}

bool academia::agregarPeriodo(periodo* p) {
    return periodos->insertarFinal(p);
}

bool academia::eliminarPeriodo(int num) {
    if (!periodos->buscarPorNumPeriodo(num)) {
        return false;
    }
    periodos->eliminarPeriodo(num);
    return true;
}

bool academia::buscarPeriodo(int num) {
    return periodos->buscarPorNumPeriodo(num);
}

string academia::listarPeriodos() {
    return periodos->toString();
}

// Métodos de matrícula
bool academia::matricularEstudianteEnCurso(string idEstudiante, string idCurso, int numGrupo) {
    curso* c = cursos->buscarPorId(idCurso) ? cursos->getCurso(idCurso) : nullptr;
    if (!c) {
        return false;
    }
    grupo* g = c->getGrupos()->buscarPorNumGrupo(numGrupo) ? c->getGrupos()->getGrupo(numGrupo) : nullptr;
    estudiante* e = estudiantes->buscarPorId(idEstudiante) ? estudiantes->getEstudiante(idEstudiante) : nullptr;
    if (g && e) {
        return g->agregarEstudiante(e);
    }
    return false;
}

bool academia::desmatricularEstudiante(string idEstudiante, string idCurso, int numGrupo) {
    curso* c = cursos->buscarPorId(idCurso) ? cursos->getCurso(idCurso) : nullptr;
    if (!c) {
        return false;
    }
    grupo* g = c->getGrupos()->buscarPorNumGrupo(numGrupo) ? c->getGrupos()->getGrupo(numGrupo) : nullptr;
    if (g) {
        g->eliminarEstudiante(idEstudiante);
        return true;
    }
    return false;
}

int academia::calcularCursosAnuales(string idEstudiante) {
    int totalCursos = 0;
    nodoPeriodo* nodoActual = periodos->getPrimero(); 

    while (nodoActual != nullptr) {
        periodo* p = nodoActual->getPeriodo();
        totalCursos += p->contarCursosMatriculadosEstudiante(idEstudiante);
        nodoActual = periodos->getSig(nodoActual); 
    }
    return totalCursos;
}

float academia::calcularDescuentoAnual(string idEstudiante) {
    int cursosAnuales = calcularCursosAnuales(idEstudiante);
    if (cursosAnuales >= 4) {
        return 25;
    }
    return 0;
}

string academia::generarFactura(string idEstudiante, int numPeriodo) {
    periodo* p = periodos->getPeriodo(numPeriodo);
    if (!p) {
        return "Error: El periodo no existe.";
    }
    int cursosEnPeriodo = p->getCursos()->cantidadNodos();
    float subtotal = p->getCursos()->calcularSubtotal(); 
    descuento* descuentoPeriodo = p->getDescuentoPorCursos(); 
    float porcentajeDescuentoAnual = calcularDescuentoAnual(idEstudiante); 
    float totalDescuento = descuentoPeriodo->getPorcentaje() + porcentajeDescuentoAnual; 
    float montoDescuento = subtotal * (totalDescuento / 100);
    float subtotalConDescuento = subtotal - montoDescuento;
    float iva = 13;
    float montoIVA = subtotalConDescuento * (iva / 100);
    float total = subtotalConDescuento + montoIVA;

    factura* f = new factura(subtotal, iva, descuentoPeriodo, cursosEnPeriodo);
    f->calcularTotal(total); 

    return f->toString();
}

// Métodos de informes
string academia::informeProfesores() {
    return profesores->toString();
}

string academia::informeEstudiantes() {
    return estudiantes->toString();
}

string academia::informeCursosMatriculadosEstudiante(string idEstudiante) {
    estudiante* e = estudiantes->buscarPorId(idEstudiante) ? estudiantes->getEstudiante(idEstudiante) : nullptr;
    return e ? e->toString() : "Estudiante no encontrado.";
}

string academia::informeProfesorEspecifico(string idProfesor) {
    profesor* p = profesores->buscarPorId(idProfesor) ? profesores->getProfesor(idProfesor) : nullptr;
    return p ? p->toString() : "Profesor no encontrado.";
}

string academia::informePeriodos() {
    return periodos->toString();
}

string academia::informeGrupoEspecifico(string idCurso, int numGrupo) {
    curso* c = cursos->buscarPorId(idCurso) ? cursos->getCurso(idCurso) : nullptr;
    if (!c) {
        return "Curso no encontrado.";
    }
    grupo* g = c->getGrupos()->buscarPorNumGrupo(numGrupo) ? c->getGrupos()->getGrupo(numGrupo) : nullptr;
    return g ? g->toString() : "Grupo no encontrado.";
}

