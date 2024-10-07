#include "estudiante.h"

//Constructor y Destructor
estudiante::estudiante(string n, string i, string e, string t, string m) : 
    nombre(n), id(i), especialidad(e), telefono(t), email(m) {}

estudiante::~estudiante() {}

//Métodos Get
string estudiante::getNombre() { return nombre; }
string estudiante::getId() { return id; }
string estudiante::getEspecialidad() { return especialidad; }
string estudiante::getTelefono() { return telefono; }
string estudiante::getEmail() { return email; }

//Métodos Set
void estudiante::setNombre(string n) { nombre = n; }
void estudiante::setId(string i) { id = i; }
void estudiante::setEspecialidad(string e) { especialidad = e; }
void estudiante::setTelefono(string t) { telefono = t; }
void estudiante::setEmail(string e) { email = e; }

//toString
string estudiante::toString() {
    stringstream r;
    r << "Nombre:\n" << nombre << endl;
    r << "ID:\n" << id << endl;
    r << "Especialidad o carrera:\n" << especialidad << endl;
    r << "Telefono:\n" << telefono << endl;
    r << "Email:\n" << email << endl;
    
    return r.str();
}
