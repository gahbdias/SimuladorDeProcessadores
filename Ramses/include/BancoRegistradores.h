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

#include "RegistradorA.h"
#include "RegistradorB.h"
#include "RegistradorX.h"

class BancoRegistradores { // Registrador de intruções

	public:
	  RegistradorA RA; // código da operação
	  RegistradorB RB; // qual registrador será utilizado
	  RegistradorX RX; // modo de enderaçamento

	public:
	  BancoRegistradores( ) { }
	  
	  ~BancoRegistradores( void ) = default;	  
};

#endif