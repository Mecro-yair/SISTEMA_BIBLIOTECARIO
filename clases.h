#ifndef CLASES_H
#define CLASES_H


#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Para std::find

using namespace std;

// Clase base Persona
class Persona {
protected:
    string nombre;
    string apellidoPat;
    string apellidoMat;
    string dni;
    string id;
    string edad;
    string email;
    string sexo;
    string telefono;

public:
    Persona(string n, string ap, string am, string d, string cod, string ed, string em, string se, string te)
        : nombre(n), apellidoPat(ap), apellidoMat(am), dni(d), id(cod), edad(ed), email(em), sexo(se), telefono(te) {}

    string getNombre() const { return nombre; }
    string getId() const { return id; }

    virtual void mostrarInfo() const {
        cout << "ID: " << id << ", Nombre: " << nombre << " " << apellidoPat << " " << apellidoMat << endl;
    }

    virtual ~Persona() {}
};

// Clase Usuario (hereda de Persona)
class Usuario : public Persona {
public:
    Usuario(string n, string ap, string am, string d, string cod, string ed, string em, string se, string te)
        : Persona(n, ap, am, d, cod, ed, em, se, te) {}

    void mostrarInfo() const override {
        cout << "[Usuario] ";
        Persona::mostrarInfo();
    }
};

// Clase Administrador (hereda de Persona)
class Administrador : public Persona {
private:
    string contrasenia;

public:
    Administrador(string n, string ap, string am, string d, string cod, string ed, string em, string se, string te, string con)
        : Persona(n, ap, am, d, cod, ed, em, se, te), contrasenia(con) {}

    void mostrarInfo() const override {
        cout << "[Administrador] ";
        Persona::mostrarInfo();
    }
};

// Clase Libro
class Libro {
private:
    string titulo;
    string autor;
    int anio;
    int paginas;
    int id;
    int cantidad;
    int disponibles;

public:
    Libro(string t, string a, int y, int p, int i, int c)
        : titulo(t), autor(a), anio(y), paginas(p), id(i), cantidad(c), disponibles(c) {}

    string getTitulo() const { return titulo; }
    int getDisponibles() const { return disponibles; }
    bool estaDisponible() const { return disponibles > 0; }
    void prestar() { if (disponibles > 0) disponibles--; }
    void devolver() { if (disponibles < cantidad) disponibles++; }

    void mostrarInfo() const {
        cout << "Título: " << titulo << ", Autor: " << autor << ", Año: " << anio
             << ", Páginas: " << paginas << ", ID: " << id
             << ", Disponibles: " << disponibles << endl;
    }
};

// Clase Prestamo
class Prestamo {
private:
    Usuario usuario;
    Libro& libro;

public:
    Prestamo(const Usuario& u, Libro& l) : usuario(u), libro(l) {}

    void mostrarInfo() const {
        cout << "Préstamo - Usuario: " << usuario.getNombre()
             << ", Libro: " << libro.getTitulo() << endl;
    }
};

// Clase Biblioteca
class Biblioteca {
private:
    vector<Usuario> usuarios;
    vector<Administrador> admins;
    vector<Libro> libros;
    vector<Prestamo> prestamos;

public:
    void registrarUsuario(const Usuario& usuario) {
        usuarios.push_back(usuario);
    }

    void registrarAdministrador(const Administrador& admin) {
        admins.push_back(admin);
    }

    void agregarLibro(const Libro& libro) {
        libros.push_back(libro);
    }

    void mostrarUsuarios() const {
        cout << "Usuarios registrados:\n";
        for (const auto& usuario : usuarios) {
            usuario.mostrarInfo();
        }
    }

    void mostrarAdministradores() const {
        cout << "Administradores registrados:\n";
        for (const auto& admin : admins) {
            admin.mostrarInfo();
        }
    }

    void mostrarLibros() const {
        cout << "Libros en la biblioteca:\n";
        for (const auto& libro : libros) {
            libro.mostrarInfo();
        }
    }

    void realizarPrestamo(const Usuario& usuario, Libro& libro) {
        if (libro.estaDisponible()) {
            libro.prestar();
            prestamos.emplace_back(usuario, libro);
            cout << "Préstamo realizado con éxito: Usuario " << usuario.getNombre() << " -> Libro '" << libro.getTitulo() << "'.\n";
        } else {
            cout << "El libro '" << libro.getTitulo() << "' no está disponible para préstamo.\n";
        }
    }

    vector<Usuario>& getUsuarios() { return usuarios; }
    vector<Libro>& getLibros() { return libros; }
};


#endif