/**
 * @file Ula.h
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador do Neander
 * @version 1.00
 * @date Jun-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _ULA_H_
#define _ULA_H_
#include <iostream>
#include "RI.h"

#ifndef LIXO
#define LIXO 666

class ULA { // Unidade Lógica-Aritmética

    public:
        Ula ( );
        ~Ula(void) = default;            

        double executarOperacao( double a, double b, int operacao ); // executa operações binárias
        int executarOperacao( int a ); // para operações unárias

};

#endif
#endif