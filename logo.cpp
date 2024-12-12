#include <iostream>
#include <windows.h>
#include <fstream>
#include "libros.h"
#include "biblioteca.h"
#include "extras.h"
using namespace std;

void setColor(int code) {
    cout << "\033[" << code << "m";
}


void resetColor() {
    cout << "\033[0m";
}


void imprimirColoreado(const char* texto[], int i) {
    
        for (int j = 0; texto[i][j] != '\0'; ++j) {
            if (texto[i][j] == '0') {
                setColor(43); // Fondo café 
                cout << " "; // Espacio coloreado
            } else if (texto[i][j] == ' ') {
                setColor(47); 
                cout << " "; // Espacio coloreado
            } else {
                resetColor(); // Color normal
                cout << texto[i][j];
            }
        }
        resetColor(); 
    
}

// Imprime la palabra BIBLIOTECA
void imprimirLogo() {
    const char* texto[9] = {
    "                                                                         ",	
    "  0000    000   0000    0     000   00000   00000  00000   0000    000   ", 
    "  0   0    0    0   0   0      0   0     0    0    0      0       0   0  ",
    "  0000     0    0000    0      0   0     0    0    000    0       00000  ", 
    "  0   0    0    0   0   0      0   0     0    0    0      0       0   0  ", 
    "  0000    000   0000    0000  000   00000     0    00000   0000   0   0  ",
	"                                                                         "
    };
	
    for (int i = 0; i < 7; ++i) {
        //std::cout << texto[i];
        cout<<"\t\t\t\t\t";
        setColor(41); // Fondo rojo
        cout << "       ";
        resetColor();
        imprimirColoreado(texto, i);
		//std::cout << texto[i]; // Parte roja de la bandera
        setColor(41); // Fondo rojo
        cout << "       "; // Parte roja de la bandera
        resetColor();
        cout << std::endl;
    }
    //std::cout<<"\t\t\t\t\t----------------------------------------------------------------------------"<<std::endl;*/
}
#include <limits>  // Para std::numeric_limits

void registrarPrestamo1(Biblioteca& biblioteca){
    string nombre, email, dni;
    int edad;
    char sexo;
    int cen = 0;

    do {
        cout << "Ingrese su DNI: "; 
        cin >> dni;
        
        if (dni.size() != 8) {
            cout << "\nError. No es el tamaño de un DNI.";
            cen = 0;
        }

        for (char c : dni) {
            if (!isdigit(c)) {
                cout << "\nError: El DNI solo puede contener números.\n";
                cen = 0;
            }
        }

        if (cen != 1) {
            cout << "Edad: "; cin >> edad;
            cout << "Sexo[H/M]: "; cin >> sexo;
            cout << "Ingrese su nombre y apellido: "; cin.ignore(); getline(cin, nombre);
            cout << "Ingrese su email: "; getline(cin, email);  
            cout << "\nInformacion agregada correctamente.\n\n";
            cout << "Presione enter para continuar con el menú.";
            cin.get();
            cen = 1;
        }

    } while (cen != 1);

    biblioteca.agregarUsuario(dni, nombre, email, edad, sexo);
    Usuario usu = biblioteca.getUsuarios()[biblioteca.getUsuarios().size() - 1];
    
    int id;
    cout << "\nIngrese el ID del libro: "; cin >> id;

    int id1 = 0;
    int i = 0;
    bool encontrado = false;

    while (i < biblioteca.getLibros().size() && !encontrado) {
        if (biblioteca.getLibros()[i].llamarId() == id) {
            id1 = biblioteca.getLibros()[i].llamarId(); 
            encontrado = true;
        }
        i++;
    }

    int dias;
    string Fpres = obtenerFechaHoraActual();

    cout << "\nIngrese la cantidad de días de préstamo: ";
    while (true) {
        cin >> dias;

        if (cin.fail() || dias <= 0) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Por favor, ingrese un número entero positivo para los días de préstamo: ";
        } else {
            break; 
        }
    }

    string Fdev = obtenerFechaDevolucion(dias);
    string dni1 = usu.getDni();
    biblioteca.agregarPrestamo(dni1, id1, Fpres, Fdev);
}


