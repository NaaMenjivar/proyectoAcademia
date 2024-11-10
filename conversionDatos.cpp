#include "conversionDatos.h"

//string a int
int conversionDatos::conversionInt(string s) {
    stringstream ss(s);
    int result;
    ss >> result;
    return result;
}

//string a float
float conversionDatos::conversionFloat(string s) {
    stringstream ss(s);
    float result;
    ss >> result;
    return result;
}

//string a bool
bool conversionDatos::conversionBool(string s) {
    return (s == "1" || s == "true");
}

//int a string
string conversionDatos::convInt(int v) {
    stringstream ss;
    ss << v;
    return ss.str();
}

//float a string
string conversionDatos::convFloat(float v) {
    stringstream ss;
    ss << v;
    return ss.str();
}

//bool a string
string conversionDatos::convBool(bool v) {
    return v ? "1" : "0";
}


//Conversión de horario
horario* conversionDatos::conversionHorario(string s_) {
    if (s_.size() < 9) { 
        cout << "Error: longitud de la cadena insuficiente para extraer diasSemana." << endl; 
        return nullptr;
    }

    int datosInt = conversionInt(s_); 

    int horaInicioInt = datosInt / 1000000; 
    int horaFinInt = (datosInt / 10000) % 10000; 

    string horaInicio = convInt(horaInicioInt / 100) + ":" + (horaInicioInt % 100 < 10 ? "0" : "") + convInt(horaInicioInt % 100); 
    string horaFin = convInt(horaFinInt / 100) + ":" + (horaFinInt % 100 < 10 ? "0" : "") + convInt(horaFinInt % 100); 

    string diasSemana = s_.substr(8); 

    return new horario(horaInicio, horaFin, diasSemana); 
}


