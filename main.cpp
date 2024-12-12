#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "libros.h"
#include "biblioteca.h"
#include "extras.h"

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


int main() {
    Biblioteca biblioteca;
    SetConsoleOutputCP(CP_UTF8);

    string nombre, contrasena;
    cout << "Ingrese su nombre de administrador: ";
    cin >> nombre;
    cout << "Ingrese su contraseña: ";
    cin >> contrasena;

    if (!esAdministrador(nombre, contrasena)) {
        cout << "Acceso denegado. Usuario no encontrado." << endl;
        return 0;  
    }

    int resp;
    do {
        imprimirLogo();
        cout << "MENU: " << endl;
        cout << "1) Agregar un préstamo." << endl;
        cout << "2) Agregar un libro." << endl;
        cout << "3) Quitar un libro." << endl;
        cout << "4) Lista de libros." << endl;
        cout << "5) Lista usuarios registrados." << endl;
        cout << "6) Lista administradores." << endl;
        cout << "7) Historial de préstamos." << endl;
        cout << "0) Salir." << endl;
        cout << "Digite su respuesta: ";
        cin >> resp;

        switch (resp) {
            case 1:
                registrarPrestamo1(biblioteca);
                break;

            case 2: {
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
                cout << "Eliminar un libro por ID\n\n";
                int id;
                cout << "ID del libro a eliminar: "; cin >> id;
                biblioteca.quitarLibro(id);
                break;

            case 4:
                biblioteca.mostrarLibros();
                break;

            case 5:
                biblioteca.mostrarUsuarios();
                break;

            case 6:
                mostrarAdministradores();  
                break;

            case 7:
                biblioteca.mostrarPrestamos();
                break;

            default:
                cout << "Opción inválida." << endl;
                break;
        }

        cout << endl << endl;
        system("pause");
        system("cls");

    } while (resp != 0);

    return 0;
}
