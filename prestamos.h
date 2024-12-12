#ifndef PRESTAMOS_H
#define PRESTAMOS_H
#include <iostream>
//#include "usuario.h"
#include "libros.h"
//#include "persona.h"
class Usuario;
class Prestamos{
	private:
	Usuario* usuario;
	Libro* libro;
	std::string FechaEntrega;
	std::string FechaDevolucion;
	bool activo;
	public:
		Prestamos(Usuario* usu,Libro* lib,std::string FE,std::string FD){
			usuario=usu;
			libro=lib;
			FechaEntrega=FE;
			FechaDevolucion=FD;
			activo=true;
		}
		std::string getFechaEntrega();
		std::string getFechaDevolucion();
		Libro* getLibro();
		void mostrarPrestamo();
};
#endif