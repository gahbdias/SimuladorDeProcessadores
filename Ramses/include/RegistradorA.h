/**
 * @file RegistradorA.h
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador do Ramses
 * @version 1.00
 * @date Jun-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _RA_H_
#define _RA_H_
#include <iostream>

#define VAZIO 666

class RegistradorA { 

 public:
  int A; // valor guardado no RA

 public:
  	RegistradorA( ){ A = VAZIO; }
  
  	~RegistradorA( void ) = default;
  	
  	void loadRA( int valor ) { A = valor; } // carrega o RA com um valor

  	void imprimeRA( void ) { 
  		if( A == VAZIO ){
  			std::cout << "RA: Vazio" << std::endl; 
  		} else {
  			std::cout << "RA: " << A << std::endl; 
  		}  		
  	}

};


#endif
