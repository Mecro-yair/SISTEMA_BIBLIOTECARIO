#ifndef BIBLIOTECARIO_H
#define BIBLIOTECARIO_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

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

#endif