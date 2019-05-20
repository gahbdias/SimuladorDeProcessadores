/**
 * @file ULA.cpp
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador de modelos Parte de Controle (PC) - Parte Operativa (PO)
 * @version 1.00
 * @date 06-04-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "../include/ULA.h"

ULA::ULA ( ){};

double ULA::executarOperacao( double a, double b, int operacao ) {

	switch(operacao){
		case 0:
			return (a+b);

		case 1:
			return (a-b);

		case 2:
			return (a*b);

		case 3:
			return (a/b);

		case 4:
			return (a == b);

		case 5:
			return ( a < b );
		break;

		case 6:
			return ( a || b );
		break;

		default: 
			std::cout << "\n### Entrada inválida ULA ###" << std::endl;
			return 0;
	}

}

int ULA::executarOperacao( int a ) { return !a; } // negação
