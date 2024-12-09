#include "biblioteca.h"	
#include <iostream>
#include <algorithm>
#include "usuario.h"
#include "libros.h"
#include <sstream> 
using namespace std;
Biblioteca::Biblioteca() {
    cargarLibros();
    cargarUsuarios();
    //cargarPedidos();
}



void Biblioteca::cargarLibros() {
    ifstream archivo("libros.txt");
    
    if (archivo.is_open()) {
        int id, anio, cantidad, entregado;
        string titulo, autor, linea;

        // Leer línea por línea
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            
            // Leer el ID
            getline(ss, linea, '|');
            id = stoi(linea); // Convierte de string a int

            // Leer el título
            getline(ss, titulo, '|');

            // Leer el autor
            getline(ss, autor, '|');

            // Leer el año
            getline(ss, linea, '|');
            anio = stoi(linea); // Convierte de string a int

            // Leer la cantidad
            getline(ss, linea, '|');
            cantidad = stoi(linea); // Convierte de string a int

            // Leer el entregado (asumiendo que se almacena como 1 o 0)
            getline(ss, linea, '|');
            entregado = stoi(linea); // Convierte de string a int
            bool entregadoBool = (entregado == 1);  // 1 es verdadero, 0 es falso

            // Crear el objeto libro y agregarlo al vector
            libros.push_back(Libro(id, titulo, autor, anio, cantidad));
        }

        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
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
	guardarUsuariosEnArchivo(dni, nombre, email,edad,sexo);
}
void Biblioteca::agregarPrestamo(string  dniUsu,int idLibro,string FE, string FD){
	bool cen=false;
	Usuario usu;
	Libro lib;
	for(int i=0; usuarios.size()>i&&cen!=true;i++){
		if(dniUsu==usuarios[i].getDni()){
			cen=true;
			usu=usuarios[i];
		}
	}
	cen=false;
	for(int i=0; libros.size()>i&&cen!=true;i++){
		if(idLibro==libros[i].llamarId()){
			cen=true;
			lib=libros[i];
		}
	}
	
	prestamos.push_back(Prestamos(&usu,&lib,FE,FD));
	guardarPrestamosEnArchivo(dniUsu,idLibro,FE, FD);
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
void Biblioteca::guardarUsuariosEnArchivo(string dni, string nombre, string email, int edad, char sexo){
	ofstream archivo("usuarios.txt", ios::app);  // Abrir en modo "append"

    if (archivo.is_open()){
        
        	 
			archivo << dni << "|"
			        << nombre << "|"
			        << edad << "|"
			        << sexo<< "|"
			        << email << "|"
			        << endl;
        
        archivo.close();
        cout << "Usuario guardado correctamente." << endl;
    } else {
        cout << "No se pudo abrir el archivo usuarios.txt para guardar los datos." << endl;
    }
}
void Biblioteca::guardarPrestamosEnArchivo(string  dniUsu,int idLibro,string FE, string FD){
	ofstream archivo("prestamos.txt", ios::app);  // Abrir en modo "append"

    if (archivo.is_open()){
        
        	 
			archivo << dniUsu << "|"
			        << idLibro << "|"
			        << FE << "|"
			        << FD<< "|"
			        << endl;
        
        archivo.close();
        cout << "Prestamo guardado correctamente." << endl;
    } else {
        cout << "No se pudo abrir el archivo usuarios.txt para guardar los datos." << endl;
    }
}

vector<Usuario> Biblioteca::getUsuarios(){
	return usuarios;
}
vector<Prestamos> Biblioteca::getPrestamos(){
	return prestamos;
}
    
vector<Libro> Biblioteca::getLibros(){
	return libros;
}
void Biblioteca::mostrarLibros() {
    // Verifica si el vector de libros está vacío
    if (libros.empty()) {
        cout << "No hay libros disponibles en la biblioteca." << endl;
        return;
    }

    // Muestra los detalles de cada libro en el vector
    for (Libro libro : libros) {
        cout << "ID: " << libro.llamarId() << endl;
        cout << "Título: " << libro.llamarTitulo() << endl;
        cout << "Autor: " << libro.llamarAutor() << endl;
        cout << "Año: " << libro.llamarAnio() << endl;
        cout << "Cantidad: " << libro.llamarCantidad() << endl;
        cout << "Entregado: " << (libro.llamarEntregado() ? "Sí" : "No") << endl;
        cout << "----------------------" << endl;
    }
}
