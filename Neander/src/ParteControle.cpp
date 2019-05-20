/**
 * @file ParteControle.cpp
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador de modelos Parte de Controle (PC) - Parte Operativa (PO)
 * @version 1.00
 * @date 06-04-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "../include/ParteControle.h"
#include "../include/ParteOperativa.h"
#include "../include/ULA.h"
#include <thread>
#include <chrono>

ParteControle::ParteControle ( ) {
	this->atual = 0; // começa no estado 0
	this->proximo = 0; // será definido posteriormente (apenas para não ser inicializado com lixo)
	this->clock_ = 0; // tempo 0 
	this->fim = false; // para indicar que o programa não chegou ao fim
}


int ParteControle::fte( int atual ){ // Função de Transição de Estados ~ define qual será o próximo estado

	switch(atual){
	        case 0: // while(!sair)
			if( PO.ula.executarOperacao( PO.regs.lerRegistro(0) ) ) {proximo = 1;}
			else { fim = true; }
		break;

		case 1:
			proximo = 2;
		break;

		case 2:
			proximo = 3;
		break;

		case 3:
			proximo = 4;
		break;

		case 4:
			proximo = 5;
		break;

		case 5:
			proximo = 6;
		break;

		case 6:
			proximo = 7;
		break;

		case 7:
			proximo = 8;
		break;

		case 8:
			proximo = 9;
		break;

		case 9:
			proximo = 10;
		break;

		case 10:
			proximo = 11;
		break;

		/*
		** [0] = sair , [1] = x , [2] = r, [3] = res   , [4] = aux1, 
		** [5] = aux2 , [6] = rp, [7] = 1, [8] = 10e-16, [9] = -1
		*/
		case 11:	// (x < rp)
			if( PO.ula.executarOperacao( PO.regs.lerRegistro(1), PO.regs.lerRegistro(6), 5 ) ) {proximo = 12;} 
			else {proximo = 13;}
		break;

		case 12:
			proximo = 13;
		break;

		case 13:
			proximo = 14;
		break;

		case 14:	// (aux1 || aux2)
			if ( PO.ula.executarOperacao( PO.regs.lerRegistro(4), PO.regs.lerRegistro(5), 6 ) ) {proximo = 15;} 
			else {proximo = 16;}
		break;

		case 15:
			proximo = 0;
		break;

		case 16:
			proximo = 0;
		break;
		default: std::cout << "\n### Entrada inválida fte ###" << std::endl;

	}

	return proximo;
}

void ParteControle::fs ( int atual ) { // Função de saída ~ recebe o estado atual e controla as operações (chama as funções da PO)

	double valor;

	std::cout << std::endl;
	std::cout << "Clocks decorridos:" << clock_ << std::endl;


	switch(atual){
		/*
		** [0] = sair , [1] = x , [2] = r, [3] = res   , [4] = aux1, 
		** [5] = aux2 , [6] = rp, [7] = 1, [8] = 10e-16, [9] = -1
		*/

		/*
		**	0 = soma (+)
		**	1 = subtração (-)
		**	2 = multiplicação (*)
		**	3 = divisão (/)
		**	4 = igualdade (==)
		**	5 = menor (<)
		**	6 = ou (||)
		**	
		*/

		case 0: // !sair ~ Apenas transição de estado
			std::cout << "### ESTADO 0 ###" << std::endl;
		break;

		case 1: // aux2 = r*r
			std::cout << "### ESTADO 1 ###" << std::endl;
			std::cout << "Antes de (aux2 = r*r): " << PO.regs.lerRegistro(5) << std::endl;

			valor = PO.ula.executarOperacao( PO.regs.lerRegistro(2), PO.regs.lerRegistro(2), 2 );
			std::cout << "Resultado da ULA : " << valor << std::endl;

			PO.regs.escreverRegistro(valor, 5);
			std::cout << "Registro aux2 : " <<  PO.regs.lerRegistro(5) << std::endl;
		break;

		case 2: // aux1 = x - aux2
			std::cout << "### ESTADO 2 ###" << std::endl;
			std::cout << "Antes de (aux1 = x - aux2) : " << PO.regs.lerRegistro(4) << std::endl;

			valor = PO.ula.executarOperacao( PO.regs.lerRegistro(1), PO.regs.lerRegistro(5), 1 );
			std::cout << "Resultado da ULA: " << valor << std::endl;

			PO.regs.escreverRegistro(valor, 4);
			std::cout << "Registro de aux1: " << PO.regs.lerRegistro(4) << std::endl;
		break;

		case 3: // aux2 = r + r
			std::cout << "### ESTADO 3 ###" << std::endl;
			std::cout << "Antes de (aux2 = r + r) : " << PO.regs.lerRegistro(5) << std::endl;

			valor = PO.ula.executarOperacao( PO.regs.lerRegistro(2), PO.regs.lerRegistro(2), 0 );
			std::cout << "Resultado da ULA: " << valor << std::endl;

			PO.regs.escreverRegistro(valor, 5);
			std::cout << "Registro aux2 : " <<  PO.regs.lerRegistro(5) << std::endl;
		break;

		case 4: // aux2 = aux1 / aux2
			std::cout << "### ESTADO 4 ###" << std::endl;
			std::cout << "Antes de (aux2 = aux1/ aux2) : " << PO.regs.lerRegistro(5) << std::endl;

			valor = PO.ula.executarOperacao( PO.regs.lerRegistro(4), PO.regs.lerRegistro(5), 3 );
			std::cout << "Resultado da ULA: " << valor << std::endl;

			PO.regs.escreverRegistro(valor, 5);
			std::cout << "Registro aux2 : " <<  PO.regs.lerRegistro(5) << std::endl;
		break;

		case 5: // res = r + aux2
			std::cout << "### ESTADO 5 ###" << std::endl;
			std::cout << "Antes de (res = r + aux2) : " << PO.regs.lerRegistro(3) << std::endl;

			valor = PO.ula.executarOperacao( PO.regs.lerRegistro(2), PO.regs.lerRegistro(5), 0 );
			std::cout << "Resultado da ULA: " << valor << std::endl;

			PO.regs.escreverRegistro(valor, 3);
			std::cout << "Registro res : " <<  PO.regs.lerRegistro(3) << std::endl;
		break;

		case 6: // rp = res * res
			std::cout << "### ESTADO 6 ###" << std::endl;
			std::cout << "Antes de (rp = res * res) : " << PO.regs.lerRegistro(6) << std::endl;

			valor = PO.ula.executarOperacao( PO.regs.lerRegistro(3), PO.regs.lerRegistro(3), 2 );
			std::cout << "Resultado da ULA: " << valor << std::endl;

			PO.regs.escreverRegistro(valor, 6);
			std::cout << "Registro rp : " <<  PO.regs.lerRegistro(6) << std::endl;
		break;

		case 7: // aux1 = (x == rp)
			std::cout << "### ESTADO 7 ###" << std::endl;
			std::cout << "Antes de (aux1 = x == rp) : " << PO.regs.lerRegistro(4) << std::endl;

			valor = PO.ula.executarOperacao( PO.regs.lerRegistro(1), PO.regs.lerRegistro(6), 4 );
			std::cout << "Resultado da ULA: " << valor << std::endl;

			PO.regs.escreverRegistro(valor, 4);
			std::cout << "Registro aux1 : " <<  PO.regs.lerRegistro(4) << std::endl;
		break;

		case 8: // aux2 = (r == res)
			std::cout << "### ESTADO 8 ###" << std::endl;
			std::cout << "Antes de (aux2 = r == res) : " << PO.regs.lerRegistro(5) << std::endl;

			valor = PO.ula.executarOperacao( PO.regs.lerRegistro(2), PO.regs.lerRegistro(3), 4 );
			std::cout << "Resultado da ULA: " << valor << std::endl;

			PO.regs.escreverRegistro(valor, 5);
			std::cout << "Registro aux2 : " <<  PO.regs.lerRegistro(5) << std::endl;
		break;

		case 9: // aux2 = (aux1 || aux2)
			std::cout << "### ESTADO 9 ###" << std::endl;
			std::cout << "Antes de (aux2 = aux1 || aux2) : " << PO.regs.lerRegistro(5) << std::endl;

			valor = PO.ula.executarOperacao( PO.regs.lerRegistro(4), PO.regs.lerRegistro(5), 6 );
			std::cout << "Resultado da ULA: " << valor << std::endl;

			PO.regs.escreverRegistro(valor, 5);
			std::cout << "Registro aux2 : " <<  PO.regs.lerRegistro(5) << std::endl;
		break;

		case 10: // aux1 = (x - rp )
			std::cout << "### ESTADO 10 ###" << std::endl;
			std::cout << "Antes de ( aux1 = x - rp) : " << PO.regs.lerRegistro(4) << std::endl;

			valor = PO.ula.executarOperacao( PO.regs.lerRegistro(1), PO.regs.lerRegistro(6), 1 );
			std::cout << "Resultado da ULA: " << valor << std::endl;

			PO.regs.escreverRegistro(valor, 4);
			std::cout << "Registro aux1 : " <<  PO.regs.lerRegistro(4) << std::endl;
		break;

		case 11: // if(x < rp) ~ Apenas transição de estado
			std::cout << "### ESTADO 11 ###" << std::endl;
		break;

		case 12: // aux1 = aux1*-1
			std::cout << "### ESTADO 12 ###" << std::endl;
			std::cout << "Antes de (aux1 = aux1*-1) : " << PO.regs.lerRegistro(4) << std::endl;

			valor = PO.ula.executarOperacao( PO.regs.lerRegistro(4), PO.regs.lerRegistro(9), 2 );
			std::cout << "Resultado da ULA: " << valor << std::endl;

			PO.regs.escreverRegistro(valor, 4);
			std::cout << "Registro aux1 : " <<  PO.regs.lerRegistro(4) << std::endl;
		break;

		case 13: // aux1 = aux1 < 10^{-16}
			std::cout << "### ESTADO 13 ###" << std::endl;
			std::cout << "Antes de (aux1 = aux1 < 10^-16) : " << PO.regs.lerRegistro(4) << std::endl;

			valor = PO.ula.executarOperacao( PO.regs.lerRegistro(4), PO.regs.lerRegistro(8), 5 );
			std::cout << "Resultado da ULA: " << valor << std::endl;

			PO.regs.escreverRegistro(valor, 4);
			std::cout << "Registro aux1 : " <<  PO.regs.lerRegistro(4) << std::endl;
		break;

		case 14: // if( aux1 || aux2) ~ Apenas transição de estado
			std::cout << "### ESTADO 14 ###" << std::endl;
		break;

		case 15: // sair =!sair
			std::cout << "### ESTADO 15 ###" << std::endl;
			std::cout << "Antes de (sair = !sair) : " << PO.regs.lerRegistro(0) << std::endl;

			valor = PO.ula.executarOperacao( PO.regs.lerRegistro(0) );
			std::cout << "Resultado da ULA: " << valor << std::endl;

			PO.regs.escreverRegistro(valor, 0);
			std::cout << "Registro sair : " <<  PO.regs.lerRegistro(0) << std::endl;
		break;

		case 16: // r = res
			std::cout << "### ESTADO 16 ###" << std::endl;
			std::cout << "Antes de (r = res) : " << PO.regs.lerRegistro(2) << std::endl;

			PO.regs.escreverRegistro( PO.regs.lerRegistro(3), 2);
			std::cout << "*** escreverRegistro de r: " << PO.regs.lerRegistro(2) << std::endl;
		break;

		default: std::cout << "\n### Entrada inválida fs ###" << std::endl;

	}
		std::cout << std::endl;


}

