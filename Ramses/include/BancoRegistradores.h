/**
 * @file BancoRegistradores.h
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador do Ramses
 * @version 1.00
 * @date Jun-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _BancoRegistradores_H_
#define _BancoRegistradores_H_

#include <iostream>

class BancoRegistradores { // Registrador de intruções

	public:
	  RA ra; // código da operação
	  RB rb; // qual registrador será utilizado
	  RX rx; // modo de enderaçamento

	public:
	  BancoRegistradores( ) { opcode = NOP; }
	  
	  ~BancoRegistradores( void ) = default;

	  void loadRI( int instrucao );

	  void decodificar( int instrucao );
	  
};

#endif