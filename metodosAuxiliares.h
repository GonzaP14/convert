#ifndef METODOSAUXILIARES_H_INCLUDED
#define METODOSAUXILIARES_H_INCLUDED

/**
@file metodosAuxiliares.h
@version 1.0
@date 09/10/2021
@author: Gonzalo Martin Perez y Nicolas Messina.
*/

/**
Convierte el digito (en caracter) ingresado como parametro a su correspondiente representacion numerica.

@param numero: Numero resultado de la conversion.
@param digito: Digito a convertir.
*/
void convertirLetraANumero (short * numero, char * digito);

/**
Si el numero ingresado es de base {11..16}, convierte el numero en su correspondiente letra.

@param numero: Numero a convertir.
*/
void convertirNumeroALetra (char * numero);

#endif // METODOSAUXILIARES_H_INCLUDED
