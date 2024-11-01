#include "interfaz.h"

//Constructor
interfaz::interfaz() {
	acad = new academia();
}

//Menú Principal
void interfaz::menuPrincipal() {
    int opcion;

    do {
        cout << "\n--- Menú Principal ---\n";
        cout << "1. Submenú Administración\n";
        cout << "2. Submenú Matrícula\n";
        cout << "3. Submenú Búsquedas e Informes\n";
        cout << "4. Guardar los Datos en Archivos\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion; 

        switch (opcion) { 
        case 1:
            submenuAdministracion();
            break;
        case 2:
            submenuMatricula();
            break;
        case 3:
            submenuInformes(); 
            break;
        case 4:
            guardarDatos();
            break;
        case 5:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opción no válida. Intente nuevamente.\n";
            break;
        }
    } while (opcion != 5);
}

//Submenú administración
void interfaz::submenuAdministracion() {
    int opcion;

    do {
        cout << "\n--- Submenú Administración General ---\n";
        cout << "(1) Ingresar Profesor\n";
        cout << "(2) Ingresar Estudiante\n";
        cout << "(3) Ingresar Bloque o Periodo\n";
        cout << "(4) Ingresar Curso\n";
        cout << "(5) Ingresar Grupo\n";
        cout << "(6) Asignar Profesor a Grupo\n";
        cout << "(0) Regresar al Menú Principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;  

        switch (opcion) { 
        case 1:
            ingresarProfesor();
            break;
        case 2:
            ingresarEstudiante();
            break;
        case 3:
            ingresarPeriodo();
            break;
        case 4:
            agregarCurso(); 
            break;
        case 5:
            ingresarGrupo();
            break;
        case 6:
            asignarProfesorAGrupo();
            break;
        case 0:
            cout << "Regresando al menú principal.\n";
            menuPrincipal();
            break;
        default:
            cout << "Opción inválida. Por favor intente nuevamente.\n";
        }
    } while (opcion != 0);
}

//Submenú matrícula
void interfaz::submenuMatricula() {
    int opcion; 

    do {
        cout << "\n--- Submenú Matrícula ---\n";
        cout << "(1) Matricular Estudiante\n";
        cout << "(2) Desmatricular Estudiante\n";
        cout << "(0) Regresar al menú Principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;  

        switch (opcion) {
        case 1:
            matricularEstudiante(); 
            break;
        case 2:
            desmatricularEstudiante(); 
            break;
        case 0:
            cout << "Regresando al menú principal.\n";
            menuPrincipal();
            break;
        default:
            cout << "Opción inválida. Por favor intente nuevamente.\n";
        }
    } while (opcion != 0); 

}

//Submenú informes
void interfaz::submenuInformes() {
    int opcion;

    do {
        cout << "\n--- Submenú Búsquedas e Informes ---\n";
        cout << "(1) Informe Profesores Registrados\n";
        cout << "(2) Informe Estudiantes Registrados\n";
        cout << "(3) Informe Cursos Matriculados por un Estudiante\n";
        cout << "(4) Informe Profesor Especifico\n";
        cout << "(5) Informe Periodos Habilitados para el Año\n";
        cout << "(6) Informe Grupo Especifico\n";
        cout << "(0) Regresar al Menú Principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            mostrarInformeProfesores();
            break;
        case 2:
            mostrarInformeEstudiantes();
            break;
        case 3:
            mostrarInformeCursosEstudiante();
            break;
        case 4:
            mostrarInformeProfesorEspecifico();
            break;
        case 5:
            mostrarInformePeriodos();
            break;
        case 6:
            mostrarInformeGrupoEspecifico();
            break;
        case 0:
            cout << "Regresando al menú principal.\n";
            menuPrincipal();
            break;
        default:
            cout << "Opción inválida. Por favor intente nuevamente.\n";
        }
    } while (opcion != 0);
}

//Guardar datos
void interfaz::guardarDatos() {

}

