/**
 * @file main.cpp
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador do Neander
 * @version 1.00
 * @date Jun-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "../include/UnidadeControle.h"

int main ( int argc, char *argv[] ) {

	if( argc < 3 ){
		return EXIT_FAILURE;
	}

	std::string algFile = argv[1];
	std::string dataFile = argv[2];
	
	UnidadeControle UC;

	UC.PO.M.preencherMemoria(algFile, dataFile);

	return EXIT_SUCCESS;
}




/*
for( int i=0; i< 256; i++ ){

std::cout << "linha[" << i << "] = " << memo.memoria[i] << std::endl; 

}
*/