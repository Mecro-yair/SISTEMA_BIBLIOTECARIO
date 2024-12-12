#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "libros.h"
#include "usuario.h"
#include "prestamos.h"
#include <vector>
#include <string>
#include <fstream>

class Biblioteca {
private:
    vector<Libro> libros;
    vector<Usuario> usuarios;
    vector<Prestamos> prestamos;

public:
    Biblioteca();
    void quitarLibro(int id);
    void agregarLibro(int id,string titulo, string autor, int anio, int cantidad);//
    void agregarUsuario(string dni, string nombre, string email, int edad, char sexo);
	void agregarPrestamo(string  dniUsu,int idLibro,string FE, string FD);//
    bool pedirLibro(string idLibro, string dniUsuario);
    void entregarLibro(int libroId, int usuarioId);
    void mostrarPrestamos();
    void mostrarUsuarios();
    void mostrarLibros();
	void guardarLibrosEnArchivo(Libro& libroNuevo);
    void guardarUsuariosEnArchivo(string dni, string nombre, string email, int edad, char sexo);
    void guardarPrestamosEnArchivo(string  dniUsu,int idLibro,string FE, string FD);
    void cargarLibros();
    void cargarUsuarios();
    void cargarPrestamos();
    vector<Usuario> getUsuarios();
    vector<Prestamos> getPrestamos();
    vector<Libro> getLibros();
    void guardarLibrosEnArchivo();
    //void cargarPedidos();

};

#endif
