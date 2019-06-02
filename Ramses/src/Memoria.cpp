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
    if(  memoria[i] < 256 and i < 128 and memoria[i] != LIXO ){ // area de instruções: endereço
      std::cout << "Memoria[" << i << "]: " << memoria[i] << std::endl;

    } else if( i < 128 and memoria[i] != LIXO ){ // area de instruções: palavra de instrução
      codeToStr( memoria[i], &opcode, &registrador, &modo);
      std::cout << "Memoria[" << i << "]: " << opcode << ", " << registrador << ", " << modo << std::endl;      

    } else if( memoria[i] != LIXO ){ // area de dados
      std::cout << "Memoria[" << i << "]: " << memoria[i] << std::endl;

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
    } else if( (opcode != "HLT") and (opcode != "NOP") and (opcode != "JMP") and (opcode != "JN") and (opcode != "JZ") and (opcode != "JC")  ){ // verificando se tem registrador default (comandos neander)
      registrador = A;
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
    long int dado;

    getline( dataFile, line );
    std::stringstream lineStr( line ); // string stream para conversão
    
    lineStr >> dado >> std::ws;
    // se o numero for maior que 8 bits (tiver mais que 4 digitos), guarde o byte mais significativo primeiro (guarde os 4 digitos mais significativos primeiro)
    // e o byte menos significativo em seguida (guarde os 4 digitos menos significativos em seguida)
    // obs: estamos simulando uma memória que consegue guardar só 8 bits
    // como um int cabe até 5 digitos, usaremos o limite de 4 digitos
    if( dado/10000 != 0 ){
      //std::cout << "dado: " << dado << " memo l1: " << (int) dado/10000 << " memo l2: " << (int) dado%10000 << std::endl;

      this->memoria[i] = (int) dado/10000; // 8 digitos mais significativos 
      this->memoria[i+1] = (int) dado%10000; // 8 digitos menos significativos
      //std::cout << "\n\ni: " << i << " memo li: " << this->memoria[i] << " memo li+1: " << this->memoria[i+1] << std::endl;
	// ande na memória
	i+=2;

    } else{ 
      this->memoria[i] = (int) dado; // numéro de até 8 digitos

      // ande na memória
      i++;
    }
    //std::cout << "i: " << i << std::endl;
  }

  dataFile.close();


  /*
  //Principio da simulação feita:
  // Na memória só cabe um número de 2 digitos e quero poder somar númerode de até 4 digitos
  dado1 = 160;
  [128] 1
  [129] 60

  dado2 = 260;
  [130] 2
  [131] 60

  // LDR A 129
  // ADD A 131

  60 + 60 = 120;
  carry = 1

  // STR A 133
  [133] 20

  // LDR A #1
  // JC 12
  // LDR A #0
  // fez o load do carry 1 e pulou para o add

  // ADD A 128
  1 + 1 = 2
	
  // ADD A 130
  2 + 2 = 4

  // STR A 132
  [132] 4

  // resultado
  [132] 4
  [133] 20
  // 420!! :)

  /////////////////
  dado1 = 1001
  [128] 10
  [129] 01 // 9

  dado2 = 111;
  [130] 01
  [131] 10  // 6
	
  10 + 01 = 11
  [133] 00

  C=1

  10 + 01 = 11
  11 + 01 = 00
  [132] 00

  10000 // 16

  */

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
