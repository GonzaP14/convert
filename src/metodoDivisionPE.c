#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metodosAuxiliares.h"

char * parteEntera10aDestino (long long * numero, short * baseDestino, short * mostrar){
    long long * numeroAux;
    long long * auxiliar;
    short * contador;
    char* resultado;

    contador = (short *) malloc (sizeof(short));
    resultado = (char *) malloc (45 * sizeof(char));
    auxiliar = (long long *) malloc (sizeof (long long));

    *auxiliar = *numero;
    numeroAux = numero;
    *contador = 0;

    while (*numeroAux > 0) {

        if (*mostrar == 1){
            printf("X%hd = %I64d mod %hd", *contador , *numeroAux , *baseDestino);
        }

        *resultado = (*numeroAux % *baseDestino);

        if (*resultado >= 10 && *baseDestino > 10){
            convertirNumeroALetra (resultado);
        }
        else {
            *resultado = *resultado + '0';
        }

        if (*mostrar == 1){
            printf (" = %c y Q%hd = (%I64d - %c) / %hd ", *resultado , *contador , *numeroAux , *resultado , *baseDestino);
        }

        *numeroAux /= *baseDestino;

        if (*mostrar == 1){
            printf ("= %I64d \n" , *numeroAux);
        }

        resultado ++;
        *contador += 1;
    }

    if (*contador == 0 && *mostrar == 1) {
        *resultado = '0';
        printf("X%hd = %I64d mod %hd ", *contador , *numeroAux , *baseDestino);
        resultado ++;
        *contador += 1;
        printf ("= (%I64d) %hd \n" , *numeroAux, *baseDestino);
    }

    *resultado = '\0';
    resultado -= *contador ;
    strrev (resultado);

    if (*mostrar == 1) {
        printf ("Luego, (%I64d) 10 = (%s) %hi \n", *auxiliar, resultado, *baseDestino);
    }

    free (auxiliar);
    free (contador);

    return resultado;
}
