#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ESLETRA(x) (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') ? 0 : 1
#define AMAYU(x) (x >= 'a' && x <= 'z') ? (x - 32) : x
#define AMINU(x) (x >= 'A' && x <= 'Z') ? (x + 32) : x

typedef struct
{
    char codigo[21];
    char descripcion[31];
    char clasificador[31];
    double indice;
    double var;
    char region[10];
    int periodo;
}IPC;

void decodificar_fecha(int* periodo);
void ConvertirFecha(int* periodo, char* cadena);
void Normalizar (char* descripcion);
void PuntoAComa(const double indice, char* cadena);

#endif // HEADER_H_INCLUDED
