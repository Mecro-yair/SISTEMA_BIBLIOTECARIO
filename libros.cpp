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
	entregado = true;
}

int Libro::llamarId(){
    return id;
}

string Libro::llamarTitulo() {
    return titulo;
}

string Libro::llamarAutor(){
    return autor;
}
int Libro::llamarAnio(){
    return anio;
}

int Libro::llamarCantidad(){
    return cantidad;
}

bool Libro::llamarEntregado() {
    return entregado;  
}
void Libro::mostrarLibro(){
	cout<<"ID: "<<id <<"  ";
	cout<<"Titulo: "<<titulo<<"   ";
	cout<<"Autor: "<<autor;
}
void Libro::reducirCantidad(){
	cantidad=cantidad-1;
}
