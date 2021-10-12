#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Conversor.h"

void validarNumero (char * numero, short * check) {
    if ((*numero >= '0' && *numero <= '9') || (*numero >= 'A' && *numero <= 'Z') || (*numero >= 'a' && *numero <= 'z')) {
        *check = 1;
    }

}

void validarBase (char * base, short * check) {
    short * contador;
    short * baseAuxiliar;

    contador = (short *) malloc (sizeof (short));
    baseAuxiliar = (short *) malloc (sizeof (short));

    *contador = 0;
    *check = 1;

    while (base [*contador] != '\0'){
        if (base [*contador] >= '0' && base [*contador] <= '9'){
            *contador += 1;
        }
        else {
            * check = 0;
            break;
        }
    }

    if (*check == 1) {
        *baseAuxiliar = atoi (base);
        *check = ((*baseAuxiliar) >= 2 && (*baseAuxiliar) <= 16) ? 1 : 0;
    }

    free (contador);
    free (baseAuxiliar);
}

void mostrarEntrada (char * numero , short * baseOrigen , short * baseDestino , short * verbose , short * help) {
    printf("La entrada es: \n");
    printf("Numero = %s \n", numero);
    printf("Base Origen = %hd \n", *baseOrigen);
    printf("Base Destino = %hd \n", *baseDestino);
    printf("Modo Verbose = ");

    if (*verbose == 1) {
        printf ("Encendido \n");
    }
    else {
        printf("Apagado \n");
    }

    printf("Help = ");

    if (*help == 1) {
        printf("Encendido \n");
    }
    else {
        printf("Apagado \n");
    }

    printf ("\n");
}

void mostrarHelp(){
    printf("MENU DE AYUDA:\n\n");
    printf ("El programa recibe las siguientes entradas. (No importa su orden) \n\n");

    printf("-n      Indica que la siguiente entrada es el numero a convertir. <number> es el numero que le sigue a -n. \n");
    printf("        Asegurese de lo siguiente sobre <number>: \n");
    printf("        * Que el numero sea valido en su base de origen.\n");
    printf("        * Que la parte entera no posea mas de 10 digitos.\n");
    printf("        * Que la parte fraccionaria no posea mas de 5 digitos.\n");
    printf("        Es obligatorio para el correcto funcionamiento. \n\n");

    printf("-s      Indica que la siguiente entrada es la base origen del numero ingresado. \n");
    printf("        Las bases validas se comprenden entre el siguiente rango: [2 ... 16] \n");
    printf("        Si utiliza '-s', debe ingresar una base correcta, <number> en el siguiente argumento. \n");
    printf("        Si no lo utiliza, el programa utiliza de forma predeterminada base 10. \n\n");

    printf("-d      Indica que la siguiente entrada es la base destino del numero ingresado. \n");
    printf("        Las bases validas se comprenden entre el siguiente rango: [2 ... 16] \n");
    printf("        Si utiliza '-d', debe ingresar una base correcta, <number> en el siguiente argumento. \n");
    printf("        Si no lo utiliza, el programa utiliza de forma predeterminada base 10. \n\n");

    printf("-v      Indica al programa que se debe ejecutar en modo 'verbose', mostrando los calculos intermedios del proceso de conversion. \n\n");

    printf("-h      Indica al programa que se debe mostrar el menu de ayuda. \n\n");

    printf ("\n");
    printf("-> Para informacion adicional acerca del funcionamiento del programa, consultar el informe especifico. \n\n");
}

void procesarEntrada (char * numero , short * baseOrigen , short * baseDestino , short * verbose , short * help, short * procesoCompleto) {
    char * resultado;

    mostrarEntrada (numero, baseOrigen, baseDestino, verbose, help);

    if (numero == NULL) {
        if (*help == 1) mostrarHelp ();
        printf ("No se ingreso un numero. \n\n");
    }
    else {
        if (*help == 1) mostrarHelp ();
        resultado = convertir (numero, baseOrigen, baseDestino, verbose, procesoCompleto);

        if (*procesoCompleto == 1) {
            printf ("El numero %s en base %hd es igual a %s en base %hd. \n\n", numero, *baseOrigen, resultado, *baseDestino);
            free (resultado);
        }
    }
}

int main (int argc, char ** argv) {
    char * numero;
    short * baseOrigen;
    short * baseDestino;
    short * verbose;
    short * help;
    short * contador;
    short * check;
    short * procesoCompleto;

    baseOrigen = (short *) malloc (sizeof (short));
    baseDestino = (short *) malloc (sizeof (short));
    verbose = (short *) malloc (sizeof (short));
    help = (short *) malloc (sizeof (short));
    contador = (short *) malloc (sizeof (short));
    check = (short *) malloc (sizeof (short));
    procesoCompleto = (short *) malloc (sizeof (short));

    numero = NULL;

    *baseOrigen = 10;
    *baseDestino = 10;
    *verbose = 0;
    *help = 0;
    *contador = 1;
    *check = 0;
    *procesoCompleto = 1;

    printf ("\n");
    printf ("Nombre del programa = %s", argv [0]);
    printf ("\n\n");

    if (argc >= 2 && argc <= 9) {

        while (*contador < argc) {

            if (strcmp (argv [*contador], "-n" ) == 0) {

                if (*contador + 1 >= argc) {
                    *procesoCompleto = 0;
                    printf ("No se ingresaron mas argumentos luego de '%s'. \n", argv [*contador]);
                    break;
                }

                *contador += 1;
                validarNumero (argv [*contador], check);

                if (*check == 0) {
                    *procesoCompleto = 0;
                    break;
                }

                numero = argv [*contador];

            }

            else if (strcmp (argv [*contador], "-s") == 0) {

                if (*contador + 1 >= argc) {
                    *procesoCompleto = 0;
                    printf ("No se ingresaron mas argumentos luego de '%s'. \n", argv [*contador]);
                    break;
                }

                *contador += 1;
                validarBase (argv [*contador], check);

                if (*check == 0) {
                    *procesoCompleto = 0;
                    printf ("La base origen '%s' ingresada no es valida. \n", argv [*contador]);
                    break;
                }

                *baseOrigen = atoi (argv [*contador]);
            }

            else if (strcmp (argv [*contador], "-d") == 0) {

                if (*contador + 1 >= argc) {
                    *procesoCompleto = 0;
                    printf ("No se ingresaron mas argumentos luego de '%s'. \n", argv [*contador]);
                    break;
                }

                *contador += 1;
                validarBase (argv [*contador], check);

                if (*check == 0) {
                    printf ("La base destino '%s' ingresada no es valida. \n", argv [*contador]);
                    *procesoCompleto = 0;
                    break;
                }

                *baseDestino = atoi (argv [*contador]);
            }

            else if (strcmp (argv [*contador], "-v") == 0 ) {
                *verbose = 1;
            }

            else if (strcmp (argv [*contador], "-h") == 0 ) {
                *help = 1;
            }

            else {
                *procesoCompleto = 0;
                break;
            }

            *check = 0;
            *contador += 1;
        }

        if (*procesoCompleto == 0) {
            printf ("-> Alguna de las entradas no verifica las condiciones necesarias. \n\n");
        } else {
             procesarEntrada (numero, baseOrigen, baseDestino, verbose, help, procesoCompleto);
        }

    }

    else {
        * procesoCompleto = 0;
        printf ("-> La cantidad de argumentos ingresada es incorrecta. \n");
    }

    free (baseOrigen);
    free (baseDestino);
    free (verbose);
    free (help);

    *contador = 0;

    while (*contador < argc) {
        free (argv [*contador]);
        *contador += 1;
    }

    free (contador);
    free (argv);

    if (*procesoCompleto == 1) {
        free (procesoCompleto);
        printf ("-> El programa fue ejecutado exitosamente. \n");
        exit (EXIT_SUCCESS);
    }
    else {
        free (procesoCompleto);
        printf ("-> El programa no fue ejecutado exitosamente. \n");
        exit (EXIT_FAILURE);
    }
}
