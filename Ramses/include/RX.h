/**
 * @file RX.h
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador do Ramses
 * @version 1.00
 * @date Jun-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _RX_H_
#define _RX_H_
#include <iostream>

#define VAZIO 666

class RX { 

 public:
  int X; // valor guardado no RX

 public:
  	RX( ){ X = VAZIO; }
  
  	~RX( void ) = default;
  	
  	void loadRX( int valor ) { X = valor; } // carrega o RX com um valor

  	void imprimeRX( void ) { 
  		if( X == VAZIO ){
  			std::cout << "RX: Vazio" << std::endl; 
  		} else {
  			std::cout << "RX: " << X << std::endl; 
  		}  		
  	}
    
};


#endif
