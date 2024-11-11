#ifndef PROFESOR_H 
#define PROFESOR_H
#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class profesor {
private:
    string nombre;        
    string id;             
    string telefono;       
    string email;         
    string gradoAcademico; 

public:
    profesor(string, string, string, string, string);
    profesor();
    ~profesor();

    string getNombre();
    string getId();
    string getTelefono();
    string getEmail();
    string getGradoAcademico();

    void setNombre(string);
    void setId(string);
    void setTelefono(string);
    void setEmail(string);
    void setGradoAcademico(string);

    string toString();
};

#endif 