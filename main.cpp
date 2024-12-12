#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "libros.h"
#include "biblioteca.h"
#include "extras.h"
#include <windows.h>

using namespace std;

struct Administrador {
    string nombre;
    string contrasena;
};

vector<Administrador> leerAdministradores() {
    vector<Administrador> administradores;
    ifstream archivo("admin.txt");

    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string nombre, contrasena;
            getline(ss, nombre, '|');  
            getline(ss, contrasena);   

            administradores.push_back({nombre, contrasena});
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo admin.txt" << endl;
    }

    return administradores;
}

bool esAdministrador(string nombre, string contrasena) {
    vector<Administrador> administradores = leerAdministradores();

    for (int i = 0; i < administradores.size(); ++i) {
        if (administradores[i].nombre == nombre && administradores[i].contrasena == contrasena) {
            return true;
        }
    }
    return false;
}


void mostrarAdministradores() {
    vector<Administrador> administradores = leerAdministradores();  

    if (administradores.empty()) {
        cout << "No hay administradores registrados." << endl;
        return;
    }
	system("cls");
    cout << "Lista de administradores: " << endl;
    for (int i = 0; i < administradores.size(); ++i) {
        cout << administradores[i].nombre << endl; 
    }
}

void SetColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


int main() {
    Biblioteca biblioteca;
    SetConsoleOutputCP(CP_UTF8);

    string nombre, contrasena;
    SetColor(2);
    cout << "Ingrese su nombre de administrador: ";
    SetColor(1);
    cin >> nombre;
    SetColor(2);
    cout << "Ingrese su contraseña: ";
    SetColor(1);
    cin >> contrasena;

    if (!esAdministrador(nombre, contrasena)) {
        cout << "Acceso denegado. Usuario no encontrado." << endl;
        return 0;  
    }

    int resp;
    do {
        imprimirLogo();
        SetColor(4);
        cout << "MENU: " << endl;
        SetColor(7);
        cout << "1) Agregar un préstamo." << endl;
        cout << "2) Agregar un libro." << endl;
        cout << "3) Quitar un libro." << endl;
        cout << "4) Lista de libros." << endl;
        cout << "5) Lista usuarios registrados." << endl;
        cout << "6) Lista administradores." << endl;
        cout << "7) Historial de préstamos." << endl;
        cout << "0) Salir." << endl;
        cout << "Digite su respuesta: ";
        SetColor(2);
        cin >> resp;
		SetColor(7);
        switch (resp) {
            case 1:
            	system("cls");
                registrarPrestamo1(biblioteca);
                break;

            case 2: {
            	system("cls");
                cout << "AÑADIR UN NUEVO LIBRO\n\n";
                int id, anio, cantidad;
                string titulo, autor;
                cout << "ID del libro: "; SetColor(2); cin >> id;SetColor(7);
                cout << "Título del libro: "; cin.ignore();SetColor(2); getline(cin, titulo);SetColor(7);
                cout << "Autor: "; SetColor(2);getline(cin, autor);SetColor(7);
                cout << "Año de publicación: ";SetColor(2); cin >> anio;SetColor(7);
                cout << "Cantidad: "; cin >> cantidad;
                biblioteca.agregarLibro(id, titulo, autor, anio, cantidad);
                break;
            }

            case 3:
            	system("cls");
                cout << "Eliminar un libro por ID\n\n";
                int id;
                cout << "ID del libro a eliminar: "; SetColor(2); cin >> id;SetColor(7);
                biblioteca.quitarLibro(id);
                break;

            case 4:
            	system("cls");
                biblioteca.mostrarLibros();
                break;

            case 5:
            	system("cls");
                biblioteca.mostrarUsuarios();
                break;

            case 6:
            	system("cls");
                mostrarAdministradores();  
                break;

            case 7:
            	system("cls");
                biblioteca.mostrarPrestamos();
                break;

            default:
            	system("cls");
                cout << "Opción inválida." << endl;
                break;
        }

        cout << endl << endl;
        system("pause");
        system("cls");

    } while (resp != 0);

    return 0;
}
