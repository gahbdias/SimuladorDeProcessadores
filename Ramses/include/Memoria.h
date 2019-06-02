/**
 * @file Memoria.h
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador do Neander
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

#include "RegInstrucao.h"

#ifndef LIXO
#define LIXO 666

class Memoria {

public:
  int memoria[256];
  int rem; // registrador de endereços da memória; guarda o endereço a ser acessado na memória
  int rdm; // registrador de dados da memória; guarda a última leitura da memória
  int temp; // temp

public:
  Memoria(){};

  ~Memoria( void ) = default;   

  void escreverRegistro( void ); // escreve o valor guardado no rdm no endereço guardado no rem

  void loadREM( int endereco ); // carrega REM

  void loadRDM( void ); // acessa o endereço guardado no rem e guarda seu valor no rdm

  void loadRDM( int valor ); // guarda valor passado no rdm (valor vem do acumulador)

  void preencherMemoria ( std::string  fileNameAlg, std::string  fileNameData ); // preenche a memoria com dados do arquivo  
  
  int strToCode( std::string opcode ); // converte string lido do algoritmo para um código de operação

  void imprimeDados();

  void codeToStr( int instrucao, std::string* opcode, std::string* registrador, std::string* modo);

};

#endif
#endif
