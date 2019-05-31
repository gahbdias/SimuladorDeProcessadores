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

class ProgCont { 

 public:
  int leituraAtual; // linha na memória contendo a instrução sendo executada

 public:
  ProgCont( void ) { leituraAtual = 0; }
  
  ~ProgCont( void ) = default;

  void loadPC( int valor ) { this->leituraAtual = valor; } 

  void incrementarPC( void ) { this->leituraAtual++; }

  void incrementarPC( int valor ) { this->leituraAtual = valor + leituraAtual; }

  void imprimePC( void ) { std::cout << "PC: " << leituraAtual << std::endl; };

};

#endif
