/**
 * @file ParteOperativa.h
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador do Neander
 * @version 1.00
 * @date Jun-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _ParteOperativa_H_
#define _ParteOperativa_H_
#include <iostream>

#include "Memoria.h"
#include "Ula.h"
#include "BancoRegistradores.h"
#include "ProgCont.h"
#include "RegInstrucao.h"

class ParteOperativa {

    public:
    	Memoria M; 
    	Ula ULA; // unidade lógica aritmética
    	BancoRegistradores BR;
    	ProgCont PC; // apontador de programa
    	RegInstrucao RI; // registrador de instruções
	SomadorPonteiros SUM; // Somador de Ponteiros - para o modo indexado

    public:
        ParteOperativa ();
        ~ParteOperativa( void ) = default;
};


#endif
