#include "header.h"

void decodificar_fecha(int* periodo)
{
    int codigo[] = {4,6,8,7,1,5,5,0,3,2};
    int* pun_cod = codigo;
    int potencia = 1;
    int num_resto;
    int num = 0;
    int i = 0;
    for(i=0; i<6; i++)
    {
        num_resto = (*periodo/potencia)%10;
        num_resto = *(pun_cod+num_resto);
        num += num_resto*potencia;
        potencia *= 10;
    }
    *periodo = num;
}

void ConvertirFecha(int* periodo, char* cad)
{
    char aux[10] = {};
    char* meses[] = {"enero-", "febrero-", "marzo-", "abril-", "mayo-", "junio-", "julio-", "agosto-", "septiembre-", "octubre-", "noviembre-", "diciembre-"};
    int mes = (*periodo % 100);
    int anio = (*periodo / 100);
    sprintf(aux, "%d", anio);
    strcpy(cad, meses[mes-1]);
    strcat(cad, aux);
}

void Normalizar (char* descripcion)
{
    int i;

    while(*descripcion)
    {
        i=ESLETRA(*descripcion);

        if(i == 0)
        {
            *descripcion = AMAYU(*descripcion);
            descripcion ++;

            while(*descripcion)
            {
                    *descripcion = AMINU(*descripcion);

                descripcion ++;
            }

        }
        else
            descripcion ++;
    }
}

void PuntoAComa(const double indice, char* cadena)
{
    sprintf(cadena, "%f", indice);
    char *punto = strchr(cadena, '.');

    if(punto!=NULL)
    {
        *punto = ',';
    }

}

void SolicitarDatos()
{
    float monto;
    int dato;

    printf("\nIngresar monto expresado en pesos: ");
    do
    {
        scanf("%f", &monto);
        printf("\nIngresar monto expresado en pesos: ");
    }while(monto<0);

    printf("\n1-Nacional\n2-GBA\n3-Pampeana\n4-Cuyo\n5-Noroeste\n6-Noreste\n7-Patagonia");
    do
    {
        printf("\nIngresar numero segun region que quiera solicitar: ");
        scanf("%d", &dato);

    }while(dato<1 || dato>7);

    printf("\nIngresar fecha (desde): ");
    printf("\nIngresar fecha (hasta): ");






}
