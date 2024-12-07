#include <iostream>
#include <windows.h>
#include <fstream>
#include "libros.h"
#include "biblioteca.h"
using namespace std;

int main() {
    Biblioteca biblioteca;
	SetConsoleOutputCP(CP_UTF8);
    string nombre, email,dni;
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
	system("cls");

    int opcion;
    do {
    	system("cls");
        cout << "--- Menu ---\n" << endl;
        cout << "1. Añadir libro" << endl;
        cout << "2. Pedir libro" << endl;
        cout << "3. Entregar libro" << endl;
        cout << "4. Mostrar libros pendientes de entrega" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opción: "; cin >> opcion;

        switch(opcion) {
            case 1: {
            	system("cls");
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
            case 2: {
 				system("cls");
 				cout << "PEDIDO DE LIBRO\n\n";
                int libroId;
                cout << "ID del libro a pedir: "; cin >> libroId;
                break;
            }
            case 3: {
 				system("cls");
 				cout << "ENTREGA DE LIBRO\n\n";
                int libroId;
                cout << "ID del libro a entregar: "; cin >> libroId;
                break;
            }
            case 4:
 				system("cls");
                break;
            case 5:
 				system("cls");
                cout << "Se retiró exitosamente." << endl;
                break;
            default:
 				system("cls");
                cout << "Opción inválida." << endl;
        }
    } while(opcion != 5);

    return 0;
}