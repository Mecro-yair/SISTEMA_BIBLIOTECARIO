#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <vector>
#include "persona.h"
//#include "prestamos.h"

//using namespace std;
class Prestamos;
class Usuario: public Persona {
	private:
    	std::vector <Prestamos*> prestamos;

	public:
		Usuario(){
			
		}
    	Usuario(std::string ,std::string ,std::string ,int ,char)/*:Persona(_dni,_nombre,_email,_edad,_sexo)*/;
    
    	/*void pedirLibro(string idLibro);
    	void entregarLibro(string idLibro);
    	
		bool tieneLibroPendiente(string idLibro);*/
    	
    	std::vector<Prestamos*> getPrestamos();
    	void mostrarDatos();
};


#endif
