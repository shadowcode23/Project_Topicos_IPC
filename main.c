#include "header.h"

int main()
{
    char cad[30] = {};
    int num = 201612;
    int* periodo = &num;
    ConvertirFecha(periodo,cad);
    printf("\n%s\n", cad);


    char test[] = {"hola pedAZo De CHAD"};
    Normalizar(test);
    printf("\n%s\n", test);


    char cadenaConversion[17] = {};
    double indice = 123.567;
    PuntoAComa(indice,cadenaConversion);
    printf("\n\nPunto a Coma: %s\n\n", cadenaConversion);

    SolicitarDatos();

    return 0;
}
