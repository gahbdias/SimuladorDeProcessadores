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
     
      if( PO.RI.opcode == NOP ){
        proximo = 1;

      }
      else if( (PO.RI.opcode == STA) or (PO.RI.opcode == LDA) or (PO.RI.opcode == ADD) or (PO.RI.opcode == OR) or (PO.RI.opcode == AND) ) { 
        proximo = 3;

      } else if( PO.RI.opcode == NOT ) { 
        proximo = 10;
      }
      else if( (PO.RI.opcode == JMP) or ( (PO.RI.opcode == JN) and (PO.ULA.N == true) ) or ( (PO.RI.opcode == JZ) and (PO.ULA.Z == true) ) ) { 
        proximo = 11;

      } else if( ( (PO.RI.opcode == JN) and (PO.ULA.N == false) ) or ( (PO.RI.opcode == JZ) and (PO.ULA.Z == false) ) ) { 
        proximo = 12;

      } else if( PO.RI.opcode == HLT ) { 
        fim = true;

      } else {
        // erro
        std::cout << "PO.RI.OPCODE inválido." << std::endl;
      }

    break;

    case 3:

      if( PO.RI.opcode == STA ) {
        proximo = 4;

      } else if(PO.RI.opcode == LDA) {
        proximo = 6;

      } else if( (PO.RI.opcode == ADD) or (PO.RI.opcode == OR) or (PO.RI.opcode == AND) ) {
        proximo = 8;

      } else {
        std::cout << "PO.RI.OPCODE inválido." << std::endl;
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

    default: std::cout << "\n### Entrada inválida fte ###" << std::endl;
  }

  return proximo;
}

void UnidadeControle::fs ( int atual ) { // Função de saída ~ recebe o estado atual e controla as operações (chama as funções da PO)

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
    PO.AC.loadAC( PO.ULA.executarOperacao( PO.AC.x, PO.M.rdm, PO.RI.opcode ) );
			
    break;

  case 10: // NEGAÇÃO: ULA(NOT); M1(0); LAC; (atualiza N e Z)
    std::cout << "### ESTADO 10 ###" << std::endl;
		PO.AC.loadAC( PO.ULA.executarOperacao( PO.AC.x ) );

    break;

  case 11: // JUMP, JN && N=1, JZ && Z=1: LPC; M0(0); LREM; R/W(0); LRDM; LPC;
    std::cout << "### ESTADO 11 ###" << std::endl;
    PO.M.loadREM( PO.PC.leituraAtual );
    PO.M.loadRDM();
    PO.PC.loadPC( PO.M.rdm ); // Go to endereço contido no RDM

    break;

  case 12: // JN && N=0, JZ && Z=0: IPC
    std::cout << "### ESTADO 12 ###" << std::endl;
    PO.PC.incrementarPC();
			
    break;

  default: std::cout << "\n### Entrada inválida fs ###" << std::endl;

  }

  std::cout << std::endl;

}

