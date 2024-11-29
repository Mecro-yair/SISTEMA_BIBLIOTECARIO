#include "biblioteca.h"	
#include <iostream>
#include <algorithm>

Biblioteca::Biblioteca() {
    cargarLibros();
    cargarUsuarios();

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
        string dni;
        string nombre, email;
        while (archivo >>  dni >> nombre >> email) {
        	
            usuarios.push_back(Usuario(dni, nombre, email));
        }
        archivo.close();
    }
}

void Biblioteca::agregarLibro(int id, string titulo, string autor, int anio, int cantidad) {
    libros.push_back(Libro(id, titulo, autor, anio, cantidad));
    guardarLibrosEnArchivo();
}

void Biblioteca::guardarLibrosEnArchivo() {
    ofstream archivo("libros.txt", ios::app);  // Abrir en modo "append"

    if (archivo.is_open()){
        for (int i = 0; i < libros.size(); ++i) {
        	string entregado = "0";  

			if (libros[i].llamarEntregado()) {
			    entregado = "1";  
			}
			archivo << libros[i].llamarId() << "|"
			        << libros[i].llamarTitulo() << "|"
			        << libros[i].llamarAutor() << "|"
			        << libros[i].llamarAnio() << "|"
			        << libros[i].llamarCantidad() << "|"
			        << entregado << endl;
        }
        archivo.close();
        cout << "Libros guardados correctamente." << endl;
    } else {
        cout << "No se pudo abrir el archivo libros.txt para guardar los datos." << endl;
    }
}
