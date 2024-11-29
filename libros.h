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
    bool disponible;

public:
    Libro(int id, string titulo,string autor, int anio, int cantidad);
    
	//void agregarLibro();
	void quitarLibro();
	//aqui añadiremos las funciones en prototipo que necesitemos
};

void agregarLibro();
void mostrarLibros();
#endif