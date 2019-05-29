/**
 * @file RegInstrucao.h
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

	  void imprimeRI( void ) {

		  	switch(opcode) {
		  		case NOP:
		  			std::cout << "RI: NOP(0)" << std::endl;
		  		break;

		  		case STA:
		  			std::cout << "RI: STA(1)" << std::endl;
		  		break;

		  		case LDA:
		  			std::cout << "RI: LDA(2)" << std::endl;
		  		break;

		  		case ADD:
		  			std::cout << "RI: ADD(3)" << std::endl;
		  		break;

		  		case OR:
		  			std::cout << "RI: OR(4)" << std::endl;
		  		break;

		  		case AND:
		  			std::cout << "RI: AND(5)" << std::endl;
		  		break;

		  		case NOT:
		  			std::cout << "RI: NOT(6)" << std::endl;
		  		break;

		  		case JMP:
		  			std::cout << "RI: JMP(7)" << std::endl;
		  		break;

		  		case JN:
		  			std::cout << "RI: JN(8)" << std::endl;
		  		break;

		  		case JZ:
		  			std::cout << "RI: JZ(9)" << std::endl;
		  		break;

		  		case HLT:
		  			std::cout << "RI: HLT(10)" << std::endl;
		  		break;
		  	} 
	  }
	  
};


#endif
