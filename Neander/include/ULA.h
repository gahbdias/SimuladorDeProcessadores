/**
 * @file ULA.h
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador de modelos Parte de Controle (PC) - Parte Operativa (PO)
 * @version 1.00
 * @date 06-04-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _ULA_H_
#define _ULA_H_
#include <iostream>

class ULA { // Unidade Lógica-Aritmética

    public:
        ULA ( );
        ~ULA(void) = default;            

        double executarOperacao( double a, double b, int operacao ); // executa operações binárias
        int executarOperacao( int a ); // para operações unárias

};


#endif