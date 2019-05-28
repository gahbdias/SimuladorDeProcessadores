/**
 * @file Memoria.cpp
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador do Neander
 * @version 1.00
 * @date Jun-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "../include/Memoria.h"

void Memoria::preencherMemoria ( std::string  fileNameAlg, std::string  fileNameData ){
  // Inicialização da memória
  for( int i=0; i< 256; i++ ){
    memoria[i] = 666;
  }

  // inicializa RDM e REM
  rem = 666;
  rdm = 666;
  
  std::string line; // linha do arquivo lida

  // abre o algoritmo a ser executado
  std::ifstream algorithmFile;

  algorithmFile.open( fileNameAlg );

  // If file fail to open throw exception
  if( algorithmFile.fail() ){
    throw std::invalid_argument("Arquivo do algoritmo não pode ser aberto.");
  }


  // preenche memória com algoritmo
  std::cout << "Lendo arquivo do algoritmo..." << std::endl;

  int i=0;
  while( !algorithmFile.eof() and i < 128 ){
 
    char opcode[3];
    int endereco=0;

    getline( algorithmFile, line );
    std::stringstream lineStr(line); // string stream para conversão
    

    if( line.size() <= 4 ){ // instrução de 1 byte
      
      lineStr >> opcode >> std::ws;
      this->memoria[i] = strToCode( opcode );

      i++;
      
    } else { // instrução de 2 bytes
      
      lineStr >> opcode >> std::ws >> endereco >> std::ws;
      this->memoria[i] = strToCode( opcode );
      this->memoria[i+1] = endereco;

      i += 2;      
    }


  }
  algorithmFile.close();

  // abre os arquivo dados 
  std::ifstream dataFile;

  dataFile.open( fileNameData );

  // If file fail to open throw exception
  if( dataFile.fail() ){
    throw std::invalid_argument("Arquivo dos dados não pode ser aberto.");
  }

  // preenche memória com os dados
  std::cout << "Lendo arquivo de dados..." << std::endl;

  i=128;
  while( !dataFile.eof() and i < 256 ){
    int dado;

    getline( dataFile, line );
    std::stringstream lineStr(line); // string stream para conversão
    
    lineStr >> dado >> std::ws;
    this->memoria[i] = dado;
    
    i++;
  }

  dataFile.close();
}

void Memoria::loadREM( int endereco )
{
  rem = endereco;
}

void Memoria::loadRDM( void ){

  rdm = this->memoria[rem];
}

void Memoria::loadRDM( int valor ){

  rdm = valor;
}

void Memoria::escreverRegistro( void ){

	this->memoria[rem] = rdm;

}


int Memoria::strToCode( const std::string opcode )
{

  if( opcode == "NOP" ){
    return NOP;

  } else if( opcode == "STA" ){
    return STA;

  } else if( opcode == "LDA" ){
    return LDA;

  } else if( opcode == "ADD" ){
    return ADD;

  } else if( opcode == "OR" ){
    return OR;

  } else if( opcode == "AND" ){
    return AND;

  } else if( opcode == "NOT" ){
    return NOT;

  } else if( opcode == "JMP" ){
    return JMP;

  } else if( opcode == "JN" ){
    return JN;

  } else if( opcode == "JZ" ){
    return JZ;

  } else if( opcode == "HLT" ){
    return HLT;
    
  } else {
    std::cout << "Erro em strToCode: codigo inválido. " << std::endl; 
    return -1;
  }

}
