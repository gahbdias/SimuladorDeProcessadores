/**
 * @file UnidadeControle.cpp
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador do Neander
 * @version 1.00
 * @date Jun-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "../include/UnidadeControle.h"
#include "../include/ParteOperativa.h"
#include "../include/ULA.h"
#include "../include/RI.h"

#include <thread>
#include <chrono>
#include <iostream>

UnidadeControle::UnidadeControle ( ) {
	this->atual = 1; // começa no estado 0
	this->proximo = 0; // será definido posteriormente (apenas para não ser inicializado com lixo)
	this->clock_ = 0; // tempo 0 ???????????????
	this->fim=false; // controlado pelo HLT
}


int UnidadeControle::fte( int atual ){ // Função de Transição de Estados ~ define qual será o próximo estado

  switch( atual ){

    case 1:
      proximo = 2;
    
    break;

    case 2:
     
      if( opcode == NOP ){
        proximo = 1;

      }
      else if( (opcode == STA) or (opcode == LDA) or (opcode == ADD) or (opcode == OR) or (opcode == AND) ) { 
        proximo = 3;

      } else if( opcode == NOT ) { 
        proximo = 10;
      }
      else if( (opcode == JMP) or ( (opcode == JN) and (PO.ULA.N == true) ) or ( (opcode == JZ) and (PO.ULA.Z == true) ) ) { 
        proximo = 11;

      } else if( ( (opcode == JN) and (PO.ULA.N == false) ) or ( (opcode == JZ) and (PO.ULA.Z == false) ) ) { 
        proximo = 12;

      } else if( opcode == HLT ) { 
        fim = true;

      } else {
        // erro
        std::cout << "OPCODE inválido." << std::endl;
      }

    break;

    case 3:

      if( opcode == STA ) {
        proximo = 4;

      } else if(opcode == LDA) {
        proximo = 6;

      } else if( (opcode == ADD) or (opcode == OR) or (opcode == AND) ) {
        proximo = 8;

      } else {
        std::cout << "OPCODE inválido." << std::endl;
      }

    break;

    case 4:
      proximo = 5;
    
    break;

    case 5:
      proximo = 1;
    
    break;

    case 6:
      proximo = 7;
    
    break;

    case 7:
      proximo = 1;
    
    break;

    case 8:
      proximo = 9;
    
    break;

    case 9:	
      proximo = 1;
    
    break;

    case 10:
      proximo = 1;
    
    break;

    case 11:
      proximo = 1;
    
    break;

    case 12:
      proximo = 1;
    
    break;

    case 13:
      proximo = 1;
    
    break;

    default: std::cout << "\n### Entrada inválida fte ###" << std::endl;
  }

  return proximo;
}

void UnidadeControle::fs ( int atual ) { // Função de saída ~ recebe o estado atual e controla as operações (chama as funções da PO)

  double valor;

  std::cout << std::endl;
  std::cout << "Clocks decorridos:" << clock_ << std::endl;


  switch(atual){

  case 1: // Busca: LPC; M0(0); LREM; R/W(0); IPC; LRDM;
    std::cout << "### ESTADO 1 ###" << std::endl;
    PO.M.loadREM( PO.PC.leituraAtual );
    PO.M.loadRDM();
    PO.PC.incrementarPC();

    break;

  case 2: // Decodificação: LRI; Decodificação; 
    std::cout << "### ESTADO 2 ###" << std::endl;
    PO.RI.loadRI( PO.M.rdm );
    
    break;

  case 3: // Instruções de transferência de dados:  LPC; M0(0); LREM; R/W(0); IPC; LRDM;
    std::cout << "### ESTADO 3 ###" << std::endl;
    PO.M.loadREM( PO.PC.leituraAtual );
    PO.M.loadRDM();
    PO.PC.incrementarPC();
    
    break;

  case 4: // STA: M0(1); LREM; LRDM(lê acumulador);
    std::cout << "### ESTADO 4 ###" << std::endl;
    PO.M.loadREM( PO.M.rdm );
    PO.M.loadRDM( PO.AC.x ); 
       
    break;

  case 5: // STA: R/W(1); (escreve dado no rdm no endereço do rem)
    std::cout << "### ESTADO 5 ###" << std::endl;
    PO.M.escreverRegistro();
      
    break;

  case 6: // LDA:  M0(1); LREM; R/W(0); LRDM;
    std::cout << "### ESTADO 6 ###" << std::endl;
    PO.M.loadREM( PO.M.rdm );
    PO.M.loadRDM();
    
    break;

  case 7: // LDA: M1(1); LAC; (atualiza N e Z)
    std::cout << "### ESTADO 7 ###" << std::endl;
    PO.AC.loadAC( PO.M.rdm );
    
    break;

  case 8: // ULA: M0(1); LREM; R/W(0); LRDM;
    std::cout << "### ESTADO 8 ###" << std::endl;
    PO.M.loadREM( PO.M.rdm );
    PO.M.loadRDM();
		
    break;

  case 9: // ULA: SULA(op); (atualiza N e Z); M1(0); LAC;
    std::cout << "### ESTADO 9 ###" << std::endl;
    PO.AC.loadAC( PC.ULA.executarOperacao( PC.AC.x, PC.M.rdm, PO.RI.opcode ) );
			
    break;

  case 10: // NEGAÇÃO: ULA(NOT); M1(0); LAC; (atualiza N e Z)
    std::cout << "### ESTADO 10 ###" << std::endl;
		PO.AC.loadAC( PC.ULA.executarOperacao( PC.AC.x ) );
    // ### CONFERIR COMO FAREMOS NEGAÇÃO ###

    break;

  case 11: // JUMP, JN && N=1, JZ && Z=1: LPC; M0(0); LREM; R/W(0); LRDM; LPC;
    std::cout << "### ESTADO 11 ###" << std::endl;
    PO.M.loadREM( PO.PC.leituraAtual );
    PO.M.loadRDM();
    // ### CONFERIR ESTE ESTADO ###

    break;

  case 12: // JN && N=0, JZ && Z=0: IPC
    std::cout << "### ESTADO 12 ###" << std::endl;
    PO.PC.incrementarPC();
			
    break;

  default: std::cout << "\n### Entrada inválida fs ###" << std::endl;

  }
  std::cout << std::endl;

}

