#include "usuario.h"
#include <algorithm>
#include <vector>

Usuario::Usuario(int _dni,string _nombre, string _email){
	dni = _dni;
	nombre = _nombre;
	email = _email;
}

int Usuario::dni(){
    return dni;
}

string Usuario::nombre(){
    return nombre;
}

string Usuario::email(){
    return email;
}

void Usuario::pedirLibro(string idLibro) {
    librosPedidos.push_back(libroId);
}

bool Usuario::tieneLibroPendiente(string idLibro){
    return find(librosPedidos.begin(), librosPedidos.end(), libroId) != librosPedidos.end();
}

void Usuario::entregarLibro(string idLibro) {
    librosPedidos.erase(remove(librosPedidos.begin(), librosPedidos.end(), libroId), librosPedidos.end());
}

int Usuario::LibrosPedidos(){
    return librosPedidos;
}
