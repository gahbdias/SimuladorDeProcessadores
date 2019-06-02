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

	int estado = 1;

	std::cout << "### SIMULADOR do RAMSES ###" << std::endl;
	std::cout << "Iniciando..." << std::endl;
	std::cout << std::endl;

	if( argc < 3 ){
		return EXIT_FAILURE;
	}

	std::string algFile = argv[1];
	std::string dataFile = argv[2];
	
	UnidadeControle UC;
	UC.PO.M.preencherMemoria(algFile, dataFile);

	while( !UC.fim ){
		UC.fs(estado);
		estado = UC.fte(estado);
	}
  	return EXIT_SUCCESS;

}

