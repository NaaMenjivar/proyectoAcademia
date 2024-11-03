#pragma once
#include "listaCurso.h"
#include "listaGrupo.h"
#include "listaEstudiante.h"
#include "listaProfesor.h"
#include "listaPeriodo.h"
#include "factura.h"
#include "descuento.h"

using namespace std;

class academia {
private:
    listaCurso* cursos;
    listaGrupo* grupos;
    listaEstudiante* estudiantes;
    listaProfesor* profesores;
    listaPeriodo* periodos;

public:
    // Constructor y Destructor
    academia();
    ~academia();

    // Métodos de administración de listas
    bool agregarCurso(curso* c);
    bool eliminarCurso(string id);
    string listarCursos();

    bool agregarGrupo(grupo* g, int numPeriodo);
    bool eliminarGrupo(int numGrupo);
    string listarGrupos();

    bool agregarEstudiante(estudiante* e);
    bool eliminarEstudiante(string id);
    string listarEstudiantes();

    bool agregarProfesor(profesor* p);
    bool eliminarProfesor(string id); 
    string listarProfesores(); 

    bool agregarPeriodo(periodo* p);
    bool eliminarPeriodo(int num);
    string listarPeriodos();

    // Métodos de matrícula
    bool matricularEstudianteEnCurso(string idEstudiante, string idCurso, int numGrupo);
    bool desmatricularEstudiante(string idEstudiante, string idCurso, int numGrupo);
    int calcularCursosAnuales(string idEstudiante);
    float calcularDescuentoAnual(string idEstudiante);
    string generarFactura(string idEstudiante, int numPeriodo);

    // Métodos de informes
    string informeProfesores();
    string informeEstudiantes();
    string informeCursosMatriculadosEstudiante(string idEstudiante);
    string informeProfesorEspecifico(string idProfesor);
    string informePeriodos();
    string informeGrupoEspecifico(string idCurso, int numGrupo);

    // Persistencia de datos
    void guardarDatos();
    void cargarDatos();
};
