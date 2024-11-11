#include "academia.h"

// Constructor
academia::academia() {
    archivos = new archivo();
    estudiantes = (archivos->recuperarEstudiantes()) ? archivos->recuperarEstudiantes() : new listaEstudiante();
    cursos = (archivos->recuperarCursos()) ? archivos->recuperarCursos() : new listaCurso();
    grupos = (archivos->recuperarGrupos()) ? archivos->recuperarGrupos() : new listaGrupo();
    profesores = (archivos->recuperarProfesores()) ? archivos->recuperarProfesores() : new listaProfesor(); 
    periodos = (archivos->recuperarPeriodos()) ? archivos->recuperarPeriodos() : new listaPeriodo(); 

}

// Destructor
academia::~academia() {
    archivos->guardarEstudiantes(estudiantes);
    archivos->guardarProfesores(profesores); 
    archivos->guardarGrupos(grupos);
    archivos->guardarCursos(cursos);
    archivos->guardarPeriodos(periodos);
    delete cursos;
    delete grupos;
    delete estudiantes;
    delete profesores; 
    delete periodos; 
    delete archivos;
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
    if (p) {
        return p->getGrupos()->insertarFinal(g) && grupos->insertarPrimero(g);
    }
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
    if (!e) {
        return "Estudiante no encontrado.";
    }

    stringstream ss;
    ss << "Cursos matriculados para " << e->getNombre() << " (ID: " << e->getId() << "):\n"; 
    bool cursosEncontrados = false;

    for (nodoCurso* nodoCursoActual = cursos->getPrimero(); nodoCursoActual != nullptr; nodoCursoActual = nodoCursoActual->getSig()) {
        curso* cursoActual = nodoCursoActual->getCurso();
        for (nodoGrupo* nodoGrupoActual = cursoActual->getGrupos()->getPrimero(); nodoGrupoActual != nullptr; nodoGrupoActual = nodoGrupoActual->getSig()) {
            grupo* grupoActual = nodoGrupoActual->getGrupo(); 

            if (grupoActual->buscarEstudiante(idEstudiante)) {
                cursosEncontrados = true; 
                ss << "- Curso: " << cursoActual->getNombre() << " (ID: " << cursoActual->getId() << ")\n"; 
                ss << "  Grupo: " << grupoActual->getNumeroGrupo() << "\n"; 
                ss << "  Horario: " << grupoActual->getHorario()->toString() << "\n\n"; 
            }
        }
    }

    if (!cursosEncontrados) { 
        ss << "No se encontraron cursos matriculados para este estudiante.\n";
    }

    return ss.str();
}


string academia::informeProfesorEspecifico(string idProfesor) {
    profesor* p = profesores->buscarPorId(idProfesor) ? profesores->getProfesor(idProfesor) : nullptr;
    if (!p) {
        return "Profesor no encontrado.";
    }

    stringstream ss;
    ss << "Datos del Profesor: \n";
    ss << p->toString() << "\n\n";
    ss << "Cursos y grupos impartidos por el profesor:\n";

    bool cursosEncontrados = false;

    for (nodoCurso* nodoCursoActual = cursos->getPrimero(); nodoCursoActual != nullptr; nodoCursoActual = nodoCursoActual->getSig()) { 
        curso* cursoActual = nodoCursoActual->getCurso();
        bool gruposImpartidos = false;
        for (nodoGrupo* nodoGrupoActual = cursoActual->getGrupos()->getPrimero(); nodoGrupoActual != nullptr; nodoGrupoActual = nodoGrupoActual->getSig()) {
            grupo* grupoActual = nodoGrupoActual->getGrupo();

            if (grupoActual->getProfesor()->getId() == idProfesor) {
                if (!gruposImpartidos) {
                    ss << "- Curso: " << cursoActual->getNombre() << " (ID: " << cursoActual->getId() << ")\n";
                    gruposImpartidos = true;
                    cursosEncontrados = true;
                }
                ss << "  Grupo: " << grupoActual->getNumeroGrupo() << "\n";
                ss << "  Horario: " << grupoActual->getHorario()->toString() << "\n";
                ss << "  Capacidad: " << grupoActual->getCapacidad() << "\n";
            }
        }
    }

    if (!cursosEncontrados) {
        ss << "No se encontraron cursos ni grupos impartidos por este profesor.\n";
    }

    return ss.str();
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
    if (!g) {
        return "Grupo no encontrado.";
    }

    stringstream informe;
    informe << "----- Detalle del Grupo -----\n";
    informe << "Nombre del Curso: " << c->getNombre() << "\n"; 
    informe << "Numero de Grupo: " << g->getNumeroGrupo() << "\n"; 
    informe << "Capacidad del Grupo: " << g->getCapacidad() << "\n"; 
    informe << "Horario: " << g->getHorario()->toString() << "\n"; 

    if (g->getProfesor()) {
        informe << "Profesor a Cargo: " << g->getProfesor()->getNombre() << " (ID: " << g->getProfesor()->getId() << ")\n";
    }
    else {
        informe << "Profesor a Cargo: No asignado\n";
    }

    listaEstudiante* estudiantes = g->getEstudiantes();
    if (estudiantes && !estudiantes->esVacia()) {
        informe << "Estudiantes Matriculados:\n";
        nodoEstudiante* actual = estudiantes->getPrimero();
        while (actual) {
            informe << "- " << actual->getEstudiante()->toString() << "\n";
            actual = actual->getSiguiente();
        }
    }
    else {
        informe << "Estudiantes Matriculados: Ninguno\n";
    }

    return informe.str();
}

void academia::guardarDatos() {
    archivos->guardarEstudiantes(estudiantes);
    archivos->guardarProfesores(profesores);
    archivos->guardarGrupos(grupos);
    archivos->guardarCursos(cursos);
    archivos->guardarPeriodos(periodos);  
}



