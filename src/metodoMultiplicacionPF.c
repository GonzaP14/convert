#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "metodosAuxiliares.h"

char * parteFraccionaria10ADestino (double * numero, short * baseDestino, short * precision, short * mostrar) {
    char * resultado;
    double * numeroAux;
    double * resultadoActual;
    short * digitoActual;
    short * contador;

    resultado = (char *) malloc ((*precision + 1) * sizeof (char));
    numeroAux = (double *) malloc (sizeof (double));
    resultadoActual = (double *) malloc (sizeof (double));
    digitoActual = (short *) malloc (sizeof (short));
    contador = (short *) malloc (sizeof (short));

    * numeroAux = * numero;
    * contador = 0;

    while ((*contador) != (*precision)) {
        * resultadoActual = (* numeroAux) * (* baseDestino);
        * digitoActual = floor (*resultadoActual);

        if ((* mostrar == 1)) {
            printf ("(%lf) 10 * ", *numeroAux);
        }

        * numeroAux = * resultadoActual - * digitoActual;

        if (*digitoActual < 10) {
            *resultado = *digitoActual + '0';
        }
        else {
            *resultado = *digitoActual;
            convertirNumeroALetra (resultado);
        }

        if ((* mostrar == 1)) {
            printf ("(%i) 10 = (%lf) 10, por lo que X(%i) = Piso (%lf) = (%c) %i \n", *baseDestino, *resultadoActual, - (*contador + 1), *resultadoActual , *resultado, *baseDestino);
        }

        resultado ++;
        *contador = *contador + 1;
    }

    *resultado = '\0';
    resultado = resultado - *contador;

    if (*mostrar == 1) {
        printf ("Luego, (%lf) 10 = (0.%s) %hi \n", *numero, resultado, *baseDestino);
    }

    free (resultadoActual);
    free (digitoActual);
    free (contador);
    free (numeroAux);

    return resultado;
}
