#include "horario.h"

//Constructor y Destructor
horario::horario(string h, string f, string d) : horaInicio(h), horaFin(f), diasSemana(d) {}
horario::~horario() {}

//Métodos Get
string horario::getHoraInicio() { return horaInicio; }
string horario::getHoraFin() { return horaFin; }
string horario::getDiasSemana() { return diasSemana; }

//Métodos Set
void horario::setHoraInicio(string h) { horaInicio = h; }
void horario::setHoraFin(string h) { horaFin = h; }
void horario::setDiasSemana(string d) { diasSemana = d; }

//toString
string horario::toString() {
    stringstream s;
    s << "------ Horario ------\n" << endl;;
    s << "Inicio:\t\t" << horaInicio << endl;
    s << "Fin:\t\t" << horaFin << endl;
    s << "Días:\t\t" << diasSemana << endl;
    
    return s.str();
}
