/**
 * @file Memoria.h
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador Neander
 * @version 1.00
 * @date Jun-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _MEM_H_
#define _MEM_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "RI.h"

class Memoria {

public:
  int memoria[256];

public:
  Memoria( std::string  fileNameAlg, std::string  fileNameData );
  ~Memoria( void ) = default;            

  int lerRegistro( int endereco ); // acessa um endereço e retorna seu valor
  void escreverRegistro( int valor, int endereco ); // escreve um valor em um endereço
  void RDM ( void ); // Registrador de dados da memória; guarda os dados lidos da memória 
  int strToCode( std::string opcode ); // converte string lido do algoritmo para um código de operação

};


#endif
