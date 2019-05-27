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

class Acumulador { 

 public:
  int x; // valor guardado no acumulador

 public:
  AC ( ){ x(666); }
  
  ~AC(void) = default;

  // carrega o acumulador com um valor
  void loadAC( int valor ) 
  {
    x = valor;
  }

};


#endif
