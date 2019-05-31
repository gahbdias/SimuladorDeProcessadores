/**
 * @file RegInstrucao.cpp
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador do Neander
 * @version 1.00
 * @date Jun-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "../include/RegInstrucao.h"

void RegInstrucao::loadRI( int instrucao ){
	decodificar(instrucao);
}

void RegInstrucao::decodificar( int instrucao ){
	int codigo[3];
	int aux;

	for (int i=0; i<3; i++){
		aux = instrucao%100;
		codigo[i] = aux;
		intrucao = (instrucao-aux)/100;
	}
	

	this->opcode = codigo[2];
	this->registrador = codigo[1]
	this->modo = codigo[0];
}