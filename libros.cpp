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
    entregado=false;
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

bool Libro::esEntregado(){
    return entregado;
}

void Libro::actualizaEntregado(bool valor) {
    entregado = valor;
}

void Libro::reducirCantidad() {
    if (cantidad > 0) {
        cantidad--;
    }
}


