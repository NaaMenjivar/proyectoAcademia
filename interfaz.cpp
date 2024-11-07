#include "interfaz.h"

//Constructor
interfaz::interfaz() {
	acad = new academia();
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
            menuPrincipal();
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
            menuPrincipal();
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
        cout << "(5) Informe Periodos Habilitados para el Año\n";
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
            menuPrincipal();
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
    string nombre, id, telefono, email, gradoAcademico;

    cout << "Ingrese el ID del profesor:\t";
    getline(cin, id);
    cout << endl;

    if (acad->buscarProfesor(id)) {
        cout << "Error: ya existe un profesor con ese ID.\n";
        system("pause");
        return;
    }

    cout << "Ingrese el nombre del profesor:\t";
    getline(cin, nombre);
    cout << endl;
    cout << "Ingrese el telefono del profesor:\t";
    getline(cin, telefono);
    cout << endl;
    cout << "Ingrese el email del profesor:\t";
    getline(cin, email);
    cout << endl;
    cout << "Ingrese el grado academico del profesor:\t";
    getline(cin, gradoAcademico);
    cout << endl;

    if (!nombre.empty() || !telefono.empty() || !email.empty() || !gradoAcademico.empty()) {
        profesor* p = new profesor(nombre, id, telefono, email, gradoAcademico);
        if (acad->agregarProfesor(p)) {
            cout << "Profesor ingresado." << endl;
        }
        else {
            cout << "Error al ingresar." << endl;
        }
    }
    else {
       cout << "No se pueden ingresar espacios vacios, intente nuevamente." << endl;
       submenuAdministracion();
    }
    system("pause");
}

void interfaz::ingresarEstudiante() {
    system("cls");
    string nombre, id, especialidad, telefono, email;

    cout << "Ingrese el ID del estudiante:\t";
    getline(cin, id);
    cout << endl;

    if (acad->buscarEstudiante(id)) {
        cout << "Error: ya existe un estudiante con este ID.\n";
        system("pause");
        return;
    }

    cout << "Ingrese el nombre del estudiante:\t";
    getline(cin, nombre);
    cout << endl;
    cout << "Ingrese la especialidad del estudiante:\t";
    getline(cin, especialidad);
    cout << endl;
    cout << "Ingrese el telefono del estudiante:\t";
    getline(cin, telefono);
    cout << endl;
    cout << "Ingrese el email del estudiante:\t";
    getline(cin, email);
    cout << endl;

    if (!nombre.empty() || !especialidad.empty() || !telefono.empty() || !email.empty()) {
        estudiante* e = new estudiante(nombre, id, especialidad, telefono, email);
        if (acad->agregarEstudiante(e)) {
            cout << "Estudiante ingresado." << endl;
        }
        else {
            cout << "Error al ingresar." << endl;
        }
    }
    else {
        cout << "No se pueden ingresar espacios vacíos, intente nuevamente." << endl;
        submenuAdministracion();
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
    int horas;
    float precio;
    bool disponible;

    cout << "Ingrese el ID del curso:\t";
    getline(cin, id);
    cout << endl;

    if (acad->buscarCurso(id)) {
        cout << "Error: Ya existe un curso con este ID.\n";
        system("pause");
        return;
    }

    cout << "Ingrese el nombre del curso:\t";
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
        if (acad->agregarCurso(c)) {
            cout << "Curso ingresado." << endl;
        }
        else {
            cout << "Error al ingresar." << endl;
        }
    }
    else {
        cout << "No se pueden ingresar espacios vacios, intente nuevamente." << endl;
        submenuAdministracion();
    }
    system("pause");
}

void interfaz::ingresarGrupo() {
    system("cls");
    string idCurso;
    int numGrupo, capacidad;
    string horarioInicio, horarioFin, diasSemana;
    profesor* prof = nullptr;

    cout << "Ingrese el ID del curso para el nuevo grupo:\t";
    getline(cin, idCurso);
    cout << endl;

    if (!acad->buscarCurso(idCurso)) {
        cout << "Error: El curso no existe.\n";
        system("pause");
        return;
    }
    curso* c = acad->getCursos()->getCurso(idCurso);

    cout << "Ingrese el numero del grupo:\t";
    cin >> numGrupo;
    cout << endl;
    cout << "Ingrese la capacidad del grupo:\t";
    cin >> capacidad;
    cout << endl;

    cout << "Informacion del horario:\n";
    cout << "Ingrese el horario de inicio:\t";
    getline(cin, horarioInicio);
    cout << endl;
    cout << "Ingrese el horario de fin:\t";
    getline(cin, horarioFin);
    cout << endl;
    cout << "Ingrese los dias de la semana del grupo:\t";
    getline(cin, diasSemana);
    cout << endl; 

    if (!horarioInicio.empty() || !horarioFin.empty() || !diasSemana.empty()) {
        cout << "Datos del horario ingresados exitosamente." << endl;
    }
    horario* h = new horario(horarioInicio, horarioFin, diasSemana); 

    if (numGrupo != 0 || capacidad != 0) {
        grupo* g = new grupo(numGrupo, capacidad, 0, h, prof);
        if (c->agregarGrupo(g)) {
            cout << "Grupo ingresado." << endl;
        }
        else {
            cout << "Error al ingresar." << endl; 
        }
    }
    else {
        cout << "No se pueden ingresar espacios vacios, intente de nuevo." << endl;
        submenuAdministracion();
    }
    system("pause");
}

void interfaz::asignarProfesorAGrupo() {
    system("cls");
    string idProfesor, idCurso;
    int numGrupo;

    cout << "Ingrese el ID para el curso del grupo correspondiente:\t";
    getline(cin, idCurso);
    cout << endl; 

    if (!acad->buscarCurso(idCurso)) {
        cout << "Error: El curso no esta registrado.\n";
        system("pause");
        return;
    }
    
    cout << "Ingrese el numero de grupo deseado:\t";
    cin >> numGrupo; 
    cout << endl;

    if (numGrupo == 0) {
        cout << "El numero de grupo no es valido, intente de nuevo." << endl;
        system("pause");
        submenuAdministracion();
    }
    grupo* g = acad->getCursos()->getCurso(idCurso)->getGrupos()->getGrupo(numGrupo);

    cout << "Ingrese el ID del profesor que desea asignar:\t";
    getline(cin, idProfesor);
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

    cout << "Ingrese el ID del estudiante que desea matricular: ";
    getline(cin, idEstudiante);
    if (!acad->buscarEstudiante(idEstudiante)) {
        cout << "Error: El estudiante ingresado no está registrado en el sistema.\n";
        system("pause");
        return;
    }

    cout << "Ingrese el ID del curso en el que desea matricular al estudiante: ";
    getline(cin, idCurso); 
    if (!acad->buscarCurso(idCurso)) {
        cout << "Error: El curso ingresado no está registrado en el sistema.\n";
        system("pause");
        return;
    }

    cout << "Ingrese el número de periodo: ";
    cin >> numPeriodo;
    if (!acad->buscarPeriodo(numPeriodo)) {
        cout << "Error: El periodo ingresado no está registrado en el sistema.\n";
        system("pause");
        return;
    }

    cout << "Ingrese el número de grupo en el que desea matricular al estudiante: ";
    cin >> numGrupo;
    if (!acad->buscarGrupo(numGrupo)) {
        cout << "Error: El grupo ingresado no está registrado en el curso.\n";
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
        cout << "Matrícula realizada con éxito.\n";
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

    cout << "Ingrese el ID del estudiante que desea desmatricular: ";
    getline(cin, idEstudiante);
    if (!acad->buscarEstudiante(idEstudiante)) { 
        cout << "Error: El estudiante ingresado no está registrado en el sistema.\n";
        system("pause");
        return;
    }

    cout << "Ingrese el ID del curso del que desea desmatricular al estudiante: ";
    getline(cin, idCurso);
    if (!acad->buscarCurso(idCurso)) { 
        cout << "Error: El curso ingresado no está registrado en el sistema.\n";
        system("pause");
        return;
    }

    cout << "Ingrese el número de grupo del que desea desmatricular al estudiante: ";
    cin >> numGrupo;
    if (!acad->buscarGrupo(numGrupo)) {
        cout << "Error: El grupo ingresado no está registrado en el curso.\n";
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
        cout << "Nombre\tID\n";
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
        cout << "Nombre\tID\n";
        cout << informe << endl; 
    }
    system("pause");
}

void interfaz::mostrarInformeCursosEstudiante() {
    system("cls");
    string idEstudiante; 
    cout << "Ingrese el ID del estudiante: ";
    getline(cin, idEstudiante);

    cout << "----- Informe de Cursos Matriculados por el Estudiante -----\n";
    string informe = acad->informeCursosMatriculadosEstudiante(idEstudiante); 
    if (informe == "Estudiante no encontrado.") { 
        cout << "Error: El estudiante con ID " << idEstudiante << " no está registrado en el sistema.\n"; 
    }
    else {
        cout << informe << endl; 
    }
    system("pause");
}

void interfaz::mostrarInformeProfesorEspecifico() {
    system("cls");
    string idProfesor; 
    cout << "Ingrese el ID del profesor: ";
    getline(cin, idProfesor);

    cout << "----- Informe del Profesor Específico -----\n";
    string informe = acad->informeProfesorEspecifico(idProfesor); 
    if (informe == "Profesor no encontrado.") { 
        cout << "Error: El profesor con ID " << idProfesor << " no está registrado en el sistema.\n"; 
    }
    else {
        cout << informe << endl; 
    }
    system("pause");
}

void interfaz::mostrarInformePeriodos() {
    system("cls");
    cout << "----- Informe de Periodos Habilitados para el Año -----\n";
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

    cout << "Ingrese el ID del curso: ";
    getline(cin, idCurso);

    cout << "Ingrese el número de grupo: ";
    cin >> numGrupo; 
   
    cout << "----- Informe del Grupo Específico -----\n";
    string informe = acad->informeGrupoEspecifico(idCurso, numGrupo); 
    if (informe == "Curso no encontrado." || informe == "Grupo no encontrado.") { 
        cout << "Error: No se encontró el curso o grupo especificado.\n";
    }
    else {
        cout << informe << endl; 
    }
    system("pause");
}


