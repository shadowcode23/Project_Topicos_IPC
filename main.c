#include "header.h"

int main()
{
    char cad[30] = {};
    char test[] = {"¡¡hola pedAZo De CHAD!!"};
    int num = 201612;
    int* periodo = &num;

    ConvertirFecha(periodo,cad);
    printf("\n%s\n", cad);

    Normalizar(test);
    printf("\n%s\n", test);

    printf("¡¡");



    return 0;
}
