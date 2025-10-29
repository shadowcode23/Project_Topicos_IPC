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

void SolicitarDatos(datos* datos, IPC* ipc, double* monto_ajustado, double* var_porcentual,unsigned ce)
{
    const char* region[7] = {"Nacional", "GBA", "Pampeana", "Cuyo", "Noroeste", "Noreste", "Patagonia"};
    int nro;
    double i_desde = -1;
    double i_hasta = -1;

    do
    {
        printf("\nIngresar monto expresado en pesos: ");
        scanf("%1f", &datos->monto);

    }
    while(datos->monto < 0);

    printf("\n1-Nacional\n2-GBA\n3-Pampeana\n4-Cuyo\n5-Noroeste\n6-Noreste\n7-Patagonia");
    printf("\nIngresar numero segun region que quiera solicitar: ");
    scanf("%d", &nro);
    strcpy(datos->region, region[nro-1]);


    printf("\nIngresar fecha (desde): ");
    datos->fecha_desde = IngresarFecha();

    printf("\nIngresar fecha (hasta): ");
    datos->fecha_hasta = IngresarFecha();


    while(ce--)
    {
        if(strcmp("NIVEL GENERAL", ipc->descripcion) == 0 && strcmp(datos->region,ipc->region) == 0)
        {
            if(datos->fecha_desde == ipc->periodo)
            {
                i_desde = ipc->indice;

            }
            else if(datos->fecha_hasta == ipc->periodo)
            {
                i_hasta = ipc->indice;

            }

        }

        ipc ++;

        if(i_desde != -1 && i_hasta != -1)
        {
            *monto_ajustado = datos->monto * (i_hasta / i_desde);
            *var_porcentual = (i_hasta / i_desde -1)*100;
        }

    }
}

int IngresarFecha()
{
    int mes;
    int anio;
    do
    {
        printf("Ingrese Mes (del 1 al 12): ");
        scanf("%d", &mes);
    }
    while(mes<1 || mes>12);

    printf("Ingrese año: ");
    scanf("%d", &anio);

    mes += (anio*100);

    return mes;
}

void Analisis_evo(IPC* ipc, analisis* vec, unsigned ce)
{
    char* bienes [5] = {"Alimentos y bebidas no alcohólicas" , "Bebidas alcohólicas y tabaco" , "Prendas de vestir y calzado",
                        "Bienes y servicios varios", "Equipamiento y mantenimiento del hogar"};

    char* servicios [10] = {"Recreación y cultura" , "Restaurantes y hoteles" , "Salud",
                            "Transporte", "Educación", "Comunicación", "Vivienda", "agua",
                            "electricidad", "gas y otros combustibles"};

    if(ce == 0) //como genere un vector desde el main vacio, no tiene elementos y va a llenarse aca el primer elemento.
    {
        strcpy(vec->region, ipc->region);
        vec->periodo = ipc->periodo;
        strcpy(vec->descripcion, ipc->descripcion);
        vec->indice_IPC = ipc->indice;
        *(ce)++;
    }

    while(ce--)
    {
        if(vec->periodo == ipc->periodo)
        {
            if(strcmp(vec->region, ipc->region) == 0)
        }
    }

}
