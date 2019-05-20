/**
 * @file AC.h
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador de modelos Parte de Controle (PC) - Parte Operativa (PO)
 * @version 1.00
 * @date 05-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _AC_H_
#define _AC_H_
#include <iostream>

class AC { // ACUMULADOR

	public:
		int acumulador[2];

    public:
        AC ( );
        ~AC(void) = default;

};


#endif