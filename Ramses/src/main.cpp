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

  Memoria memo;

  memo.preencherMemoria( argv[1], argv[2] );
  memo.imprimeDados(); 
  

  /*
	int estado = 1;

	std::cout << "~ Simulador do NEANDER ~" << std::endl;
	std::cout << "Iniciando..." << std::endl;

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
  */
	return EXIT_SUCCESS;
}

