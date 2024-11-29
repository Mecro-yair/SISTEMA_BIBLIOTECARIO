#include "libros.h"
#include <fstream>
#include <iostream>
using namespace std;
//aqui los metodos de libros.h
Libro::Libro(int id1, string titulo1,string autor1, int anio1, int cantidad1){
	id=id1;
    titulo=titulo1;
    autor=autor1;
    anio=anio1;
    cantidad=cantidad1;
}
void agregarLibro(){
	int id1,anio1,cantidad1;
	string titulo1,autor1;
	
	cin.ignore();
	cout<<"Ingrese el autor: ";getline(cin,autor1);
	cout<<"Ingrese el titulo del libro:";getline(cin,titulo1);
	cout<<"Ingrese el ID:";cin>>id1;
	cout<<"Ingrese el año de publicacion:";cin>>anio1;
	cout<<"Ingrese la cantidad de libros:";cin>>cantidad1;
	
	ofstream Archivo;
	
	Archivo.open("libros.txt",ios::app);
	
	if(Archivo.is_open()){
		Archivo<<id1<<" "<<titulo1<<" "<<autor1<<" "<<anio1<<" "<<cantidad1<<endl;
		Archivo.close();
	}else{
		cout << "No se pudo abrir el archivo." << endl;
	}
	
	
}

void Libro::quitarLibro(){
	
}
void mostrarLibros(){
	ifstream archivo("libros.txt");
    string linea;

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            cout << linea << endl; // Mostrar el contenido del archivo
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}