#include "usuario.h"
#include "prestamos.h"
#include <algorithm>
#include <vector>
using namespace std;
Usuario::Usuario(string _dni,string _nombre,string _email,int _edad,char _sexo):Persona(_dni,_nombre,_email,_edad,_sexo){
}

/*void Usuario::pedirLibro(string idLibro) {
    librosPedidos.push_back(idLibro);
}

bool Usuario::tieneLibroPendiente(string idLibro){
    return find(librosPedidos.begin(), librosPedidos.end(), idLibro) != librosPedidos.end();
}

void Usuario::entregarLibro(string idLibro) {
    librosPedidos.erase(remove(librosPedidos.begin(), librosPedidos.end(), idLibro), librosPedidos.end());
}*/

vector<Prestamos*> Usuario::getPrestamos(){
    return prestamos;
}
void Usuario::mostrarDatos(){
	mostrarPersona();
}
