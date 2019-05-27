/**
 * @file Instrucao.h
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador do Neander
 * @version 1.00
 * @date Jun-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _Instrucao_H_
#define _Instrucao_H_
#include <iostream>

class Instrucao { // ACUMULADOR

	public:
		int acumulador[2];

    public:
        Instrucao ( );
        ~Instrucao(void) = default;

};


#endif