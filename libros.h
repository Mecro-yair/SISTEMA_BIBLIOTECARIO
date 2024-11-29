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
    Libro(int id, string titulo,string autor, int anio, int cantidad);
    
	int llamarId();
    string llamarTitulo();
    string llamarAutor();
    int llamarAnio() ;
    int llamarCantidad();
    bool esEntregado();
    void actualizaEntregado(bool valor);
    void reducirCantidad();
    
};


#endif