/**
 * @file ProgCont.h
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador de modelos Parte de Controle (PC) - Parte Operativa (PO)
 * @version 1.00
 * @date 05-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _ProgCont_H_
#define _ProgCont_H_
#include <iostream>

class ProgCont { // ACUMULADOR

	public:
		int acumulador[2];

    public:
        ProgCont ( );
        ~ProgCont(void) = default;

};


#endif