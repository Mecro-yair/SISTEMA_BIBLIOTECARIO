#ifndef EXTRAS_H
#define EXTRAS_H

void imprimirColoreado(const char* texto[], int i);
void imprimirLogo();
void resetColor();
void setColor(int code);
std::string obtenerFechaHoraActual();
std::string obtenerFechaDevolucion(int dias_sumar);
#endif