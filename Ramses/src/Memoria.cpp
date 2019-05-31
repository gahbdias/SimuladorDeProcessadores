/**
 * @file Memoria.cpp
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador do Ramses
 * @version 1.00
 * @date Jun-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "../include/Memoria.h"

void Memoria::imprimeDados (){

  std::cout << "RDM: " << rdm << std::endl;
  std::cout << "REM: " << rem << std::endl;

  for( int i=128; i<256; i++ ){
    if( memoria[i] != LIXO ){
      std::cout << "Memoria[" << i << "]: " << memoria[i] << std::endl;
    }
  }
}

void Memoria::preencherMemoria ( std::string  fileNameAlg, std::string  fileNameData ){
  // Inicialização da memória
  for( int i=0; i< 256; i++ ){
    memoria[i] = LIXO;
  }

  // inicializa RDM e REM
  rem = LIXO;
  rdm = LIXO;
  
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
 
    std::string opcode;
    int registrador = NONE;
    int modo = Dir;
    int endereco;
    int instrucao;

    getline( algorithmFile, line );
    std::stringstream lineStr(line); // string stream para conversão
    
    //lineStr >> opcode >> std::ws; // leia o opcode e descubra o como codificar a instrução
    //std::cout << opcode;


    // verificando opcode
    char ws = ' ';
    auto nchar = 0u;
    while( line[nchar] != ws && nchar < line.size() ){
      opcode.push_back( line[nchar] );
      nchar++;      
    }
    nchar++; // pule caracter em branco

    // verificando se há registrador
    if( ( line[nchar] == 'A' || line[nchar] == 'B' || line[nchar] == 'X' ) && nchar < line.size() ){
      // atribua registrador especificado
      registrador = (line[nchar] == 'A') ? A : (line[nchar] == 'B') ? B : X;    
      nchar++;
      
      nchar++; // pule caracter em branco
    }

    // verificando se há modo de endereçamento
    if( line[nchar] == '#'  && nchar < line.size() ) {
      modo = Ime; // modo de endereçamento imediato
      nchar++;
      
    } else if( line[ line.size() ] == 'I'  && nchar < line.size() ) {
      modo = Ind; // modo de endereçamento indireto
 
    } else if( line[ line.size() ] == 'X'  && nchar < line.size() ) {
      modo = Idx; // modo de endereçamento indexado
 
    } 

    if( nchar < line.size() ) {
      
    }
    
    //std::cout << nchar << std::endl;
    std::cout << "opcode: " << opcode << "; reg: " << registrador << "; modo: " << modo << ";\n";
    //std::cout << endereço << std::endl;

    /*
    if( (opcode == "HLT") or (opcode == "NOP") or (opcode == "NOT") or (opcode == "NEG") or (opcode == "SHR") ){ // instrução de 1 byte

      // não há endereço
      modo = 40; // Modo de endereçamento default 40 ?????????????

      if( (opcode == "HLT") or (opcode == "NOP") ){
	// não há registrador 
	registrador = NONE;
	
      } else {
	char reg = line[4];

	if( reg ==  'A' ){
	  registrador = A;
	  
	} else if( reg == 'B' ){
	  registrador = B;
	  
	} else if( reg == 'X' ){
	  registrador = X;
	  
	} else { // NOT do Neander
	  registrador = A; // registrador default

	}
	std::cout << " reg lido: " << reg;

      }

      std::cout << " reg atrib: " << registrador;
      //      this->memoria[i] = strToCode( opcode );
      i++;
      
      
    } else if( (line[4] == 'A') or (line[4] == 'B') or (line[4] == 'X') ){ // intrução de 2 bytes com registrador
      
      char reg = line[4];

	if( reg ==  'A' ){
	  registrador = A;
	  
	} else if( reg == 'B' ){
	  registrador = B;
	  
	} else if( reg == 'X' ){
	  registrador = X;
	  
	}

	std::cout << " reg lido: " << reg;

	std::cout << " reg atrib: " << registrador;

	std::string modoEnd;
	lineStr >> opcode >> std::ws >> reg >> std::ws >> modoEnd >> std::ws; // leia o modoEnd
	std::cout << " modo lido: " << modoEnd;
	
      if( modoEnd[0] == '#' ) { // verifique primeiro char do endereço
	modo = Ime; // modo de endereçamento imediato
	
      } else if( modoEnd[ modoEnd.size() -1 ]  == 'I' ) { // verifique último char do endereço 
	modo = Ind; // modo de endereçamento indireto

      } else if( modoEnd[ modoEnd.size() -1 ]  == 'X' ) { // verifique último char do endereço
	modo = Idx; // modo de endereçamento indexado

      } else {
	modo = Dir; // modo de endereçamento direto

      }

      std::cout << " modo atrib: " << modo;
      
    } 
    
    
    // condificar instrução
    instrucao = opcode*10000 + registrador*100+ modo;

    // salvar na memória
    this->memoria[i] = instrucao;
    this->memoria[i+1] = endereco;
     */
    std::cout << std::endl;
   
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

void Memoria::loadREM( int endereco ){
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


int Memoria::strToCode( const std::string opcode ) {

  if( opcode == "NOP" ){
    return NOP;

  } else if( opcode == "STA" or opcode == "STR" ){
    return STR;

  } else if( opcode == "LDA" or opcode == "LDR" ){
    return LDR;

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
