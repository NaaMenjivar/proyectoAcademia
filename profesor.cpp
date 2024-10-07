#include "profesor.h"

//Constructor y Destructor
profesor::profesor(string n, string i, string t, string e, string g) : 
    nombre(n), id(i), telefono(t), email(e), gradoAcademico(g) {}

profesor::~profesor(){}

//Métodos Get
string profesor::getNombre() { return nombre; }
string profesor::getId() { return id; }
string profesor::getTelefono() { return telefono; }
string profesor::getEmail() { return email; }
string profesor::getGradoAcademico() { return gradoAcademico; }

//Métodos Set
void profesor::setNombre(string n) { nombre = n; }
void profesor::setId(string i) { id = i; }
void profesor::setTelefono(string t) { telefono = t; }
void profesor::setEmail(string e) { email = e; }
void profesor::setGradoAcademico(string g) { gradoAcademico = g; }

//toString
string profesor::toString() {
    stringstream k;
    k << "Nombre:\n" << nombre << endl;
    k << "ID:\n" << id << endl;
    k << "Telefono:\n" << telefono << endl;
    k << "Email:\n" << email << endl;
    k << "Grado academico:\n" << gradoAcademico << endl;

    return k.str();
}
