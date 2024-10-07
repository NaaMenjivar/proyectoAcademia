#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class estudiante {
private:
    string nombre;
    string id;               
    string especialidad;  
    string telefono;      
    string email; 

public:
    estudiante(string, string, string, string, string);
    ~estudiante();

    string getNombre();
    string getId();
    string getEspecialidad();
    string getTelefono();
    string getEmail();

    void setNombre(string);
    void setId(string);
    void setEspecialidad(string);
    void setTelefono(string);
    void setEmail(string);

    string toString();
};
