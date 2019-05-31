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

#include "RA.h"
#include "RB.h"
#include "RX.h"

class BancoRegistradores { // Registrador de intruções

	public:
	  RA ra; // código da operação
	  RB rb; // qual registrador será utilizado
	  RX rx; // modo de enderaçamento

	public:
	  BancoRegistradores( ) { }
	  
	  ~BancoRegistradores( void ) = default;	  
};

#endif