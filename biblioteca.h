#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "libros.h"
#include "usuario.h"
#include <vector>
#include <string>
#include <fstream>

class Biblioteca {
private:
    vector<Libro> libros;
    vector<Usuario> usuarios;

public:
    Biblioteca();
    void agregarLibro(int id,string titulo, string autor, int anio, int cantidad);//
    void agregarUsuario(string dni, string nombre, string email, int edad, char sexo);//
    bool pedirLibro(string idLibro, string dniUsuario);
    void entregarLibro(int libroId, int usuarioId);
    void mostrarPrestamos();
    void guardarLibrosEnArchivo();
    void guardarUsuariosEnArchivo();
    void guardarPedidosEnArchivo();
    void cargarLibros();
    void cargarUsuarios();
    //void cargarPedidos();

};

#endif
