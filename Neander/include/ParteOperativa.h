/**
 * @file ParteOperativa.h
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador de modelos Parte de Controle (PC) - Parte Operativa (PO)
 * @version 1.00
 * @date 06-04-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _ParteOperativa_H_
#define _ParteOperativa_H_
#include <iostream>
#include "ULA.h"
#include "REGS.h"

class ParteOperativa {

    public:
    	ULA ula; // unidade lógica aritmética
    	REGS regs; // registradores

    public:
        ParteOperativa ( );
        ~ParteOperativa(void) = default;
};


#endif