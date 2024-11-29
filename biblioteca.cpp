#include "biblioteca.h"
#include <iostream>
#include <algorithm>

Biblioteca::Biblioteca() {
    cargarLibros();
    cargarUsuarios();
    cargarPedidos();
}



void Biblioteca::cargarLibros() {
    ifstream archivo;
    archivo.open("libros.txt");
    if (archivo.is_open()) {
        int id, anio, cantidad;
        bool entregado;
        string titulo, autor;
        while (archivo >> id >> titulo >> autor >> anio >> cantidad >> entregado) {
        	
            libros.push_back(Libro(id, titulo, autor, anio, cantidad));
        }
        archivo.close();
    }
}

void Biblioteca::cargarUsuarios() {
    ifstream archivo("usuarios.txt");
    if (archivo.is_open()) {
        int id;
        string nombre, email;
        while (archivo >> id >> nombre >> email) {
        	
            usuarios.push_back(Usuario(id, nombre, email));
        }
        archivo.close();
    }
}

