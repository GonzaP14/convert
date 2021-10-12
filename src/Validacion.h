#ifndef VALIDACION_H_INCLUDED
#define VALIDACION_H_INCLUDED

/**
@file Validacion.h
@version 1.0
@date 09/10/2021
@author: Gonzalo Martin Perez y Nicolas Messina.
*/

/**
Verifica la validez de un numero en su correspondiente base de origen.

@param numero: Numero a verificar.
@param baseOrigen: Base origen del numero.

@return: Puntero a short asociado al resultado de la verificacion del numero.
*/
short * verificarNumero (char * numero, short * baseOrigen);

#endif // VALIDACION_H_INCLUDED
