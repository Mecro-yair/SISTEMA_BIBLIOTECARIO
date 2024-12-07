#include "biblioteca.h"	
#include <iostream>
#include <algorithm>

Biblioteca::Biblioteca() {
    cargarLibros();
    cargarUsuarios();
    //cargarPedidos();
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
        
        string dni, nombre, email;
        int edad;
        char sexo;
        while (archivo >>  dni >> nombre >>edad >> sexo >> email) {
        	
            usuarios.push_back(Usuario(dni,nombre,email,edad,sexo));
        }
        archivo.close();
    }
} 

void Biblioteca::agregarLibro(int id, string titulo, string autor, int anio, int cantidad) {
    libros.push_back(Libro(id, titulo, autor, anio, cantidad));
    guardarLibrosEnArchivo();
}
void Biblioteca::agregarUsuario(string dni, string nombre, string email, int edad, char sexo){
	usuarios.push_back(Usuario(dni, nombre,email,edad,sexo));
	guardarUsuariosEnArchivo();
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
void Biblioteca::guardarUsuariosEnArchivo(){
	ofstream archivo("usuarios.txt", ios::app);  // Abrir en modo "append"

    if (archivo.is_open()){
        for (int i = 0; i < usuarios.size(); ++i) {
        	 
			archivo << usuarios[i].getDni() << "|"
			        << usuarios[i].getNombre() << "|"
			        << usuarios[i].getEdad() << "|"
			        << usuarios[i].getSexo() << "|"
			        << usuarios[i].getEmail() << "|"
			        << endl;
        }
        archivo.close();
        cout << "Usuario guardado correctamente." << endl;
    } else {
        cout << "No se pudo abrir el archivo usuarios.txt para guardar los datos." << endl;
    }
}
