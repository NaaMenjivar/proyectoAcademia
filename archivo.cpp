#include "archivo.h"

void archivo::guardarEstudiantes(listaEstudiante* lis) {
	salida.open("Archivos/estudiantesAcademia.txt");
	if (salida.good()) {
		nodoEstudiante* aux = lis->getPrimero();
		while (aux) {
			salida << aux->getEstudiante()->getId() << "\t"; 
			salida << aux->getEstudiante()->getNombre() << "\t"; 
			salida << aux->getEstudiante()->getEspecialidad() << "\t"; 
			salida << aux->getEstudiante()->getTelefono() << "\t"; 
			salida << aux->getEstudiante()->getEmail() << "\n"; 
			aux = aux->getSiguiente();
		}
	}
	salida.close();
}

void archivo::guardarProfesores(listaProfesor* lis) {
	salida.open("Archivos/profesoresAcademia.txt");
	if (salida.good()) {
		nodoProfesor* aux = lis->getPrimero();
		while (aux) {
			salida << aux->getProfesor()->getId() << "\t"; 
			salida << aux->getProfesor()->getNombre() << "\t"; 
			salida << aux->getProfesor()->getTelefono() << "\t"; 
			salida << aux->getProfesor()->getEmail() << "\t"; 
			salida << aux->getProfesor()->getGradoAcademico() << "\n"; 
			aux = aux->getSiguiente();
		}
	}
	salida.close();
}

void archivo::guardarGrupos(listaGrupo* lis) {
	salida.open("Archivos/gruposAcademia.txt");
	salidaAux.open("Archivos/estudiantesGrupo.txt");

	if (salida.good() && salidaAux.good()) {
		nodoGrupo* aux = lis->getPrimero(); 
		while (aux) {
			grupo* grupoActual = aux->getGrupo();
			salida << grupoActual->getNumeroGrupo() << "\t";
			salida << grupoActual->getProfesor()->getId() << "\t";
			salida << grupoActual->getProfesor()->getNombre() << "\t";
			salida << grupoActual->getCapacidad() << "\t";
			salida << grupoActual->getHorario()->getHoraInicio() << "\t";
			salida << grupoActual->getHorario()->getHoraFin() << "\t";
			salida << grupoActual->getHorario()->getDiasSemana() << "\n";
			salida << grupoActual->getCantidadAlumnos() << "\t";
			guardarEstudiantesGrupo(grupoActual->getEstudiantes(), grupoActual->getNumeroGrupo());

			aux = aux->getSig();
		}
	}

	salida.close();
	salidaAux.close();
}

void archivo::guardarCursos(listaCurso* lis) {
	salida.open("Archivos/cursosAcademia.txt");
	salidaAux.open("Archivos/gruposCurso.txt");

	if (salida.good() && salidaAux.good()) {
		nodoCurso* aux = lis->getPrimero();

		while (aux) {
			curso* cursoActual = aux->getCurso();
			salida << cursoActual->getId() << "\t";
			salida << cursoActual->getNombre() << "\t";
			salida << cursoActual->getHoras() << "\t";
			salida << cursoActual->getPrecio() << "\t";
			salida << (cursoActual->getDiponibilidad() ? "1" : "0") << "\n";
			guardarGruposCurso(cursoActual->getGrupos(), cursoActual->getId());

			aux = aux->getSig();
		}
	}

	salida.close();
	salidaAux.close();
}

void archivo::guardarPeriodos(listaPeriodo* lis) {
	salida.open("Archivos/periodosAcademia.txt");
	salidaAux.open("Archivos/cursosPeriodo.txt");
	salidaAux2.open("Archivos/gruposPeriodo.txt");

	if (salida.good() && salidaAux.good() && salidaAux2.good()) { 
		nodoPeriodo* aux = lis->getPrimero(); 

		while (aux) { 
			periodo* periodoActual = aux->getPeriodo(); 
			salida << periodoActual->getNumTrimestre() << "\t"; 
			salida << periodoActual->getNombre() << "\t"; 
			salida << periodoActual->getMesInicio() << "\t"; 
			salida << periodoActual->getMesFin() << "\n"; 
			guardarCursosPeriodo(periodoActual->getCursos(), periodoActual->getNumTrimestre()); 
			guardarGruposPeriodo(periodoActual->getGrupos(), periodoActual->getNumTrimestre());  

			aux = aux->getSig(); 
		}
	}

	salida.close(); 
	salidaAux.close(); 
	salidaAux2.close(); 
}

void archivo::guardarEstudiantesGrupo(listaEstudiante* lis, int numeroGrupo) {
	if (salida.good()) {
		nodoEstudiante* aux = lis->getPrimero();
		while (aux) {
			salidaAux << numeroGrupo << "\t";
			salidaAux << aux->getEstudiante()->getId() << "\t"; 
			salidaAux << aux->getEstudiante()->getNombre() << "\t";
			salidaAux << aux->getEstudiante()->getTelefono() << "\t";
			salidaAux << aux->getEstudiante()->getEmail() << "\t";
			salidaAux << aux->getEstudiante()->getEspecialidad() << "\n";
			aux = aux->getSiguiente();
		}
	}
}

void archivo::guardarGruposCurso(listaGrupo* lis, string idCurso) {
	if (salida.good()) {
		nodoGrupo* aux = lis->getPrimero();
		while (aux) {
			grupo* grupoActual = aux->getGrupo();
			salidaAux << idCurso << "\t";
			salidaAux << grupoActual->getNumeroGrupo() << "\t";
			salidaAux << grupoActual->getProfesor()->getId() << "\t";
			salidaAux << grupoActual->getProfesor()->getNombre() << "\t";
			salidaAux << grupoActual->getCapacidad() << "\t";
			salidaAux << grupoActual->getHorario()->getHoraInicio() << "\t";
			salidaAux << grupoActual->getHorario()->getHoraFin() << "\t"; 
			salidaAux << grupoActual->getHorario()->getDiasSemana() << "\n";
			salidaAux << grupoActual->getCantidadAlumnos() << "\t";
			guardarEstudiantesGrupo(grupoActual->getEstudiantes(), grupoActual->getNumeroGrupo());

			aux = aux->getSig();
		}
	}
}

void archivo::guardarGruposPeriodo(listaGrupo* lis, int numTrimestre) {
	if (salida.good()) { 
		nodoGrupo* aux = lis->getPrimero();  
		while (aux) {
			grupo* grupoActual = aux->getGrupo();   
			salidaAux2 << numTrimestre << "\t"; 
			salidaAux2 << grupoActual->getNumeroGrupo() << "\t"; 
			salidaAux2 << grupoActual->getProfesor()->getId() << "\t"; 
			salidaAux2 << grupoActual->getProfesor()->getNombre() << "\t"; 
			salidaAux2 << grupoActual->getCapacidad() << "\t"; 
			salidaAux2 << grupoActual->getHorario()->getHoraInicio() << "\t"; 
			salidaAux2 << grupoActual->getHorario()->getHoraFin() << "\t"; 
			salidaAux2 << grupoActual->getHorario()->getDiasSemana() << "\n"; 
			salidaAux2 << grupoActual->getCantidadAlumnos() << "\t"; 
			guardarEstudiantesGrupo(grupoActual->getEstudiantes(), grupoActual->getNumeroGrupo()); 
			aux = aux->getSig(); 
		}
	}
}

void archivo::guardarCursosPeriodo(listaCurso* lis, int numTrimestre) {
	if (salida.good()) {
		nodoCurso* aux = lis->getPrimero();
		while (aux) {
			curso* cursoActual = aux->getCurso();
			salidaAux << cursoActual->getId() << "\t";
			salidaAux << cursoActual->getNombre() << "\t";
			salidaAux << cursoActual->getHoras() << "\t";
			salidaAux << cursoActual->getPrecio() << "\t";
			salidaAux << (cursoActual->getDiponibilidad() ? "1" : "0") << "\n";
			guardarGruposCurso(cursoActual->getGrupos(), cursoActual->getId());
			aux = aux->getSig();
		}
	}
}

listaEstudiante* archivo::recuperarEstudiantes() {
	listaEstudiante* listaAux = new listaEstudiante();
	entrada.open("Archivos/estudiantesAcademia.txt");
	string id, nombre, especialidad, telefono, email;
	estudiante* est = nullptr;
	while (entrada.good()) {
		getline(entrada, id, '\t');
		getline(entrada, nombre, '\t');
		getline(entrada, especialidad, '\t');
		getline(entrada, telefono, '\t');
		getline(entrada, email, '\n');

		if (!id.empty() && !nombre.empty() && !especialidad.empty() && !telefono.empty() && !email.empty()) {
			est = new estudiante(nombre, id, especialidad, telefono, email);
			listaAux->insertarPrimero(est);
		}
		entrada.close();
		return listaAux;
	}
}

listaProfesor* archivo::recuperarProfesores() { 
	listaProfesor* listaAux = new listaProfesor(); 
	entrada.open("Archivos/profesoresAcademia.txt");
	string id, nombre, telefono, email, gradoAcademico; 
	profesor* prof = nullptr; 

	while (entrada.good()) {
		getline(entrada, id, '\t');
		getline(entrada, nombre, '\t');
		getline(entrada, telefono, '\t');
		getline(entrada, email, '\t');
		getline(entrada, gradoAcademico, '\n');

		if (!id.empty() && !nombre.empty() && !telefono.empty() && !email.empty() && !gradoAcademico.empty()) {
			prof = new profesor(nombre, id, telefono, email, gradoAcademico);
			listaAux->insertarPrimero(prof);
		}
		entrada.close();
		return listaAux;
	}
}

listaGrupo* archivo::recuperarGrupos() {
	listaGrupo* listaAux = new listaGrupo();
	string numeroGrupo, idInstructor, nombreInstructor, cupoMaximo, horarioData, cantidadCuposUsados;
	listaEstudiante* estudiantes;
	grupo* grupoAux = nullptr;

	entrada.open("Archivos/gruposAcademia.txt");

	while (entrada.good()) {
		getline(entrada, numeroGrupo, '\t');
		getline(entrada, idInstructor, '\t');
		getline(entrada, nombreInstructor, '\t');
		getline(entrada, cupoMaximo, '\t');
		getline(entrada, horarioData, '\t');
		getline(entrada, cantidadCuposUsados, '\n');

		estudiantes = recuperarEstudiantesGrupo(conv.conversionInt(numeroGrupo));

		if (!numeroGrupo.empty() && !idInstructor.empty() && !nombreInstructor.empty() && !cupoMaximo.empty() &&
			!horarioData.empty() && !cantidadCuposUsados.empty()) {

			horario* h = conv.conversionHorario(horarioData);

			grupoAux = new grupo(
				conv.conversionInt(numeroGrupo),
				conv.conversionInt(cupoMaximo),
				conv.conversionInt(cantidadCuposUsados),
				h,
				new profesor(nombreInstructor, idInstructor, "", "", "")
			);
			grupoAux->setEstudiantes(estudiantes);
		}

		if (entrada.good() && grupoAux) {
			listaAux->insertarPrimero(grupoAux);
		}
	}

	entrada.close();
	return listaAux;
}

listaCurso* archivo::recuperarCursos() {
	listaCurso* listaAux = new listaCurso();
	string idCurso, nombreCurso, horas, precio, disponibilidad;
	listaGrupo* grupos;
	curso* cursoAux = nullptr;

	entrada.open("Archivos/cursosAcademia.txt");

	while (entrada.good()) {
		getline(entrada, idCurso, '\t');
		getline(entrada, nombreCurso, '\t'); 
		getline(entrada, horas, '\t'); 
		getline(entrada, precio, '\t'); 
		getline(entrada, disponibilidad, '\n');
		grupos = recuperarGruposCurso(idCurso); 

		if (!idCurso.empty() && !nombreCurso.empty() && !horas.empty() && !precio.empty() && !disponibilidad.empty()) {
			bool disp = (disponibilidad == "1"); 

			cursoAux = new curso( 
				nombreCurso, 
				idCurso, 
				conv.conversionInt(horas),  
				conv.conversionFloat(precio), 
				disp 
			);
			cursoAux->setGrupos(grupos); 
		}

		if (entrada.good() && cursoAux) { 
			listaAux->insertarPrimero(cursoAux); 
		}
	}

	entrada.close(); 
	return listaAux;
}

listaPeriodo* archivo::recuperarPeriodos() {
	listaPeriodo* listaAux = new listaPeriodo();
	string numPeriodo, mesInicio, mesFin;
	listaCurso* cursos;
	periodo* periodoAux = nullptr;

	entrada.open("Archivos/periodosAcademia.txt");

	while (entrada.good()) {
		getline(entrada, numPeriodo, '\t');
		getline(entrada, mesInicio, '\t');
		getline(entrada, mesFin, '\n');

		if (!numPeriodo.empty() && !mesInicio.empty() && !mesFin.empty()) {
			int numeroPeriodoInt = conv.conversionInt(numPeriodo);

			cursos = recuperarCursosPeriodo(numeroPeriodoInt);

			periodoAux = new periodo(numeroPeriodoInt);
			periodoAux->setCursos(cursos);
		}

		if (entrada.good() && periodoAux) {
			listaAux->insertarPrimero(periodoAux);
		}
	}

	entrada.close();
	return listaAux;
}

listaEstudiante* archivo::recuperarEstudiantesGrupo(int numeroGrupo_) {
	listaEstudiante* listaAux = new listaEstudiante();
	entradaAux.open("Archivos/estudiantesGrupo.txt");
	string grupoNum, id, nombre, especialidad, telefono, email;
	estudiante* est = nullptr;

	while (entradaAux.good()) {
		getline(entradaAux, grupoNum, '\t');
		getline(entradaAux, id, '\t');
		getline(entradaAux, nombre, '\t');
		getline(entradaAux, especialidad, '\t');
		getline(entradaAux, telefono, '\t');
		getline(entradaAux, email, '\n');

		if (!grupoNum.empty() && !id.empty() && !nombre.empty() && !especialidad.empty() && !telefono.empty() && !email.empty()) { 
			if (numeroGrupo_ == conv.conversionInt(grupoNum)) {
				est = new estudiante(nombre, id, especialidad, telefono, email);
				listaAux->insertarPrimero(est);
			}
		}
	}
	entradaAux.close(); 
	return listaAux;
}

listaGrupo* archivo::recuperarGruposCurso(string idCurso) {
	listaGrupo* listaAux = new listaGrupo();
	string cursoId, numeroGrupo, idInstructor, nombreInstructor, cupoMaximo, horarioData, cantidadCuposUsados;
	listaEstudiante* estudiantes;
	grupo* grupoAux = nullptr;

	entradaAux.open("Archivos/gruposCurso.txt");

	while (entradaAux.good()) {
		getline(entradaAux, cursoId, '\t');

		if (cursoId == idCurso) {
			getline(entradaAux, numeroGrupo, '\t');
			getline(entradaAux, idInstructor, '\t');
			getline(entradaAux, nombreInstructor, '\t');
			getline(entradaAux, cupoMaximo, '\t');
			getline(entradaAux, horarioData, '\t');
			getline(entradaAux, cantidadCuposUsados, '\n');
			estudiantes = recuperarEstudiantesGrupo(conv.conversionInt(numeroGrupo));

			if (!numeroGrupo.empty() && !idInstructor.empty() && !nombreInstructor.empty() && !cupoMaximo.empty() &&
				!horarioData.empty() && !cantidadCuposUsados.empty()) {

				horario* h = conv.conversionHorario(horarioData);

				grupoAux = new grupo(
					conv.conversionInt(numeroGrupo),
					conv.conversionInt(cupoMaximo),
					conv.conversionInt(cantidadCuposUsados),
					h,
					new profesor(nombreInstructor, idInstructor, "", "", "")  
				);
				grupoAux->setEstudiantes(estudiantes); 
			}

			if (entradaAux.good() && grupoAux) {
				listaAux->insertarPrimero(grupoAux);
			}
		}
		else {
			getline(entradaAux, numeroGrupo, '\n');
		}
	}

	entradaAux.close();
	return listaAux;
}

listaGrupo* archivo::recuperarGruposPeriodo(int numPeriodo) {
	listaGrupo* listaAux = new listaGrupo();
	string periodoId, numeroGrupo, idInstructor, nombreInstructor, cupoMaximo, horarioData, cantidadCuposUsados;
	listaEstudiante* estudiantes;
	grupo* grupoAux = nullptr;

	entradaAux.open("Archivos/gruposPeriodo.txt");

	while (entradaAux.good()) {
		getline(entradaAux, periodoId, '\t');

		if (conv.conversionInt(periodoId) == numPeriodo) {
			getline(entradaAux, numeroGrupo, '\t');
			getline(entradaAux, idInstructor, '\t');
			getline(entradaAux, nombreInstructor, '\t');
			getline(entradaAux, cupoMaximo, '\t');
			getline(entradaAux, horarioData, '\t');
			getline(entradaAux, cantidadCuposUsados, '\n');

			estudiantes = recuperarEstudiantesGrupo(conv.conversionInt(numeroGrupo));

			if (!numeroGrupo.empty() && !idInstructor.empty() && !nombreInstructor.empty() &&
				!cupoMaximo.empty() && !horarioData.empty() && !cantidadCuposUsados.empty()) {

				horario* h = conv.conversionHorario(horarioData);

				grupoAux = new grupo(
					conv.conversionInt(numeroGrupo),
					conv.conversionInt(cupoMaximo),
					conv.conversionInt(cantidadCuposUsados),
					h,
					new profesor(nombreInstructor, idInstructor, "", "", "")
				);
				grupoAux->setEstudiantes(estudiantes);
			}

			if (entradaAux.good() && grupoAux) {
				listaAux->insertarPrimero(grupoAux);
			}
		}
		else {
			getline(entradaAux, numeroGrupo, '\n');
		}
	}

	entradaAux.close();
	return listaAux;
}

listaCurso* archivo::recuperarCursosPeriodo(int numPeriodo) {
	listaCurso* listaAux = new listaCurso();
	string periodoId, idCurso, nombreCurso, horas, precio, disponibilidad;
	listaGrupo* grupos;
	curso* cursoAux = nullptr;

	entradaAux2.open("Archivos/cursosPeriodo.txt");

	while (entradaAux2.good()) {
		getline(entradaAux2, periodoId, '\t');

		if (conv.conversionInt(periodoId) == numPeriodo) {
			getline(entradaAux2, idCurso, '\t');
			getline(entradaAux2, nombreCurso, '\t');
			getline(entradaAux2, horas, '\t');
			getline(entradaAux2, precio, '\t');
			getline(entradaAux2, disponibilidad, '\n');

			grupos = recuperarGruposCurso(idCurso);

			if (!idCurso.empty() && !nombreCurso.empty() && !horas.empty() && !precio.empty() && !disponibilidad.empty()) {
				bool disp = (disponibilidad == "1");

				cursoAux = new curso(
					nombreCurso,
					idCurso,
					conv.conversionInt(horas),
					conv.conversionFloat(precio),
					disp
				);
				cursoAux->setGrupos(grupos);
			}

			if (entradaAux2.good() && cursoAux) {
				listaAux->insertarPrimero(cursoAux);
			}
		}
		else {
			getline(entradaAux2, idCurso, '\n');
		}
	}

	entradaAux2.close();
	return listaAux;
}





