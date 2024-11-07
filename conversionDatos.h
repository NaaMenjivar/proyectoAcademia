#pragma once
#include "horario.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class conversionDatos {
public:
    //String a bases
    int conversionInt(string s);
    float conversionFloat(string s);
    bool conversionBool(string s);

    //Bases a string
    string convInt(int v);
    string convFloat(float v);
    string convBool(bool v);
    
    //Conversión horario
    horario* conversionHorario(string s_);
};

