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
