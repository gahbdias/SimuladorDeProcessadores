/**
 * @file main.cpp
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador de modelos Parte de Controle (PC) - Parte Operativa (PO)
 * @version 1.00
 * @date 06-04-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "../include/ParteOperativa.h"
#include "../include/ParteControle.h"
#include "../include/ULA.h"

int main (void) {
	
	int estado = 0;

	ParteControle PC;

	PC.PO.regs.escreverRegistro( 0, 0 );  // sair
	PC.PO.regs.escreverRegistro( 3, 1 );  // x
	PC.PO.regs.escreverRegistro( 1, 2 );  // r
	PC.PO.regs.escreverRegistro( 0, 3 );  // res
	PC.PO.regs.escreverRegistro( 0, 4 );  // aux1
	PC.PO.regs.escreverRegistro( 0, 5 );  // aux2 
	PC.PO.regs.escreverRegistro( 0, 6 );  // rp
	PC.PO.regs.escreverRegistro( 1, 7 );  // 1
	PC.PO.regs.escreverRegistro( 10e-16, 8 );  // 10^-16
	PC.PO.regs.escreverRegistro( -1, 9 ); // -1

	while( !PC.fim ){ 
		PC.fs(estado);
		estado = PC.fte(estado);
		PC.clock_++;
	}

	std::cout << "\n\n Estimativa de raiz de " << PC.PO.regs.lerRegistro(1) << " : " << PC.PO.regs.lerRegistro(3) << std::endl;

	return EXIT_SUCCESS;
}
