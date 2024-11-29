#include "usuario.h"
#include <algorithm>
#include <vector>

Usuario::Usuario(string _dni,string _nombre, string _email){
	dni = _dni;
	nombre = _nombre;
	email = _email;
}

string Usuario::DNI(){
    return dni;
}

string Usuario::Nombre(){
    return nombre;
}

string Usuario::Email(){
    return email;
}

void Usuario::pedirLibro(string idLibro) {
    librosPedidos.push_back(idLibro);
}

bool Usuario::tieneLibroPendiente(string idLibro){
    return find(librosPedidos.begin(), librosPedidos.end(), idLibro) != librosPedidos.end();
}

void Usuario::entregarLibro(string idLibro) {
    librosPedidos.erase(remove(librosPedidos.begin(), librosPedidos.end(), idLibro), librosPedidos.end());
}

vector<string> Usuario::LibrosPedidos(){
    return librosPedidos;
}
