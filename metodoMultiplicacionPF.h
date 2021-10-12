#ifndef METODOMULTIPLICACIONPF_H_INCLUDED
#define METODOMULTIPLICACIONPF_H_INCLUDED

/**
@file metodoMultiplicacionPF.h
@version 1.0
@date 09/10/2021
@author: Gonzalo Martin Perez y Nicolas Messina.
*/

/**
Convierte la parte fraccionaria del numero a la base destino.

@param numero: Numero a convertir en base 10.
@param baseDestino: Base destino de la conversion.
@param precision: Cantidad de digitos utilizados para la parte fraccionaria.
@param mostrar: Parametro de activacion del modo verbose.

@return: Puntero a caracter asociado al resultado de la conversion.
*/
char * parteFraccionaria10ADestino (double * numero, short * baseDestino, short * precision, short * mostrar);

#endif // METODOMULTIPLICACIONPF_H_INCLUDED
