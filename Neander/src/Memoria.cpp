/**
 * @file Memoria.cpp
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador Neander
 * @version 1.00
 * @date Jun-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */


#include "../include/Memoria.h"

Memoria::Memoria ( std::string  fileNameAlg, std::string  fileNameData ){

  int lixo=666;
  for( int i=0; i< 256; i++ ){
    memoria[i] = lixo;
  }

  std::string line; // linha do arquivo lida
  std::stringstream lineStr; // string stream para conversão

  // abre o algoritmo a ser executado
  std::ifstream algorithmFile;

  algorithmFile.open( fileNameAlg );

  // If file fail to open throw exception
  if( algorithmFile.fail() ){
    throw std::invalid_argument("Arquivo do algoritmo não pode ser aberto.");
  }


  // preenche memória com algoritmo
  std::cout << "Lendo arquivo do algoritmo" << std::endl;

  int i=0;
  while( !algorithmFile.eof() and i < 128 ){
    //fflush( lineStr );
 
    char opcode[3];
    int endereco;

    getline( algorithmFile, line );
    lineStr << line;
	
    std::cout << "linha: \"" << line << "\" " << std::endl;
    if( line.size() <= 4 ){ // instrução de 1 byte
      opcode[0] = line[0];
      opcode[1] = line[1];
      opcode[2] = line[2];

      // lineStr >> opcode >> std::ws;
      this->memoria[i] = strToCode( opcode );
      std::cout << " 1 byte " << opcode << std::endl;

    } else { // instrução de 2 bytes
      opcode[0] = line[0];
      opcode[1] = line[1];
      opcode[2] = line[2];

      std::string tmp;
      lineStr >>  tmp >> endereco >> std::ws;
      this->memoria[i] = strToCode( opcode );
      this->memoria[i] = endereco;
      std::cout << " 2 byte; code: " << opcode << " end: " << endereco << std::endl;
    }

    i++;
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
  std::cout << "Lendo arquivo de dados" << std::endl;

  std::cout << "eof: " << dataFile.eof() << std::endl;


  i=128;
  while( !dataFile.eof() and i < 256 ){
    int dado;

    getline( dataFile, line );
    lineStr << line;
    std::cout << "linha: \"" << line << "\" " << std::endl;

    lineStr >> dado >> std::ws;
    std::cout << "dado[" << i << "] " << dado << std::endl;

    this->memoria[i] = dado;
    i++;
  }

  dataFile.close();

}

int Memoria::lerRegistro( int endereco ){

	return this->memoria[endereco];
}

void Memoria::escreverRegistro( int valor, int endereco ){

	this->memoria[endereco] = valor;

}

void Memoria::RDM ( void )
{

}

int Memoria::strToCode( const std::string opcode )
{

  std::cout << " strToCode " << opcode << "." << std::endl;

  if( opcode.compare("NOP") == 0 ){
    return NOP;

  } else if( opcode == "STA" ){
    return STA;

  } else if( opcode == "LDA" ){
    std::cout << "entre!" << std::endl;
    return LDA;

  } else if( opcode.compare("ADD") == 0 ){
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
