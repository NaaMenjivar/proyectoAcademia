#include "grupo.h"

//Constructor y Destructor
grupo::grupo(int n, int c, int a, horario* h, profesor* p) :
    numeroGrupo(n), capacidad(c), cantidadAlumnos(a), h(h), p(p), estudiantes(new listaEstudiante()) {}
grupo::~grupo() {
    if (estudiantes != nullptr) { 
        delete estudiantes; 
    }
}

//Métodos Get
int grupo::getNumeroGrupo() { return numeroGrupo; }
int grupo::getCapacidad() { return capacidad; }
int grupo::getCantidadAlumnos() { return cantidadAlumnos; }
horario* grupo::getHorario() { return h; }
profesor* grupo::getProfesor() { return p; }
listaEstudiante* grupo::getEstudiantes() { return estudiantes; }

//Métodos Set
void grupo::setNumeroGrupo(int num) { numeroGrupo = num; }
void grupo::setCapacidad(int cap) { capacidad = cap; }
void grupo::setCantidadAlumnos(int cant) { cantidadAlumnos = cant; }
void grupo::setHorario(horario* hor) { h = hor; }
void grupo::setProfesor(profesor* prof) { p = prof; }
void grupo::setEstudiantes(listaEstudiante* e) { estudiantes = e; }

//Modificadores de estudiantes
bool grupo::agregarEstudiante(estudiante* e){
    return estudiantes->insertarPrimero(e);
}
void grupo::eliminarEstudiante(string id) {
    estudiantes->eliminarEstudiante(id);
}
bool grupo::buscarEstudiante(string id) {
    return estudiantes->buscarPorId(id);
}

//toString
string grupo::toString() {
    stringstream s;
    s << "Numero de grupo:\n" << numeroGrupo << endl;
    s << "Capacidad:\n" << capacidad << endl;
    s << "Cantidad de alumnos:\n" << cantidadAlumnos << endl;
    s << "Horario del grupo:\n" << h->toString() << endl;
    s << "Profesor asignado:\n" << p->toString() << endl;
    s << "Lista de estudiantes:\n" << estudiantes->toString() << endl;
    return s.str();
}
