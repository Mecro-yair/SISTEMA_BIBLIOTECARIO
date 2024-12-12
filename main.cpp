#include <iostream>
#include <windows.h>
#include <fstream>
#include "libros.h"
#include "biblioteca.h"
#include "extras.h"
using namespace std;

int main() {
	
    Biblioteca biblioteca;
	SetConsoleOutputCP(CP_UTF8);
	//biblioteca.cargarLibros();
	//biblioteca.cargarUsuarios();
	int resp;
	do{
		imprimirLogo();
		cout<<"MENU: "<<endl;
		cout<<"1) Agregar un prestamos."<<endl;
		cout<<"2) Agregar un libro."<<endl;
		cout<<"3) Quitar un libro."<<endl;
		cout<<"4) Lista de libros."<<endl;
		cout<<"5) Lista usuarios registrados."<<endl;
		cout<<"6) Lista administradores."<<endl;
		cout<<"7) Historial de Prestamos."<<endl;
		cout<<"8) Agregar nuevo administrador."<<endl;
		cout<<"0) Salir."<<endl;
		cout<<"Digite su respuesta: ";cin>>resp;
		
		switch(resp){
			case 1:
				registrarPrestamo1(biblioteca);
				//lleve todo lo que estaba aqui a logo.cpp y lo declare en extrs.h
				/*string nombre, email,dni;
    			int edad;
			    char sexo;
			    int cen=0;
			    do{
				    cout << "Ingrese su DNI: "; 
					cin >> dni;
				
				    if(dni.size() != 8){
				    	cout << "\nError. No es el tamaño de un DNI.";
				    	cen=0;
					}
					for (char c : dni) {
				    if (!isdigit(c)) {
				        cout << "\nError: El DNI solo puede contener números.\n";
				        cen=0;
				        }
				    }
				    if(cen!=1){
				    	cout << "Edad: ";cin>>edad;
						cout << "Sexo[H/M]: ";cin>>sexo;
						//cin.ignore();
						cout << "Ingrese su nombre y apellido: "; cin.ignore(); getline(cin, nombre);
						cout << "Ingrese su email: "; getline(cin, email);	
						cout << "\nInformacion agregada correctamente.\n\n";
						cout << "Presione enter para continuar con el menú.";
						cin.get();
						cen=1;
					}
					
					
				}while(cen!=1);
				biblioteca.agregarUsuario(dni,nombre,email,edad,sexo);
				Usuario usu=biblioteca.getUsuarios()[biblioteca.getUsuarios().size()-1];
				int id;
				cout<<"\nIngrese el ID del libro: ";cin>>id;
				int id1=0;
				int i = 0;
				bool encontrado = false;
				
				while (i < biblioteca.getLibros().size() && !encontrado) {
				    if (biblioteca.getLibros()[i].llamarId() == id) {
				        id1 = biblioteca.getLibros()[i].llamarId(); 
						encontrado=true;
				    }
				    i++;
				}
				int dias;
				string Fpres=obtenerFechaHoraActual();
				cout<<"\nIngrese la cantidad de dias de prestamos: ";cin>>dias;
				string Fdev =obtenerFechaDevolucion(dias);
				string dni1=usu.getDni();
				
				cout<<id1<<encontrado;
				biblioteca.agregarPrestamo(dni1,id1,Fpres,Fdev);*/
				break;
			
			case 2:{
				cout << "AÑADIR UN NUEVO LIBRO\n\n";
                int id, anio, cantidad;
                string titulo, autor;
                cout << "ID del libro: "; cin >> id;
                cout << "Título del libro: "; cin.ignore(); getline(cin, titulo);
                cout << "Autor: "; getline(cin, autor);
                cout << "Año de publicación: "; cin >> anio;
                cout << "Cantidad: "; cin >> cantidad;
                biblioteca.agregarLibro(id, titulo, autor, anio, cantidad);
				break;
			}
				
			case 3:
				int idLibro;
   				cout << "Ingrese el ID del libro que desea eliminar: ";
    			cin >> idLibro;
    			biblioteca.eliminarLibro(idLibro);
				break;
			case 4:
				biblioteca.mostrarLibros();
				break;
			case 5:
				biblioteca.mostrarUsuarios();
			case 6:
				break;
			case 7:
				biblioteca.mostrarPrestamos();
				break;	
			default:	
                cout << "Opción inválida." << endl;
                break;
		}
		cout<<endl<<endl;
		system("pause");
		system("cls");
		
	}while(resp!=0);
    

    return 0;
}