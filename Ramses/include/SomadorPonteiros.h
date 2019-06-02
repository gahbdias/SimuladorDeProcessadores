/**
 * @file SomadorPonteiros.h
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador do Neander
 * @version 1.00
 * @date Jun-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _SomadorPonteiros_H_
#define _SomadorPonteiros_H_

#include <iostream>

class SomadorPonteiros { // Somador de Ponteiros - para o modo indexado

    public:
        SomadorPonteiros () {}

        ~SomadorPonteiros( void ) = default;            

        int somarIndice( int x, int rdm ){ 
            // Soma o indice de RX ao dado de RDM (que será um endereço) e coloca o resultado em REM ou PC
            return rdm + x;
        } 

};

#endif
