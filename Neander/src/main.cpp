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

//#include "../include/ParteOperativa.h"
//#include "../include/ParteControle.h"
//#include "../include/ULA.h"
#include "../include/Memoria.h"

int main ( int argc, char *argv[] ) {
	
Memoria memo( "../algoritmos/soma.txt", "../algoritmos/soma_dados.txt" );

for( int i=0; i< 256; i++ ){

std::cout << "linha[" << i << "] = " << memo.memoria[i] << std::endl; 

}

return EXIT_SUCCESS;
}
