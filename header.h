#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ESLETRA(x) (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') ? 0 : 1
#define AMAYU(x) (x >= 'a' && x <= 'z') ? (x - 32) : x
#define AMINU(x) (x >= 'A' && x <= 'Z') ? (x + 32) : x
#define TAMGRUPO 25
#define TAMREGION 9
#define TAMDESC 31
#define TAMCOD 21
#define TAMCLAS 30
#define ERROR -1
#define TODO_OK 0

typedef struct
{
    char codigo[TAMCOD];
    char descripcion[TAMDESC];
    char clasificador[TAMDESC];
    double indice;
    double var;
    char region[TAMREGION];
    int periodo;
}IPC;

typedef struct
{
    float monto;
    char region[TAMREGION];
    int fecha_desde;
    int fecha_hasta;

}datos;

typedef struct
{
    char descripcion[TAMDESC];
    int periodo;
    double indice_IPC;
    char region[TAMREGION];
    char grupo[TAMGRUPO];
}analisis;

typedef struct
{
    char codigo[TAMCOD];
    char desc_aperturas[TAMDESC];
    char clasificador[TAMCLAS];
    int periodo;
    double indice;
    double var_mensual;
    double var_interanual;
    char region[TAMREGION];
}aperturas;



void insertar_ordenado(IPC* registro, analisis* vector, unsigned* ce);
void decodificar_fecha(int* periodo);
void ConvertirFecha(int* periodo, char* cadena);
void Normalizar (char* descripcion);
void PuntoAComa(const double indice, char* cadena);
void SolicitarDatos(datos* datos, IPC* ipc,double* monto_ajustado, double* var_porcentual, unsigned ce);
int IngresarFecha();
void* buscar_generico(void* registros,  unsigned ce, size_t tam, void* elemento, int cmp(void*, void*));
void desplazar(void* insertar, void* fin, size_t tam);
int compara(void* a, void* b);


#endif // HEADER_H_INCLUDED
