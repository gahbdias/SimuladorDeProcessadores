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
  int rem; // registrador de endereços da memória; guarda o endereço a ser acessado na memória
  int rdm; // registrador de dados da memória; guarda a última leitura da memória

public:
  Memoria( std::string  fileNameAlg, std::string  fileNameData );
  ~Memoria( void ) = default;            

  void loadREM( int endereco ); // carrega REM
  void loadRDM( void ); // acessa o endereço guardado no rem e guarda seu valor no rdm
  void loadRDM( int valor ); // guarda valor passado no rdm (valor vem do acumulador)
  void escreverRegistro( void ); // escreve o valor guardado no rdm no endereço guardado no rem
  int strToCode( std::string opcode ); // converte string lido do algoritmo para um código de operação

};


#endif
