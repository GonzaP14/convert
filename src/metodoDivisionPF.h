#ifndef METODODIVISIONPF_H_INCLUDED
#define METODODIVISIONPF_H_INCLUDED
/**
@file metodoDivisionPF.h
@version 1.0
@date 09/10/2021
@author: Gonzalo Martin Perez y Nicolas Messina.
*/

/**
Convierte la parte fraccionaria del numero a la base 10.

@param parteFraccionaria: Numero al cual vamos a convertir de base origen a base 10.
@param baseOrigen: Base en la cual se nos otorga el numero.
@param mostrar: Es utilizado para saber si debemos hacer el verbose o no en el metodo.
@return: Puntero a double asociado al numero en base 10 luego de la conversion.
*/
double * parteFraccionariaOrigenA10 (char * parteFraccionaria , short * baseOrigen , short * mostrar);

#endif // METODODIVISIONPF_H_INCLUDED
