#include "biblioteca.h"	
#include <iostream>
#include <algorithm>
#include "usuario.h"
#include "libros.h"
#include <sstream>
#include <string> 

using namespace std;
Biblioteca::Biblioteca() {
    cargarLibros();
    cargarUsuarios();
    cargarPrestamos();
}



void Biblioteca::cargarLibros() {
    ifstream archivo("libros.txt");
    
    if (archivo.is_open()) {
       
		string linea;
        // Leer línea por línea
        while (getline(archivo, linea)) {
        	size_t pos=0;
        	int id, anio, cantidad, entregado;
        	string titulo, autor, dato;
            
            
            // Leer el ID
            pos = linea.find("|");
            dato=linea.substr(0,pos);
            id=stoi(dato);
            linea.erase(0,pos+1);

            // Leer el título
            pos = linea.find("|");
            titulo= linea.substr(0,pos);
            linea.erase(0,pos+1);
            

            // Leer el autor
            pos=linea.find("|");
            autor=linea.substr(0,pos);
            linea.erase(0,pos+1);

            // Leer el año
            pos=linea.find("|");
            dato= linea.substr(0,pos);
            anio=stoi(dato);
            linea.erase(0,pos+1);

            // Leer la cantidad
            pos=linea.find("|");
            dato=linea.substr(0,pos);
            cantidad=stoi(dato);
            
            // Leer el entregado (asumiendo que se almacena como 1 o 0)
            pos=linea.find("|");
            dato=linea.substr(0,pos);
            entregado = stoi(dato); // Convierte de string a int
            bool entregadoBool = (entregado == 1);  // 1 es verdadero, 0 es falso
            // Crear el objeto libro y agregarlo al vector
            libros.push_back(Libro(id, titulo, autor, anio, cantidad));
        }

        archivo.close();
        cout << "Se cargaron " << libros.size() << " Libros correctamente." << endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

void Biblioteca::cargarUsuarios() {
	
    ifstream archivo("usuarios.txt");
    
    if (archivo.is_open()) {
        
        // Leer línea por línea
        string linea;
        while (getline(archivo, linea)) {
        	size_t pos=0;
            string dni, nombre, email,dato;
        	int edad;
        	char sexo;
        	//Extraer dni
        	pos=linea.find("|");
        	dni = linea.substr(0,pos);
        	linea.erase(0,pos+1);
			//extraer nombre
			pos=linea.find("|");
			nombre = linea.substr(0,pos);
			linea.erase(0,pos+1);
			//extraer edad
			pos=linea.find("|");
			dato=linea.substr(0,pos);
			edad=stoi(dato);
			linea.erase(0,pos+1);
			//extraer sexo
			pos=linea.find("|");
			dato=linea.substr(0,pos);
			sexo=dato[0];
			linea.erase(0,pos+1);
			
			pos=linea.find("|");
			email=linea.substr(0,pos);
            
			usuarios.push_back(Usuario(dni,nombre,email,edad,sexo));
        }

        archivo.close();
        cout << "Se cargaron " << usuarios.size() << " usuarios correctamente." << endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    
} 
void Biblioteca::cargarPrestamos(){
	ifstream archivo("prestamos.txt"); // Abrir el archivo
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        size_t pos = 0;
        string FE,FD,dato,dni;
        int id;
            // Extraer dni
            pos = linea.find("|");
            dni = linea.substr(0, pos);
            linea.erase(0, pos + 1); // Eliminar el autor y la coma

            // Extraer id
            pos = linea.find("|");
            dato = linea.substr(0, pos);
            id=stoi(dato);
            linea.erase(0, pos + 1); // Eliminar el año y la coma

            // Extraer fechA DE entrega
            pos = linea.find("|"); 
			FE = linea.substr(0,pos);
			linea.erase(0,pos+1);
			
			//Extraer fecha de Fecha de devolucion
			pos=linea.find("|");
			FD=linea.substr(0, pos);
            
			int j=0;
			bool c=false;
			while(j<libros.size()&&c!=true){
				if(libros[j].llamarId()==id){
					c=true;
				}
				j++;
			}
			int i=0;
            c=false;
            while(i<usuarios.size()&&c!=true){
            	if(usuarios[i].getDni()==dni){
					c=true;
				}
				i++;
			}
            
            // Crear un objeto Libro y agregarlo al vector
            prestamos.push_back(Prestamos(&usuarios[i-1],&libros[j-1] ,FE,FD));
    }

    archivo.close();
    cout << "Se cargaron " << prestamos.size() << " prestamos correctamente." << endl;
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
	int j=0;
	bool c=false;
	while(j<libros.size()&&c!=true){
		if(libros[j].llamarId()==idLibro){
			c=true;
		}
		j++;
	}
	int i=0;
    c=false;
    while(i<usuarios.size()&&c!=true){
        if(usuarios[i].getDni()==dniUsu){
			c=true;
		}
		i++;
	}
            
    // Crear un objeto Libro y agregarlo al vector
    prestamos.push_back(Prestamos(&usuarios[i-1],&libros[j-1] ,FE,FD));
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
			        << entregado<<"|" << endl;
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
void Biblioteca::mostrarUsuarios(){
	if(usuarios.empty()){
		cout << "No hay ningun usuario registrado." << endl;
        return;	
	}
	for(size_t i=0; i<usuarios.size();i++){
		cout<<"Usuario "<<i+1<<"-->  ";
		usuarios[i].mostrarPersona();
		cout<<endl;
	}
}
void Biblioteca::mostrarPrestamos(){
	if(prestamos.empty()){
		cout << "No existen prestamos actualmente."<<endl;
		return;
	}
	cout<<"--------------------------------------\n";
	for(size_t i=0; i<prestamos.size();i++){
		//cout<<"--------------------------------------\n";
		cout<<"Prestamo: "<<i+1<<": \n";
		prestamos[i].mostrarPrestamo();
		cout<< "\n--------------------------------------";
		cout<<endl;
	}
}
void Biblioteca::quitarLibro(int id) {
    for (size_t i = 0; i < libros.size(); i++) {
        if (libros[i].llamarId() == id) {
            for (size_t j = 0; j < prestamos.size(); j++) {
                if (prestamos[j].getLibro()->llamarId() == id) {
                    cout << "El libro no se puede eliminar porque está asociado a un préstamo." << endl;
                    return;
                }
            }
            libros.erase(libros.begin() + i);
            ofstream archivo("libros.txt");
            if (archivo.is_open()) {
                for (size_t k = 0; k < libros.size(); k++) {
                    archivo << libros[k].llamarId() << "|";
                    archivo << libros[k].llamarTitulo() << "|";
                    archivo << libros[k].llamarAutor() << "|";
                    archivo << libros[k].llamarAnio() << "|";
                    archivo << libros[k].llamarCantidad() << "|";
                    bool entregado = libros[k].llamarEntregado();
                    string estadoEntregado;
                    if (entregado) {
                        estadoEntregado = "1";
                    } else {
                        estadoEntregado = "0";
                    }
                    archivo << estadoEntregado << "|";
                    archivo << endl; 
                }
                archivo.close();
                cout << "El libro fue quitado." << endl;
            } else {
                cout << "No se pudo actualizar el archivo libros.txt." << endl;
            }
            return;
        }
    }
    cout << "No se encontró un libro con el ID proporcionado." << endl;
}