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
#include "RegInstrucao.h"

/*#ifndef LIXO
#define LIXO 666*/

class Ula { // Unidade Lógica-Aritmética

	public:
		bool Z; // Indica se o resultado da ULA é zero
		bool N;	// Indica se o resultado da ULA é negativo

    public:
        Ula () {
        	this->Z = false;
        	this->N = false;
        }

        ~Ula(void) = default;            

        int executarOperacao( int x, int y, int operacao ); // executa operações binárias
        int executarOperacao( int x ); // para operações unárias
        void atualizaNZ( int resultado );

};

#endif
//#endif