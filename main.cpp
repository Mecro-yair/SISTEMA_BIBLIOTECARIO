#include <iostream>
#include <windows.h>
#include "libros.h"
using namespace std;

int main() {
	SetConsoleOutputCP(CP_UTF8);
    string nombre, email,dniUser;
    cout << "Ingrese su DNI: "; 
	cin >> dniUser;

    if(dniUser.size() != 8){
    	cout << "\nError. No es el tamaño de un DNI.";
    	return 0;
	}
	for (char c : dniUser) {
    if (!isdigit(c)) {
        cout << "\nError: El DNI solo puede contener números.\n";
        return 0;
        }
    }

	cout << "Ingrese su nombre y apellido: "; cin.ignore(); getline(cin, nombre);
	cout << "Ingrese su email: "; getline(cin, email);	
	cout << "\nInformacion agregada correctamente.\n\n";
	cout << "Presione enter para continuar con el menú.";
	cin.get();
	system("cls");

    int opcion;
    do {
        cout << "--- Menu ---\n" << endl;
        cout << "1. Añadir libro" << endl;
        cout << "6. Mostrar inventario de libros"<<endl;
        cout << "2. Pedir libro" << endl;
        cout << "3. Entregar libro" << endl;
        cout << "4. Mostrar libros pendientes de entrega" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opción: "; cin >> opcion;

        switch(opcion) {
            case 1: {
            	system("cls");
            	cout << "AÑADIR UN NUEVO LIBRO\n\n";
                agregarLibro();
                break;
            }
            case 2: {
 				system("cls");
 				cout << "PEDIDO DE LIBRO\n\n";
                int libroId;
                cout << "ID del libro a pedir: "; cin >> libroId;
                break;
            }
            case 3: {
 				system("cls");
 				cout << "ENTREGA DE LIBRO\n\n";
                int libroId;
                cout << "ID del libro a entregar: "; cin >> libroId;
                break;
            }
            case 4:
 				system("cls");
                break;
            case 5:
 				system("cls");
                cout << "Se retiró exitosamente." << endl;
                break;
            case 6:
            	mostrarLibros();
            default:
 				system("cls");
                cout << "Opción inválida." << endl;
        }
    } while(opcion != 5);

    return 0;
}
