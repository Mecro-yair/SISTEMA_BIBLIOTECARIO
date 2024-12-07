#ifndef PRESTAMOS_H
#define PRESTAMOS_H
#include <iostream>
#include "usuario.h"
#include "libros.h"
#include "persona.h"
class Usuario;
class Prestamos{
	private:
	Usuario* usuario;
	Libro* libro;
	std::string FechaEntrega;
	std::string FechaDevolucion;
};
#endif