/**
 * @file Ula.cpp
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador do Ramses
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

	atualizaNZC( resultado, operacao ); // verifique se o resultado é negativo, zero ou houve overflow

	resultado = resultado%10000; // guarde apenas 4 digitos no caso de overflow
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

	atualizaNZC( resultado, operacao ); // verifique se o resultado é negativo, zero ou houve overflow

	resultado = resultado%10000; // guarde apenas 4 digitos no caso de overflow
	return resultado;
} 

void Ula::atualizaNZC( int resultado, int operacao ){

	if ( resultado == 0 ){
	  this->Z = true;
	} else {
	  this->Z = false;
	}
	
	if ( resultado < 0 ){
	  this->N = true;
	} else {
	  this->N = false;
	}

	// operações que atualizam o carrry: ADD, SUB, NEG e SHR
	if( operacao == ADD or operacao == NEG ) {
	  if ( resultado/10000 != 0  ){ // LIMITE DE 8 BITS (4 DÍGITOS)
	    this->C = true;
	  } else {
	    this->C = false;
	  }

	} else if( operacao == SUB ) {
	  if ( resultado/10000 != 0  ){ // LIMITE DE 8 BITS (4 DÍGITOS)
	    this->C = false;
	  } else {
	    this->C = true;
	  }

	} else if( operacao == SHR ) {
	  if ( resultado%2 == 0 ){ // se numero for par guarde o bit mais significativo do binário
	    this->C = true;
	  } else {
	    this->C = false;
	  }

	}


}


