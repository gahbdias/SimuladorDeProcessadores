/**
 * @file Ula.cpp
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador do Neander
 * @version 1.00
 * @date Jun-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "../include/Ula.h"

int Ula::executarOperacao( int x, int y, int operacao ) { // ADD, OR, AND, SUB

	int resultado = LIXO;

	switch( operacao ){
		case ADD:
			resultado = ( x + y );
		break;

		case OR:
			resultado = ( x or y );
		break;

		case AND:
			resultado = ( x and y );
		break;

		case SUB:
			resultado = ( x - y );
		break;		

		default: 
			std::cout << "\n### Entrada inválida ULA BINARIA ###" << std::endl;
		return LIXO;
	}

	atualizaNZC( resultado );
	return resultado;
}

int Ula::executarOperacao( int x, int operacao ) { // NOT, NEG, SHR
	int resultado = LIXO;

	switch( operacao ){
		case NOT: // TROCA OS BITS, 0101 = 1010
			resultado = ( x * (-1) )-1;
		break;

		case NEG:
			resultado = ( x * (-1) );
		break;

		case SHR:
			resultado = ( x = x/2 );
		break;

		default: 
			std::cout << "\n### Entrada inválida ULA UNARIA ###" << std::endl;
		return LIXO;
	}

	atualizaNZC( resultado );
	return resultado;
} 

void Ula::atualizaNZC( int resultado ){
	if ( resultado == 0 ){
		this->Z = true;
	}
	else if ( resultado < 0 ){
		this->N = true;
	}
	else if ( (resultado > 127) or (resultado < -128) ){ // LIMITE DE 8 BITS
		this->C = true;
	}
}


