#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ESLETRA(x) (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') ? 0 : 1
#define AMAYU(x) (x >= 'a' && x <= 'z') ? (x - 32) : x
#define AMINU(x) (x >= 'A' && x <= 'Z') ? (x + 32) : x


void decodificar_fecha(int* periodo);
void ConvertirFecha(int* periodo, char* cadena);
void Normalizar (char* descripcion);


#endif // HEADER_H_INCLUDED
