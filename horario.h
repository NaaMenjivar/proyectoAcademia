#ifndef HORARIO_H
#define HORARIO_H
#pragma once
#include <iostream>
#include <sstream> 
#include <string>
using namespace std;

class horario {
private:
    string horaInicio;      
    string horaFin;        
    string diasSemana;

public:
    horario(string h, string f, string d);
    ~horario();

    string getHoraInicio();
    string getHoraFin();
    string getDiasSemana();

    void setHoraInicio(string h);
    void setHoraFin(string h);
    void setDiasSemana(string d);

    string toString();
};

#endif 