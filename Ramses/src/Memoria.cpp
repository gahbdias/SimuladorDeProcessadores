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

  std::string opcode;
  std::string registrador;
  std::string modo;

  std::cout << "RDM: " << rdm << std::endl;
  std::cout << "REM: " << rem << std::endl;

  for( int i=0; i<256; i++ ){
    if( memoria[i] != LIXO and memoria[i] < 256 ){
      std::cout << "Memoria[" << i << "]: " << memoria[i] << std::endl;
    } else if( memoria[i] != LIXO ){
      codeToStr( memoria[i], &opcode, &registrador, &modo);
      std::cout << "Memoria[" << i << "]: " << opcode << ", " << registrador << ", " << modo << std::endl;
    }
  }
}

void Memoria::codeToStr( int instrucao, std::string* opcode, std::string* registrador, std::string* modo) {
  int codigo[3];
  std::stringstream ss;
  int aux;

  std::string opcodeString[23]{ "NOP", "STR", "LDR", "ADD", "OR", "AND", "SUB", "NOT", "JMP", "JN", "JZ", "JC", "JSR", "NEG", "SHR", "HLT"};
  std::string modoString[4]{ "DIRETO", "INDIRETO", "IMEDIATO", "INDEXADO" };
  std::string registradorString[4]{ "A", "B", "X", "NONE" };

  for ( int i=0; i<3; i++ ){
    aux = instrucao%100;
    codigo[i] = aux;
    instrucao = ( instrucao - aux )/100;
  }

  *opcode = opcodeString[ codigo[2]-10 ];

  *registrador = registradorString[ codigo[1]-30 ];

  *modo = modoString[ codigo[0]-40 ];
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
    std::string end;

    bool temEnd = false;

    int registrador = NONE;
    int modo = DIRETO;
    int endereco;
    int instrucao;

    getline( algorithmFile, line );   
    
    // verificando opcode
    char ws = ' ';
    char comma = ',';
    auto nchar = 0u;
    while( line[nchar] != ws && nchar < line.size() ){
      opcode.push_back( line[nchar] );
      nchar++;      
    }
    nchar++; // pule caracter em branco

    // verificando se há registrador
    if( ( line[nchar] == 'A' || line[nchar] == 'B' || line[nchar] == 'X' ) && nchar < line.size() ){
      // atribua registrador especificado
      registrador = ( line[nchar] == 'A') ? A : (line[nchar] == 'B' ) ? B : X;    
      nchar++;
      
      nchar++; // pule caracter em branco
    }

    // verificando se há modo de endereçamento
    if( line[nchar] == '#'  && nchar < line.size() ) {
      modo = IMEDIATO; // modo de endereçamento imediato
      nchar++;
      
    } else if( line[ line.size() -1 ] == 'I'  && nchar < line.size() ) {
      modo = INDIRETO; // modo de endereçamento indireto
 
    } else if( line[ line.size() - 1 ] == 'X'  && nchar < line.size() ) {
      modo = INDEXADO; // modo de endereçamento indexado
 
    } 

    while( (line[nchar] != comma) and (line[nchar] != ws) and (nchar < line.size()) ) {
      end.push_back( line[nchar] );
      nchar++; 

      temEnd = true;
    }
    
    // condificar instrução
    instrucao = strToCode( opcode )*10000 + registrador*100 + modo;

    // salvar na memória
    this->memoria[i] = instrucao;
    i++;

    if( temEnd ){
      std::stringstream str( end ); // string stream para conversão
      str >> endereco;
      this->memoria[i] = endereco;
      i++;
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
  std::cout << std::endl;

  i=128;
  while( !dataFile.eof() and i < 256 ){
    int dado;

    getline( dataFile, line );
    std::stringstream lineStr( line ); // string stream para conversão
    
    lineStr >> dado >> std::ws;
    this->memoria[i] = dado;
    
    i++;
  }

  dataFile.close();
}

void Memoria::loadREM( int endereco ){
  rem = endereco;
}

void Memoria::loadRDM( void ){ // leitura da memoria ~ endereço de REM, dado para RDM
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

  } else if( opcode == "SUB" ){
    return SUB;

  } else if( opcode == "NOT" ){
    return NOT;

  } else if( opcode == "JMP" ){
    return JMP;

  } else if( opcode == "JN" ){
    return JN;

  } else if( opcode == "JZ" ){
    return JZ;

  } else if( opcode == "JC" ){
    return JC;

  } else if( opcode == "JSR" ){
    return JSR;

  } else if( opcode == "NEG" ){
    return NEG;

  } else if( opcode == "SHR" ){
    return SHR;

  } else if( opcode == "HLT" ){
    return HLT;
    
  } else {
    std::cout << "Erro em strToCode: codigo inválido. " << std::endl; 
    return -1;
  }
}
