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

int Ula::executarOperacao( int x, int y, int operacao ) { // ADD, AND, OR

	int resultado = LIXO;

	switch( operacao ){
		case ADD:
			resultado = ( x + y );
		break;

		case AND:
			resultado = ( x and y );
		break;

		case OR:
			resultado = ( x or y );
		break;

		default: 
			std::cout << "\n### Entrada inválida ULA ###" << std::endl;
		return LIXO;
	}

	atualizaNZ( resultado );
	return resultado;
}

int Ula::executarOperacao( int x ) { // NOT
	int resultado = LIXO;
	resultado = (x*(-1))-1;
	atualizaNZ( resultado );
	return resultado;
} 

void Ula::atualizaNZ( int resultado ){
	if ( resultado == 0 ){
		this->Z = true;
	}
	else if ( resultado < 0 ){
		this->N = true;
	}
}


