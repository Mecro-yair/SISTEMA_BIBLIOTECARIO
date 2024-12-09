#ifndef PERSONA_H
#define PERSONA_H

class Persona{
	protected:
		std::string dni;
	    std::string nombre;
	    std::string email;
	    int edad;
		char sexo;
	public:
		Persona(){
			
		}
		Persona(std::string dni,std::string nombre,std::string email,int edad,char sexo);
		std::string getDni();
		std::string getNombre();
		std::string getEmail();
		int getEdad();
		char getSexo();
		void mostrarPersona();	
    
};


#endif