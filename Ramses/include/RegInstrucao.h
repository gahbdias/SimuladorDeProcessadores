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
	DIRETO = 40,
	INDIRETO,
	IMEDIATO,
	INDEXADO // 43
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

	  void imprimeRI( void ) {

		  	switch( opcode ) {
		  		case NOP:
		  			std::cout << "RI: NOP(10)" << std::endl;
		  		break;

		  		case STR:
		  			std::cout << "RI: STR(11)" << std::endl;
		  		break;

		  		case LDR:
		  			std::cout << "RI: LDR(12)" << std::endl;
		  		break;

		  		case ADD:
		  			std::cout << "RI: ADD(13)" << std::endl;
		  		break;

		  		case OR:
		  			std::cout << "RI: OR(14)" << std::endl;
		  		break;

		  		case AND:
		  			std::cout << "RI: AND(15)" << std::endl;
		  		break;

		  		case SUB:
		  			std::cout << "RI: SUB(16)" << std::endl;
		  		break;

		  		case NOT:
		  			std::cout << "RI: NOT(17)" << std::endl;
		  		break;

		  		case JMP:
		  			std::cout << "RI: JMP(18)" << std::endl;
		  		break;

		  		case JN:
		  			std::cout << "RI: JN(19)" << std::endl;
		  		break;

		  		case JZ:
		  			std::cout << "RI: JZ(20)" << std::endl;
		  		break;

		  		case JC:
		  			std::cout << "RI: JC(21)" << std::endl;
		  		break;

		  		case JSR:
		  			std::cout << "RI: JSR(22)" << std::endl;
		  		break;

		  		case NEG:
		  			std::cout << "RI: NEG(23)" << std::endl;
		  		break;

		  		case SHR:
		  			std::cout << "RI: SHR(24)" << std::endl;
		  		break;

		  		case HLT:
		  			std::cout << "RI: HLT(25)" << std::endl;
		  		break;

		  	} 
	  }	  
};


#endif
