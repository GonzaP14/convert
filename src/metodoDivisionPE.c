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
    //Recorro el numero y lo voy transformando a la base destino
    while (*numeroAux > 0) {

        if (*mostrar == 1){
            printf("X%hd = %I64d mod %hd", *contador , *numeroAux , *baseDestino);
        }

        *resultado = (*numeroAux % *baseDestino);
        //Si la base es mayor a 10 y el resultado mayor o igual a 10 lo convierto en la letra,de lo contrario lo convierto en su numero correspondiente
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
    // Le asigno al final del resultado el '\0'
    *resultado = '\0';
    //Vuelvo al puntero a la primer posicion de resultado
    resultado -= *contador ;
    //Doy vuelta el resultado ya que es necesario por el algoritmo aplicado
    strrev (resultado);

    if (*mostrar == 1) {
        printf ("Luego, (%I64d) 10 = (%s) %hi \n", *auxiliar, resultado, *baseDestino);
    }

    free (auxiliar);
    free (contador);

    return resultado;
}
