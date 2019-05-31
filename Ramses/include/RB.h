/**
 * @file RB.h
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador do Ramses
 * @version 1.00
 * @date Jun-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _RB_H_
#define _RB_H_
#include <iostream>

#define VAZIO 666

class RB { 

 public:
  int B; // valor guardado no RB

 public:
  	RB( ){ B = VAZIO; }
  
  	~RB( void ) = default;
  	
  	void loadRB( int valor ) { B = valor; } // carrega o RB com um valor

  	void imprimeRB( void ) { 
  		if( B == VAZIO ){
  			std::cout << "RB: Vazio" << std::endl; 
  		} else {
  			std::cout << "RB: " << B << std::endl; 
  		}  		
  	}
    
};


#endif
