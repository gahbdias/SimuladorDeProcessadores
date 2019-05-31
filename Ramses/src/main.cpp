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

void decodificar( int instrucao ) {
	int codigo[3];
	int aux;

	for (int i=0; i<3; i++){
		aux = instrucao%100;
		codigo[i] = aux;
		instrucao = (instrucao-aux)/100;
	}
	
	std::cout << codigo[2] << std::endl;
	std::cout << codigo[1] << std::endl;
	std::cout << codigo[0] << std::endl;
}

int main ( int argc, char *argv[] ) {


	decodificar(203040);

	/*int estado = 1;

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
	}*/

	return EXIT_SUCCESS;
}

