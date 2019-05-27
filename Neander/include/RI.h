/**
 * @file RI.h
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador do Neander
 * @version 1.00
 * @date Jun-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _RegInstrucao_H_
#define _RegInstrucao_H_

#include <iostream>

enum operacoes { NOP, STA, LDA, ADD, OR, AND, NOT, JMP, JN, JZ, HLT };

class RegInstrucao { // Registrador de intruções

public:
  int opcode; // código da operação

public:
  RegInstrucao( ) { opcode = NOP; }
  
  ~RegInstrucao( void ) = default;

  void loadRI( int code ) { opcode = code; }
  
};


#endif
