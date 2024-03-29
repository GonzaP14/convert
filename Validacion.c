#include <stdio.h>
#include <stdlib.h>

void verificarNumeroBase2a10 (char * numero, short * baseOrigen, short * resultado) {
    //Hasta que el numero sea '\0' valido si el numero pertenece a la base de origen
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
    //Hasta que el numero sea '\0' valido si el numero pertenece a la base de origen
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
    //Llamo a los metodos necesarios dependiendo si la base se encuentra entre 2 y 10 o si es mayor o igual a 11.
    if ((*baseOrigen) > 16 ) {
        * resultado = 0;
    }
    else if ((*baseOrigen) <= 10 && (*baseOrigen) >= 2) {
        verificarNumeroBase2a10 (numeroAux, baseOrigen, resultado);
    }
    else if ((*baseOrigen) >= 11) {
        verificarNumeroBase11a16 (numeroAux, baseOrigen, resultado);
    }

    return resultado;
}
