/**
 * @file RegInstrucao.h
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador do Ramses
 * @version 1.00
 * @date Jun-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _RegInstrucao_H_
#define _RegInstrucao_H_

#include <iostream>

enum operacoes { 
	NOP = 10, 
	STR, 
	LDR, 
	ADD, 
	OR, 
	AND,
	SUB, 
	NOT, 
	JMP, 
	JN, 
	JZ,
	JC,
	JSR,
	NEG,
	SHR, 
	HLT // 25
};

enum registradores {
	A = 30,
	B,
	X,
	NONE // 33
};

enum modoEnderecamento {
	Dir = 40,
	Ind,
	Ime,
	Idx // 43
};

class RegInstrucao { // Registrador de intruções

	public:
	  int opcode; // código da operação
	  int registrador; // qual registrador será utilizado
	  int modo; // modo de enderaçamento

	public:
	  RegInstrucao( ) { opcode = NOP; }
	  
	  ~RegInstrucao( void ) = default;

	  void loadRI( int instrucao );

	  void decodificar( int instrucao );
	  
};


#endif
