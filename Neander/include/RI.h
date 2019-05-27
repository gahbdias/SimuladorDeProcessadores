/**
 * @file RI.h
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador de modelos Parte de Controle (PC) - Parte Operativa (PO)
 * @version 1.00
 * @date 05-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _RI_H_
#define _RI_H_
#include <iostream>


enum operacoes { NOP, STA, LDA, ADD, OR, AND, NOT, JMP, JN, JZ, HLT };

class RI { // Registrador de 

public:
  int opcode;

public:
  RI ( )
  {
    opcode = NOP;
  }
  ~RI(void) = default;
  
};


#endif
