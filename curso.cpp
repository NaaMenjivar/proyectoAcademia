#include "curso.h"

//Constructor y Destructor
curso::curso(string n, string i, int h, float p, bool d) :
    nombre(n), id(i), horas(h), precio(p), disponible(d), grupos(new listaGrupo()) {}
curso::~curso() {
    if (grupos != nullptr) {
        delete grupos;
    }
}

//Métodos Get
string curso::getNombre() { return nombre; }
string curso::getId() { return id; }
int curso::getHoras() { return horas; }
float curso::getPrecio() { return precio; }
bool curso::getDiponibilidad() { return disponible; }
listaGrupo* curso::getGrupos() { return grupos; }

//Métodos Set
void curso::setNombre(string n) { nombre = n; }
void curso::setId(string i) { id = i; }
void curso::setHoras(int h) { horas = h; }
void curso::setPrecio(float p) { precio = p; }
void curso::setDisponibilidad(bool d) { disponible = d; }
void curso::setGrupos(listaGrupo* g) { grupos = g; }

//Modificadores de grupos
bool curso::agregarGrupo(grupo* g){
    return grupos->insertarPrimero(g);
}
void curso::eliminarGrupo(int num) {
    grupos->eliminarGrupo(num);
}
bool curso::buscarGrupo(int num) {
    return grupos->buscarPorNumGrupo(num);
}

string curso::toString() {
    stringstream s;
    s << "Nombre:\n" << nombre << endl;
    s << "ID:\n" << id << endl;
    s << "Horas:\n" << horas << endl;
    s << "Precio:\n" << precio << endl;
    s << "Disponibilidad:\n" << disponible << endl;
    s << "Grupos:\n" << grupos->toString() << endl;
    return s.str();
}
