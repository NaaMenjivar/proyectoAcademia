#include "interfaz.h"

//Constructor
interfaz::interfaz() {
    acad = new academia;
}

//Destructor
interfaz::~interfaz() {
    acad->guardarDatos();
    delete acad;
}

//Menú Principal
void interfaz::menuPrincipal() {
    int opcion;
    system("cls");
    do {
        system("cls");
        cout << "\n--- Menu Principal ---\n";
        cout << "1. Submenu Administracion\n";
        cout << "2. Submenu Matricula\n";
        cout << "3. Submenu Busquedas e Informes\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion; 
        cin.ignore(); 

        switch (opcion) { 
        case 1:
            system("cls");
            this->submenuAdministracion();
            break;
        case 2:
            system("cls");
            this->submenuMatricula();
            break;
        case 3:
            system("cls");
            this->submenuInformes(); 
            break;
        case 4:
            system("cls");
            cout << "Saliendo del programa.\n";
            break;
        default:
            cout << "Opcion no valida. Intente nuevamente.\n";
            system("pause");
            break;
        }
    } while (opcion != 4);
}

//Submenú administración
void interfaz::submenuAdministracion() {
    int opcion;

    do {
        system("cls");
        cout << "\n--- Submenu Administracion General ---\n";
        cout << "(1) Ingresar Profesor\n";
        cout << "(2) Ingresar Estudiante\n";
        cout << "(3) Ingresar Bloque o Periodo\n";
        cout << "(4) Ingresar Curso\n";
        cout << "(5) Ingresar Grupo\n";
        cout << "(6) Asignar Profesor a Grupo\n";
        cout << "(0) Regresar al Menu Principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;  

        switch (opcion) { 
        case 1:
            system("cls");
            ingresarProfesor();
            break;
        case 2:
            system("cls");
            ingresarEstudiante();
            break;
        case 3:
            system("cls");
            ingresarPeriodo();
            break;
        case 4:
            system("cls");
            ingresarCurso();
            break;
        case 5:
            system("cls");
            ingresarGrupo();
            break;
        case 6:
            system("cls");
            asignarProfesorAGrupo();
            break;
        case 0:
            system("cls");
            cout << "Regresando al menu principal.\n";
            break;
        default:
            cout << "Opcion invalida. Por favor intente nuevamente.\n";
            system("pause");
        }
    } while (opcion != 0);
}

//Submenú matrícula
void interfaz::submenuMatricula() {
    int opcion; 

    do {
        system("cls");
        cout << "\n--- Submenu Matricula ---\n";
        cout << "(1) Matricular Estudiante\n";
        cout << "(2) Desmatricular Estudiante\n";
        cout << "(0) Regresar al menu Principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;  

        switch (opcion) {
        case 1:
            system("cls");
            matricularEstudiante();
            break;
        case 2:
            system("cls");
            desmatricularEstudiante();
            break;
        case 0:
            system("cls");
            cout << "Regresando al menu principal.\n";
            break;
        default:
            cout << "Opcion invalida. Por favor intente nuevamente.\n";
            system("pause");
        }
    } while (opcion != 0); 

}

//Submenú informes
void interfaz::submenuInformes() {
    int opcion;

    do {
        system("cls");
        cout << "\n--- Submenu Busquedas e Informes ---\n";
        cout << "(1) Informe Profesores Registrados\n";
        cout << "(2) Informe Estudiantes Registrados\n";
        cout << "(3) Informe Cursos Matriculados por un Estudiante\n";
        cout << "(4) Informe Profesor Especifico\n";
        cout << "(5) Informe Periodos Habilitados para el Annio\n";
        cout << "(6) Informe Grupo Especifico\n";
        cout << "(0) Regresar al Menu Principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            system("cls");
            mostrarInformeProfesores();
            break;
        case 2:
            system("cls");
            mostrarInformeEstudiantes();
            break;
        case 3:
            system("cls");
            mostrarInformeCursosEstudiante();
            break;
        case 4:
            system("cls");
            mostrarInformeProfesorEspecifico();
            break;
        case 5:
            system("cls");
            mostrarInformePeriodos();
            break;
        case 6:
            system("cls");
            mostrarInformeGrupoEspecifico();
            break;
        case 0:
            system("cls");
            cout << "Regresando al menu principal.\n";
            break;
        default:
            cout << "Opcion invalida. Por favor intente nuevamente.\n";
            system("pause");
        }
    } while (opcion != 0);
}

//Métodos de ingreso
void interfaz::ingresarProfesor() {
    system("cls");
    string nombre, id, tel, email, grado;
    profesor* p = nullptr;

    cout << "Ingrese ID: "; cin >> id;

    if (acad->buscarProfesor(id)) {
        cout << "Ya existe.\t" << endl;
        system("pause");
        return;
    }

    cout << "Ingrese nombre:\t"; cin >> nombre; 
    cout << "Ingrese telefono:\t"; cin >> tel; 
    cout << "Ingrese email:\t"; cin >> email; 
    cout << "Ingrese grado:\t"; cin >> grado;  

    if (!nombre.empty() || !id.empty() || !tel.empty() || !email.empty() || !grado.empty()) {
        p = new profesor(nombre, id, tel, email, grado);
        if (acad->agregarProfesor(p)) {
            cout << "Profesor ingresado." << endl;
        }
        else {
            cout << "Error al ingresar." << endl;
            ingresarProfesor();
        }
    }
    else {
        cout << "No se pueden ingresar espacios vacíos, intente nuevamente." << endl;
        ingresarProfesor();
    }
    system("pause");
}

void interfaz::ingresarEstudiante() {
    system("cls");
    string nombre, id, tel, email, espe;
    estudiante* e = nullptr;

    cout << "Ingrese ID: "; cin >> id;

    if (acad->buscarEstudiante(id)) {
        cout << "Ya existe.\t" << endl;
        system("pause");
        return;
    }

    cout << "Ingrese nombre:\t"; cin >> nombre;
    cout << "Ingrese telefono:\t"; cin >> tel;
    cout << "Ingrese email:\t"; cin >> email;
    cout << "Ingrese especialidad:\t"; cin >> espe;

    if (!nombre.empty() || !id.empty() || !tel.empty() || !email.empty() || !espe.empty()) { 
        e = new estudiante(nombre, id, tel, email, espe);  
        if (acad->agregarEstudiante(e)) {
            cout << "Estudiante ingresado." << endl;
        }
        else {
            cout << "Error al ingresar." << endl;
            ingresarEstudiante(); 
        }
    }
    else {
        cout << "No se pueden ingresar espacios vacíos, intente nuevamente." << endl;
        ingresarEstudiante();
    }
    system("pause");
}

void interfaz::ingresarPeriodo() {
    system("cls");
    int numTrimestre;

    cout << "Ingrese el numero de periodo (1-4):\t";
    cin >> numTrimestre;
    cout << endl;

    if (numTrimestre < 1 || numTrimestre > 4) {
        cout << "El numero de periodo debe estar entre 1 y 4.\n";
        system("pause");
        return;
    }

    if (acad->buscarPeriodo(numTrimestre)) {
        cout << "Ya existe un periodo con este numero.\n";
        system("pause");
        return;
    }

    periodo* p = new periodo(numTrimestre);
    if (acad->agregarPeriodo(p)) {
        cout << "Periodo ingresado." << endl;
    }
    else {
        cout << "Error al ingresar." << endl;
    }
    system("pause");
}

void interfaz::ingresarCurso() {
    system("cls");
    string nombre, id;
    int horas, numPeriodo;
    float precio;
    bool disponible;

    cout << "Ingrese el ID del curso:\t";
    cin.ignore();
    getline(cin, id);
    cout << endl;

    if (acad->buscarCurso(id)) {
        cout << "Error: Ya existe un curso con este ID.\n";
        system("pause");
        return;
    }

    cout << "Ingrese el nombre del curso:\t";
    cin.ignore();
    getline(cin, nombre);
    cout << endl;
    cout << "Ingrese la cantidad de horas del curso:\t";
    cin >> horas;
    cout << endl;
    cout << "Ingrese el precio del curso:\t";
    cin >> precio;
    cout << endl;
    cout << "¿El curso esta disponible? (1/0):\t";
    cin >> disponible;
    cout << endl;

    if (!nombre.empty() || horas != 0 || precio != 0) {
        curso* c = new curso(nombre, id, horas, precio, disponible);
        cout << acad->listarPeriodos() << endl; 
        cout << "Ingrese el numero de periodo al que desea ingresar el curso (1-4):\t";
        cin >> numPeriodo; 

        if (acad->agregarCurso(c)) {
            if (acad->buscarPeriodo(numPeriodo)) { 
                if (acad->getPeriodos()->getPeriodo(numPeriodo)->agregarCurso(c)) { 
                    system("cls");
                    cout << "Curso agregado al periodo " << numPeriodo << " con exito.\n";
                }
            }
            else {
                cout << "El periodo ingresado no existe, intente nuevamente." << endl;
                return;
            }
            cout << "Curso ingresado." << endl;
        }
        else {
            cout << "Error al ingresar." << endl;
        }
    }
    else {
        cout << "No se pueden ingresar espacios vacios, intente nuevamente." << endl;
        ingresarCurso();
    }
    system("pause");
}

void interfaz::ingresarGrupo() {
    system("cls");
    string idCurso;
    int numGrupo, capacidad, numPeriodo;
    string horarioInicio, horarioFin, diasSemana;
    profesor* p = new profesor();

    cout << acad->listarCursos();
    cout << "Ingrese el ID del curso para el nuevo grupo:\t";
    cin.ignore();
    getline(cin, idCurso);

    if (!acad->buscarCurso(idCurso)) {
        cout << "Error: El curso no existe.\n";
        system("pause");
        return;
    }
    curso* c = acad->getCursos()->getCurso(idCurso);

    system("cls");
    cout << "Ingrese el numero del grupo:\t";
    cin >> numGrupo;
    cout << "Ingrese la capacidad del grupo:\t";
    cin >> capacidad;

    if (numGrupo <= 0 || capacidad <= 0) {
        cout << "Error: El numero de grupo y la capacidad deben ser mayores que cero.\n";
        system("pause");
        return;
    }

    system("cls");
    cout << "------- Informacion del Horario -------\n";
    cout << "Ingrese el horario de inicio (HHMM):\t";
    cin >> horarioInicio;
    cout << "Ingrese el horario de fin (HHMM):\t";
    cin >> horarioFin;
    cout << "Ingrese los dias de la semana (LunMie):\t";
    cin.ignore();
    getline(cin, diasSemana);

    horario* h = new horario(horarioInicio, horarioFin, diasSemana);
    grupo* g = new grupo(numGrupo, capacidad, 0, h, p); 

    system("cls");
    cout << acad->listarPeriodos();
    cout << "Ingrese el numero de periodo (1-4): ";
    cin >> numPeriodo;

    if (!acad->buscarPeriodo(numPeriodo)) {
        cout << "Error: Periodo no encontrado.\n";
        delete g;
        system("pause");
        return;
    }

    if (c->agregarGrupo(g) && acad->agregarGrupo(g, numPeriodo)) { 
        cout << "Grupo agregado correctamente al curso y al periodo.\n";
    }
    else {
        cout << "Error al agregar el grupo al curso o al periodo.\n";
        delete g;
    }

    system("pause");
}


void interfaz::asignarProfesorAGrupo() {
    system("cls");
    string idProfesor, idCurso;
    int numGrupo;

    cout << acad->listarCursos();
    cout << "Ingrese el ID para el curso del grupo correspondiente:\t"; cin >> idCurso; 
    cout << endl; 

    if (!acad->buscarCurso(idCurso)) {
        cout << "Error: El curso no esta registrado.\n";
        system("pause");
        return;
    }
    if (acad->getGrupos()->vacia()) {
        cout << "No hay grupos disponibles en este curso. No se puede asignar un profesor.\n";
        system("pause");
        return;
    }

    cout << acad->getCursos()->getCurso(idCurso)->getGrupos()->toString();
    cout << "Ingrese el numero de grupo deseado:\t";
    cin >> numGrupo; 
    cout << endl;

    if (numGrupo == 0) {
        cout << "El numero de grupo no es valido, intente de nuevo." << endl;
        system("pause");
        submenuAdministracion();
    }
    if (!acad->buscarGrupo(numGrupo)) {
        cout << "El grupo no existe, intente de nuevo." << endl;
        system("pause");
        return;
    }

    grupo* g = acad->getCursos()->getCurso(idCurso)->getGrupos()->getGrupo(numGrupo);

    cout << acad->listarProfesores();
    cout << "Ingrese el ID del profesor que desea asignar:\t"; cin >> idProfesor; 
    cout << endl; 
    if (!acad->buscarProfesor(idProfesor)) {
        cout << "Error: El profesor ingresado no esta registrado en el sistema.\n";
        system("pause");
        return;
    }
    profesor* p = acad->getProfesores()->getProfesor(idProfesor);

    g->setProfesor(p);
    cout << "Profesor asignado correctamente al grupo con #" << numGrupo << ".\n";
    system("pause");
}

//Métodos de matrícula
void interfaz::matricularEstudiante() {
    system("cls");
    string idEstudiante, idCurso;
    int numGrupo, numPeriodo;

    if (acad->listarEstudiantes().empty()) {
        cout << "Error: No hay estudiantes registrados en el sistema.\n";
        system("pause");
        return;
    }
    if (acad->listarCursos().empty()) {
        cout << "Error: No hay cursos registrados en el sistema.\n";
        system("pause");
        return;
    }
    if (acad->listarPeriodos().empty()) {
        cout << "Error: No hay periodos registrados en el sistema.\n";
        system("pause");
        return;
    }

    cout << acad->listarEstudiantes();
    cout << "Ingrese el ID del estudiante que desea matricular: "; cin >> idEstudiante; 
    if (!acad->buscarEstudiante(idEstudiante)) {
        cout << "Error: El estudiante ingresado no esta registrado en el sistema.\n";
        system("pause");
        return;
    }

    cout << acad->listarCursos();
    cout << "Ingrese el ID del curso en el que desea matricular al estudiante: "; cin >> idCurso; 
    if (!acad->buscarCurso(idCurso)) {
        cout << "Error: El curso ingresado no esta registrado en el sistema.\n";
        system("pause");
        return;
    }

    if (acad->getCursos()->getCurso(idCurso)->getGrupos()->vacia()) {
        cout << "No hay grupos disponibles en este curso. No se puede matricular un estudiante.\n";
        system("pause");
        return;
    }

    cout << acad->listarPeriodos();
    cout << "Ingrese el numero de periodo: ";
    cin >> numPeriodo;
    if (!acad->buscarPeriodo(numPeriodo)) {
        cout << "Error: El periodo ingresado no está registrado en el sistema.\n";
        system("pause");
        return;
    }

    cout << acad->getCursos()->getCurso(idCurso)->getGrupos()->toString();
    cout << "Ingrese el numero de grupo en el que desea matricular al estudiante: ";
    cin >> numGrupo;
    if (!acad->buscarGrupo(numGrupo)) {
        cout << "Error: El grupo ingresado no esta registrado en el curso.\n";
        system("pause");
        return;
    }

    grupo* g = acad->getGrupos()->getGrupo(numGrupo);
    if (g->getCantidadAlumnos() >= g->getCapacidad()) {
        cout << "Error: El grupo seleccionado no tiene cupos disponibles.\n";
        system("pause");
        return;
    }
    if (acad->matricularEstudianteEnCurso(idEstudiante, idCurso, numGrupo)) {
        cout << "Matricula realizada con exito.\n";
        cout << "Factura generada:\n" << acad->generarFactura(idEstudiante, numPeriodo);
    }
    else {
        cout << "Error al matricular al estudiante.\n";
    }
    system("pause");
}

void interfaz::desmatricularEstudiante() {
    system("cls");
    string idEstudiante, idCurso;
    int numGrupo;

    if (acad->listarEstudiantes().empty()) {
        cout << "Error: No hay estudiantes registrados en el sistema.\n";
        system("pause");
        return;
    }

    cout << acad->listarEstudiantes();
    cout << "Ingrese el ID del estudiante que desea desmatricular: "; cin >> idEstudiante; 
    if (!acad->buscarEstudiante(idEstudiante)) { 
        cout << "Error: El estudiante ingresado no esta registrado en el sistema.\n";
        system("pause");
        return;
    }

    cout << acad->listarCursos();
    cout << "Ingrese el ID del curso del que desea desmatricular al estudiante: "; cin >> idCurso; 
    if (!acad->buscarCurso(idCurso)) { 
        cout << "Error: El curso ingresado no esta registrado en el sistema.\n";
        system("pause");
        return;
    }

    if (acad->getCursos()->getCurso(idCurso)->getGrupos()->vacia()) {
        cout << "No hay grupos disponibles en este curso. No se puede desmatricular un estudiante.\n";
        system("pause");
        return;
    }

    cout << acad->getCursos()->getCurso(idCurso)->getGrupos()->toString();
    cout << "Ingrese el numero de grupo del que desea desmatricular al estudiante: ";
    cin >> numGrupo;
    if (!acad->buscarGrupo(numGrupo)) {
        cout << "Error: El grupo ingresado no esta registrado en el curso.\n";
        system("pause");
        return;
    }

    if (acad->desmatricularEstudiante(idEstudiante, idCurso, numGrupo)) {
        cout << "El estudiante ha sido desmatriculado del grupo correctamente.\n";
    }
    else {
        cout << "Error al desmatricular al estudiante.\n";
    }
    system("pause");
}

//Métodos para mostrar
void interfaz::mostrarInformeProfesores() {
    system("cls");
    cout << "----- Informe de Profesores Registrados -----\n";
    string informe = acad->informeProfesores(); 
    if (informe.empty()) { 
        cout << "No hay profesores registrados en el sistema.\n";
    }
    else {
        cout << informe << endl; 
    }
    system("pause");
}

void interfaz::mostrarInformeEstudiantes() {
    system("cls");
    cout << "----- Informe de Estudiantes Registrados -----\n";
    string informe = acad->informeEstudiantes(); 
    if (informe.empty()) { 
        cout << "No hay estudiantes registrados en el sistema.\n";
    }
    else {
        cout << informe << endl; 
    }
    system("pause");
}

void interfaz::mostrarInformeCursosEstudiante() {
    system("cls");
    string idEstudiante; 
    cout << "Lista Estudiantes:\n" << acad->listarEstudiantes() << endl;
    cout << "Ingrese el ID del estudiante: "; cin >> idEstudiante; 
    system("cls");

    cout << "----- Informe de Cursos Matriculados por el Estudiante -----\n";
    string informe = acad->informeCursosMatriculadosEstudiante(idEstudiante); 
    if (informe == "Estudiante no encontrado.") { 
        cout << "Error: El estudiante con ID " << idEstudiante << " no esta registrado en el sistema.\n"; 
    }
    else {
        cout << informe << endl; 
    }
    system("pause");
}

void interfaz::mostrarInformeProfesorEspecifico() {
    system("cls");
    string idProfesor; 
    cout << "Lista Profesores:\n" << acad->listarProfesores() << endl;
    cout << "Ingrese el ID del profesor: "; cin >> idProfesor;
    system("cls");

    cout << "----- Informe del Profesor Especifico -----\n";
    string informe = acad->informeProfesorEspecifico(idProfesor); 
    if (informe == "Profesor no encontrado.") { 
        cout << "Error: El profesor con ID " << idProfesor << " no esta registrado en el sistema.\n"; 
    }
    else {
        cout << informe << endl; 
    }
    system("pause");
}

void interfaz::mostrarInformePeriodos() {
    system("cls");
    cout << "----- Informe de Periodos Habilitados para el Annio -----\n";
    string informe = acad->informePeriodos(); 
    if (informe.empty()) { 
        cout << "No hay periodos registrados en el sistema.\n";
    }
    else {
        cout << informe << endl; 
    }
    system("pause");
}

void interfaz::mostrarInformeGrupoEspecifico() {
    system("cls");
    string idCurso;  
    int numGrupo;

    if (acad->getCursos()->vacia()) {
        cout << "No se pueden mostrar grupos sin cursos disponibles.\n";
        system("pause");
        return;
    }

    cout << acad->listarCursos();
    cout << "Ingrese el ID del curso: "; 
    cin >> idCurso; 

    if (acad->getCursos()->getCurso(idCurso)->getGrupos()->vacia()) {
        cout << "No hay grupos disponibles en este curso.\n";
        system("pause");
        return;
    }

    cout << acad->getCursos()->getCurso(idCurso)->getGrupos()->toString();
    cout << "Ingrese el numero de grupo: ";
    cin >> numGrupo; 
    system("cls");

    cout << "----- Informe del Grupo Especifico -----\n";
    string informe = acad->informeGrupoEspecifico(idCurso, numGrupo); 
    if (informe == "Curso no encontrado." || informe == "Grupo no encontrado.") { 
        cout << "Error: No se encontro el curso o grupo especificado.\n";
    }
    else {
        cout << informe << endl; 
    }
    system("pause");
}


