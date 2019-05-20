/**
 * @file Memoria.h
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador de modelos Parte de Controle (PC) - Parte Operativa (PO)
 * @version 1.00
 * @date 06-04-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _MEM_H_
#define _MEM_H_
#include <iostream>


class Memoria {

	private:
		double memoria[256];

    public:
        REGS ( );
        ~REGS(void) = default;            

        double lerRegistro( int endereco ); // acessa um endereço e retorna seu valor
		void escreverRegistro( double valor, int endereco ); // escreve um valor em um endereço

};


#endif