/**
 * @file Memoria.cpp
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador de modelos Parte de Controle (PC) - Parte Operativa (PO)
 * @version 1.00
 * @date 06-04-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "../include/Memoria.h"

Memoria::Memoria ( ){};

double Memoria::lerRegistro( int endereco ){

	return this->memoria[endereco];
}

void Memoria::escreverRegistro( double valor, int endereco ){

	this->memoria[endereco] = valor;

}
