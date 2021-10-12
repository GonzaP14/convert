#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertirLetraANumero (short * numero, char * digito) {
    if (*digito >= '0' && *digito <= '9'){
        *numero = *digito - '0';
    }
    else if (*digito >= 'A' && *digito <= 'F'){
        *numero = *digito - 55;
    }
    else if (*digito >= 'a' && *digito <= 'f'){
        *numero = *digito - 87;
    }
}

void convertirNumeroALetra (char * numero){
    char * resultado;

    resultado = numero;

    if(*resultado >= 10 && *resultado < 16){
        *resultado = 'A' + (*resultado - 10);
    }
}
