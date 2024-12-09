#ifndef LIBRO_H
#define LIBRO_H

#include <string>
using namespace std;

//int cantLibrosTotal = 0;
class Libro {
private:
    int id;
    string titulo;
    string autor;
    int anio;
    int cantidad;
    bool entregado;

public:
	Libro() : id(-1), titulo("") {}
    Libro(int id, string titulo, string autor, int anio, int cantidad);
    
	int llamarId();
    string llamarTitulo();
    string llamarAutor();
    int llamarAnio();
    int llamarCantidad();
    bool llamarEntregado();
};


#endif