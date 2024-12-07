#include <iostream>
#include "extras.h"
// Cambia el color de la salida (compatible con terminales ANSI)
void setColor(int code) {
    std::cout << "\033[" << code << "m";
}

// Restaura el color por defecto
void resetColor() {
    std::cout << "\033[0m";
}

// Función para colorear el texto
void imprimirColoreado(const char* texto[], int i) {
    
        for (int j = 0; texto[i][j] != '\0'; ++j) {
            if (texto[i][j] == '0') {
                setColor(43); // Fondo café (amarillo oscuro)
                std::cout << " "; // Espacio coloreado
            } else if (texto[i][j] == ' ') {
                setColor(47); // Fondo blanco
                std::cout << " "; // Espacio coloreado
            } else {
                resetColor(); // Color normal
                std::cout << texto[i][j];
            }
        }
        resetColor(); // Restablecer el color al final de la línea
        //std::cout << std::endl;
    
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
        std::cout<<"\t\t\t\t\t";
        setColor(41); // Fondo rojo
        std::cout << "       ";
        resetColor();
        imprimirColoreado(texto, i);
		//std::cout << texto[i]; // Parte roja de la bandera
        setColor(41); // Fondo rojo
        std::cout << "       "; // Parte roja de la bandera
        resetColor();
        std::cout << std::endl;
    }
    //std::cout<<"\t\t\t\t\t----------------------------------------------------------------------------"<<std::endl;*/
}


