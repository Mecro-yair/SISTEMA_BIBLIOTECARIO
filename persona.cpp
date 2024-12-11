#include <iostream>
#include "persona.h"


using namespace std;

Persona::Persona(string _dni,string _nombre,string _email,int _edad,char _sexo){
	dni=_dni;
	nombre=_nombre;
	email=_email;
	edad=_edad;
	sexo=_sexo;
}
string Persona::getDni(){
    return dni;
}

string Persona::getNombre(){
    return nombre;
}

string Persona::getEmail(){
    return email;
}
int Persona::getEdad(){
	return edad;
}
char Persona::getSexo(){
	return sexo;
}
void Persona::mostrarPersona(){
	cout <<"Dni: "<<dni<<"  ";
	cout<<"Nombre: "<<nombre<<"  ";
	cout<<"Email: "<<email<<"  ";
}