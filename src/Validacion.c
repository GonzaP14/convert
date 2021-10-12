#include <stdio.h>
#include <stdlib.h>

void verificarNumeroBase2a10 (char * numero, short * baseOrigen, short * resultado) {
    while ((*numero) != '\0') {
        if (! (((*numero) >= '0') && (*numero) < ('0' + *baseOrigen)) ) {
            * resultado = 0;
            break;
        }

        numero ++;
    }
}

void verificarNumeroBase11a16 (char * numero, short * baseOrigen, short * resultado) {
    short * checkNumeros;
    short * checkLetras;
    checkLetras = (short *)malloc(sizeof(short));
    checkNumeros = (short *)malloc(sizeof(short));

    while ((*numero) != '\0') {
        *checkNumeros = ( (*numero) >= '0' && (*numero) < ('0' + *baseOrigen) );
        *checkLetras = ( (* numero) >= 'A' && (*numero) < ('A' + *baseOrigen - 10) ) || ( (* numero) >= 'a' && (*numero) < ('a' + *baseOrigen - 10) );

        if (!(*checkNumeros || *checkLetras)) {
            * resultado = 0;
            break;
        }

        numero ++;
    }

    free (checkLetras);
    free (checkNumeros);
}

short * verificarNumero (char * numero, short * baseOrigen) {
    short * resultado;
    char * numeroAux;
    resultado = (short *) malloc (sizeof (short));
    * resultado = 1;
    numeroAux = numero;

    if ((* baseOrigen) > 16 ) {
        * resultado = 0;
    } else if ((* baseOrigen) <= 10) {
        verificarNumeroBase2a10 (numeroAux, baseOrigen, resultado);
    } else {
        verificarNumeroBase11a16 (numeroAux, baseOrigen, resultado);
    }

    return resultado;
}
