/**
 * @file Relogio.h
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador do Neander
 * @version 1.00
 * @date Jun-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _Relogio_H_
#define _Relogio_H_
#include <iostream>

class Relogio { 

 public:
  int clock_; // Clock da unidade de controle

 public:
  	Relogio( ) { clock_ = 0; }
  
  	~Relogio(void) = default;

  	void clockLA() { clock_++; } // incremento para operações lógica ariméticas

  	void clockMemoria() { clock_ += 3; } // incremento para acesso a memória

  	void imprimeClock() { std::cout << "Clock atual: " << clock_ << std::endl; } // imprime o Clock atual

};

#endif

