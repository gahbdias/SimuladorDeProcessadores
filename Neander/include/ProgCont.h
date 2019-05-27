/**
 * @file ProgCont.h
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador do Neander
 * @version 1.00
 * @date Jun-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _ProgCont_H_
#define _ProgCont_H_
#include <iostream>

class ProgCont { // ACUMULADOR

 public:
  int leituraAtual; // linha na memória contendo a instrução sendo executada

 public:
  ProgCont( )
  {
    leituraAtual(0);
  }
  
  ~ProgCont(void) = default;

  int incrementaPC( void )
  {
    this->leituraAtual++;
  }

};


#endif
