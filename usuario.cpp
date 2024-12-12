#include "usuario.h"
#include "prestamos.h"
#include <algorithm>
#include <vector>
using namespace std;
Usuario::Usuario(string _dni,string _nombre,string _email,int _edad,char _sexo):Persona(_dni,_nombre,_email,_edad,_sexo){
}


vector<Prestamos*> Usuario::getPrestamos(){
    return prestamos;
}
void Usuario::mostrarDatos(){
	mostrarPersona();
}
