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
    void agregarLibro(int id,string titulo, string autor, int anio, int cantidad);
    void agregarUsuario(int dni, string nombre, string email);
    bool pedirLibro(string idLibro, string dniUsuario);
    void entregarLibro(int libroId, int usuarioId);
    void mostrarLibrosPedidosNoEntregados();
    void guardarLibrosEnArchivo();
    void guardarUsuariosEnArchivo();
    void guardarPedidosEnArchivo();
    void cargarLibros();
    void cargarUsuarios();
    //void cargarPedidos();

};

#endif
