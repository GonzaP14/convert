#ifndef METODODIVISION_H_INCLUDED
#define METODODIVISION_H_INCLUDED

/**
@file metodoDivision.h
@version 1.0
@date 09/10/2021
@author: Gonzalo Martin Perez y Nicolas Messina.
*/

/**
Convierte la parte entera del numero de la base 10 a la base destino.

@param: numero Numero al cual vamos a convertir de base 10 a base Destino.
@param: baseDestino Base a la que queremos llevar el numero.
@param: mostrar Es utilizado para saber si debemos hacer el verbose o no en el metodo.
@return: Puntero a char asociado al numero en base destino luego de la conversion.
*/
char * parteEntera10aDestino (long long* numero , short * baseDestino , short * mostrar);

#endif // METODODIVISION_H_INCLUDED
