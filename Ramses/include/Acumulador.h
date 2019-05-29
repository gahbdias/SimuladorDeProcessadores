/**
 * @file AC.h
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador do Neander
 * @version 1.00
 * @date Jun-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _Acumulador_H_
#define _Acumulador_H_
#include <iostream>

#define VAZIO 666

class Acumulador { 

 public:
  int x; // valor guardado no acumulador

 public:
  	Acumulador( ){ x = VAZIO; }
  
  	~Acumulador(void) = default;
  	
  	void loadAC( int valor ) { x = valor; } // carrega o acumulador com um valor

  	void imprimeAC( void ) { 
  		if( x == VAZIO ){
  			std::cout << "AC: Vazio" << std::endl; 
  		} else {
  			std::cout << "AC: " << x << std::endl; 
  		}  		
  	}

};


#endif
//#endif
