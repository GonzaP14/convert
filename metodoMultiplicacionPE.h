#ifndef METODOMULTIPLICACION_H_INCLUDED
#define METODOMULTIPLICACION_H_INCLUDED

/**
@file metodoMultiplicacionPE.h
@version 1.0
@date 09/10/2021
@author: Gonzalo Martin Perez y Nicolas Messina.
*/

/**
Convierte la parte entera del numero de la base origen a la base 10.

@param numero: Numero a convertir.
@param baseOrigen: Base origen del numero.
@param mostrar: Parametro de activacion del modo Verbose.

@return: Puntero a long asociado al resultado de la conversion.
*/
long long* parteEnteraOrigenA10 (char * numero , short * baseOrigen, short * mostrar);

#endif // METODOMULTIPLICACION_H_INCLUDED
