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



    //sizeof(vector)/sizeof(vector[0])

    double monto_ajustado;
    double var_porcentual;

    //SolicitarDatos();

    analisis vec_analisis[] = {};
    //Analisis_evo(*IPC ipc, vec_analisis, unsigned ce);

    char cadenaConversion2[17] = {};
    PuntoAComa(indice, cadenaConversion2);

    return 0;
}
