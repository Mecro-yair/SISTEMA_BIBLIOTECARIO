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
        
        while (getline(archivo, linea)) {
        	size_t pos=0;
        	int id, anio, cantidad, entregado;
        	string titulo, autor, dato;
            
            
            
            pos = linea.find("|");
            dato=linea.substr(0,pos);
            id=stoi(dato);
            linea.erase(0,pos+1);

            
            pos = linea.find("|");
            titulo= linea.substr(0,pos);
            linea.erase(0,pos+1);
            

            
            pos=linea.find("|");
            autor=linea.substr(0,pos);
            linea.erase(0,pos+1);

            
            pos=linea.find("|");
            dato= linea.substr(0,pos);
            anio=stoi(dato);
            linea.erase(0,pos+1);

       
            pos=linea.find("|");
            dato=linea.substr(0,pos);
            cantidad=stoi(dato);
            
            
            pos=linea.find("|");
            dato=linea.substr(0,pos);
            entregado = stoi(dato); 
            bool entregadoBool = (entregado == 1);  // 1 es verdadero, 0 es falso
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
	ifstream archivo("prestamos.txt"); 
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        size_t pos = 0;
        string FE,FD,dato,dni;
        int id;
            
            pos = linea.find("|");
            dni = linea.substr(0, pos);
            linea.erase(0, pos + 1); 

            // Extraer id
            pos = linea.find("|");
            dato = linea.substr(0, pos);
            id=stoi(dato);
            linea.erase(0, pos + 1); 

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
            
           
            prestamos.push_back(Prestamos(&usuarios[i-1],&libros[j-1] ,FE,FD));
    }

    archivo.close();
    cout << "Se cargaron " << prestamos.size() << " prestamos correctamente." << endl;
}
void Biblioteca::agregarLibro(int id, string titulo, string autor, int anio, int cantidad) {
    
    Libro nuevoLibro(id, titulo, autor, anio, cantidad);
    
   
    libros.push_back(nuevoLibro);

   
    guardarLibrosEnArchivo(nuevoLibro);
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
	if(libros[j-1].llamarCantidad()<=0){
		cout<<"Ya no quedan ejemplares de este libro.\n";
		return;
	}
	
	int i=0;
	
    c=false;
    while(i<usuarios.size()&&c!=true){
        if(usuarios[i].getDni()==dniUsu){
			c=true;
		}
		i++;
	}
            
	libros[j-1].reducirCantidad();
    prestamos.push_back(Prestamos(&usuarios[i-1],&libros[j-1] ,FE,FD));
	guardarPrestamosEnArchivo(dniUsu,idLibro,FE, FD);
	
}


void Biblioteca::guardarLibrosEnArchivo(Libro& libroNuevo) {
    ofstream archivo("libros.txt", ios::app);  

    if (archivo.is_open()) {
        
        string entregado = (libroNuevo.llamarEntregado()) ? "1" : "0";
        

        archivo << libroNuevo.llamarId() << "|"
                << libroNuevo.llamarTitulo() << "|"
                << libroNuevo.llamarAutor() << "|"
                << libroNuevo.llamarAnio() << "|"
                << libroNuevo.llamarCantidad() << "|"
                << entregado << "|" << endl;

        archivo.close();
        cout << "Nuevo libro agregado correctamente al archivo." << endl;
    } else {
        cout << "No se pudo abrir el archivo libros.txt para agregar el nuevo libro." << endl;
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
	ofstream archivo("prestamos.txt", ios::app);  

    if (archivo.is_open()){
        
        	 
			archivo << dniUsu << "|"
			        << idLibro << "|"
			        << FE << "|"
			        << FD<< "|"
			        << endl;
        
        archivo.close();
        cout << "Prestamo de libro guardado correctamente." << endl;
        
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
    
    if (libros.empty()) {
        cout << "No hay libros disponibles en la biblioteca." << endl;
        return;
    }

    
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

void Biblioteca::guardarLibrosEnArchivo() {
    ofstream archivo("libros.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo para guardar." << endl;
        return;
    }

    int i = 0;
    while (i < libros.size()) {
        
        archivo << libros[i].llamarId() << "|"
                << libros[i].llamarTitulo() << "|"
                << libros[i].llamarAutor() << "|"
                << libros[i].llamarAnio() << "|"
                << libros[i].llamarCantidad() << "|"
                << libros[i].llamarEntregado()<<"|" 
                << endl;
        i++;
    }

    archivo.close();
    cout << "Se guardaron " << libros.size() << " libros en el archivo correctamente." << endl;
}
