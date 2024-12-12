#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <vector>
#include "persona.h"


using namespace std;
class Prestamos;
class Usuario: public Persona {
	private:
    	//std::vector <Prestamos*> prestamos;

	public:
		Usuario(){
			
		}
    	Usuario(std::string ,std::string ,std::string ,int ,char);	
    	std::vector<Prestamos*> getPrestamos();
    	void mostrarDatos();
};


#endif
