#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <vector>
using namespace std;

class Usuario {
	private:
    	string dni;
    	string nombre;
    	string email;
    	vector <string> librosPedidos;

	public:
    	Usuario(string dni, string nombre, string email);
    
    	string DNI();
    	string Nombre();
    	string Email();

    	void pedirLibro(string idLibro);
    	bool tieneLibroPendiente(string idLibro);
    	void entregarLibro(string idLibro);
    	vector<string> LibrosPedidos();
};

#endif
