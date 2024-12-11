#include <iostream>
#include "prestamos.h"
#include "usuario.h"
#include "persona.h"

using namespace std;

void Prestamos::mostrarPrestamo(){
	cout<<"Datos de usuario --> ";
	usuario->mostrarPersona();
	cout<<endl;
	cout<<"Datos de Libro --> ";
	libro->mostrarLibro();
	cout<<endl;
	cout<<"Fecha de Entrega: "<<FechaEntrega<<endl;
	cout<<"Fecha de Devolución: "<<FechaDevolucion;
}