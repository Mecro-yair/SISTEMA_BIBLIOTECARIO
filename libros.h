#ifndef LIBRO_H
#define LIBRO_H

#include <string>
using namespace std;

class Libro {
private:
    int id;
    string titulo;
    string autor;
    int anio;
    int cantidad;
    bool entregado;

public:
    Libro(int id, string titulo,string autor, int anio, int cantidad);
    
	//aqui añadiremos las funciones en prototipo que necesitemos
};

#endif