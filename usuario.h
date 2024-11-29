#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <vector>
using namespace std;

class Usuario {
private:
    int dni;
    string nombre;
    string email;
    vector <string> librosPedidos;

public:
    Usuario(int dni, string nombre, string email);
    
    int dni();
    string nombre();
    string email();

    void pedirLibro(string idLibro);
    bool tieneLibroPendiente(string idLibro);
    void entregarLibro(string idLibro);
    int LibrosPedidos();
};

#endif
