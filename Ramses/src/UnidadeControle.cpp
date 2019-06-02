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

UnidadeControle::UnidadeControle ( void ) {
	this->atual = 1; // começa no estado 0
	this->proximo = 0; // será definido posteriormente (apenas para não ser inicializado com lixo)
	this->fim=false; // controlado pelo HLT
}

void UnidadeControle::imprimeEstado( void ){
  PO.PC.imprimePC();
  PO.RI.imprimeRI();
  PO.ULA.imprimeNZC();
  PO.BR.RA.imprimeRA();
  PO.BR.RB.imprimeRB();
  PO.BR.RX.imprimeRX();
  PO.M.imprimeDados();
  relogio.imprimeClock();
  std::cout << "################" << std::endl;
  std::cout << std::endl;
}


int UnidadeControle::fte( int atual ){ // Função de Transição de Estados ~ define qual será o próximo estado

  bool isUla = ( ( PO.RI.opcode == ADD ) or 
                 ( PO.RI.opcode == SUB ) or
                 ( PO.RI.opcode == AND ) or
                 ( PO.RI.opcode == OR  ) );

  switch( atual ){

    case 1:
      proximo = 2;
    
    break;

    case 2:
     
      if ( ( PO.RI.opcode == NOT ) or ( PO.RI.opcode == NEG ) or ( PO.RI.opcode == SHR ) ){
        proximo = 13;
      } else if ( ( PO.RI.opcode == JN and PO.ULA.N == false ) or 
                  ( PO.RI.opcode == JZ and PO.ULA.Z == false ) or 
                  ( PO.RI.opcode == JC and PO.ULA.C == false ) ) { 
        proximo = 16;
      } else if ( ( PO.RI.modo == IMEDIATO ) and 
                  ( ( PO.RI.opcode == JN and PO.ULA.N == true ) or 
                    ( PO.RI.opcode == JZ and PO.ULA.Z == true ) or 
                    ( PO.RI.opcode == JC and PO.ULA.C == true ) or 
                    ( PO.RI.opcode == JSR ) or
                    ( PO.RI.opcode == JMP ) ) ) { 
        proximo = 16;
      } else if ( ( PO.RI.opcode == JN and PO.ULA.N == true ) or 
                  ( PO.RI.opcode == JZ and PO.ULA.Z == true ) or 
                  ( PO.RI.opcode == JC and PO.ULA.C == true ) or 
                  ( PO.RI.opcode == JMP ) ) {
        proximo = 14;
      } else if ( PO.RI.opcode == NOP ) { 
        proximo = 1;
      } else if ( PO.RI.opcode == HLT ) { 
        fim = true;
      } else {
        proximo = 3;
      }

    break;

    case 3:
      if ( ( PO.RI.modo == IMEDIATO ) and ( PO.RI.opcode == LDR ) ){
        proximo = 10;
      } else if ( ( PO.RI.modo == IMEDIATO ) and ( isUla ) ) {
        proximo = 12;
      } else if ( PO.RI.modo == INDIRETO ) {
        proximo = 7;
      } else if ( ( PO.RI.modo == DIRETO ) and 
                  ( ( PO.RI.opcode == LDR ) or ( isUla ) ) ) {
        proximo = 7;
      } else if ( ( PO.RI.modo == INDEXADO ) and 
                  ( ( PO.RI.opcode == STR ) or 
                    ( PO.RI.opcode == LDR ) or 
                    ( isUla ) ) ) {
        proximo = 9;
      } else if ( ( PO.RI.modo == IMEDIATO ) and ( PO.RI.opcode == STR ) ) {
        proximo = 8;
      } else if ( ( PO.RI.modo == DIRETO ) and ( PO.RI.opcode == STR ) ) {
        proximo = 4;
      } else if ( ( PO.RI.modo == DIRETO ) and  ( PO.RI.opcode == JSR ) ) {
        proximo = 18;
      } else if ( ( PO.RI.modo == INDEXADO ) and  ( PO.RI.opcode == JSR ) ) {
        proximo = 22;
      } else if ( ( PO.RI.opcode == JN and PO.ULA.N == true ) or 
                  ( PO.RI.opcode == JZ and PO.ULA.Z == true ) or 
                  ( PO.RI.opcode == JC and PO.ULA.C == true ) or
                  ( PO.RI.opcode == JMP) ) { 
        proximo = 15;
      }

    break;

    case 4:
      proximo = 5;
    
    break;

    case 5:
      proximo = 6;
    
    break;

    case 6:
      proximo = 1;
    
    break;

    case 7:

      if ( ( PO.RI.modo == DIRETO ) and ( isUla ) ) {
        proximo = 12;
      } else if ( ( PO.RI.modo == DIRETO ) and ( PO.RI.opcode == LDR ) ){
        proximo = 10;
      } else if ( PO.RI.opcode == JSR ){
        proximo = 18;
      } else if ( PO.RI.opcode == STR ){
        proximo = 4;
      }  else if ( PO.RI.opcode == LDR or isUla ) {
        proximo = 23;
      }

    break;

    case 8:
      proximo = 5;
    
    break;

    case 9:	
      if ( PO.RI.opcode == STR ) {
        proximo = 5;
      } else if ( PO.RI.opcode == LDR or isUla ){
        proximo = 11;
      }
    
    break;

    case 10:
      proximo = 1;
    
    break;

    case 11:
      if ( PO.RI.opcode == LDR ) {
        proximo = 10;
      } else if ( isUla ) {
        proximo = 12;
      }
    
    break;

    case 12:
      proximo = 1;
    
    break;

    case 13:
      proximo = 1;
    
    break;

    case 14:
      if( PO.RI.modo == DIRETO ){
        proximo = 15;
      } else if( PO.RI.modo == INDIRETO ) {
        proximo = 7;
      } else if( PO.RI.modo == INDEXADO ) {
        proximo = 17;
      }
    
    break;

    case 15:
      proximo = 1;
    
    break;

    case 16:
      proximo = 1;
    
    break;

    case 17:
      proximo = 1;
    
    break;

    case 18:
      proximo = 19;
    
    break;

    case 19:
      proximo = 20;
    
    break;

    case 20:
      proximo = 21;
    
    break;

    case 21:
      proximo = 1;
    
    break;

    case 22:
      proximo = 19;
    
    break;

    case 23:
      if ( PO.RI.opcode == LDR ){
        proximo = 10;
      } else if ( isUla ){
        proximo = 12;
      }
    
    break;

    default: std::cout << "\n### Entrada inválida fte ###" << std::endl;
  }

  return proximo;
}

void UnidadeControle::fs ( int atual ) { // Função de saída ~ recebe o estado atual e controla as operações (chama as funções da PO)

  switch( atual ){

  case 1: // Busca: M0(0); LREM; R/W(0); IPC; LRDM;
    std::cout << "### ESTADO 1 ###" << std::endl;
    PO.M.loadREM( PO.PC.leituraAtual );
    PO.M.loadRDM();
    PO.PC.incrementarPC();
    relogio.clockMemoria();

    break;

  case 2: // Decodificação: LRI; Decodificação; 
    std::cout << "### ESTADO 2 ###" << std::endl;
    PO.RI.loadRI( PO.M.rdm );
    relogio.clockLA();
    
    break;

  case 3: // Instruções de transferência de dados: M0(0); LREM; R/W(0); IPC; LRDM;
    std::cout << "### ESTADO 3 ###" << std::endl;
    PO.M.loadREM( PO.PC.leituraAtual );
    PO.M.loadRDM();
    PO.PC.incrementarPC();
    relogio.clockMemoria();
    
    break;

  case 4: // STR: M0(2); LREM; - direto
    std::cout << "### ESTADO 4 ###" << std::endl;
    PO.M.loadREM( PO.M.rdm );
    relogio.clockLA();
       
    break;

  case 5: // STR: M2(r); M3(0); LRDM(lê r); - direto
    std::cout << "### ESTADO 5 ###" << std::endl;
    if( PO.RI.registrador == A ){
      PO.M.loadRDM( PO.BR.RA.A );
    } else if( PO.RI.registrador == B ){
      PO.M.loadRDM( PO.BR.RB.B );
    } else if ( PO.RI.registrador == X ){
      PO.M.loadRDM( PO.BR.RX.X );
    }
    relogio.clockLA();

    break;

  case 6: // STR: R/W(1); (escreve dado no rdm no endereço do rem) - direto
    std::cout << "### ESTADO 6 ###" << std::endl;
    PO.M.escreverRegistro();
    relogio.clockMemoria();
      
    break;

  case 7: // STR:  M0(2); LREM; R/W(0); LRDM; - indireto
    std::cout << "### ESTADO 7 ###" << std::endl;
    PO.M.loadREM( PO.M.rdm );
    PO.M.loadRDM();
    relogio.clockMemoria();
    
    break;

  case 8: // STR: M0(0); LREM; IPC; - imediato 
    std::cout << "### ESTADO 8 ###" << std::endl;
    PO.M.loadREM( PO.PC.leituraAtual );
    PO.PC.incrementarPC();
    relogio.clockLA();

    break;

  case 9: // STR: SUM; M0(1); LREM [da SUM]; [soma de ponteiros] - indexado
    std::cout << "### ESTADO 9 ###" << std::endl;
    PO.M.loadREM( PO.SUM.somarIndice( PO.BR.RX, PO.M.rdm ) );
    relogio.clockLA();
		
    break;

    
  case 10: // LDR: 
    std::cout << "### ESTADO 10 ###" << std::endl;

    break;

//////////////////////////

  case 19999: // NEGAÇÃO: ULA(NOT); M1(0); LAC; (atualiza N e Z)
    std::cout << "### ESTADO 10 ###" << std::endl;

    break;

  case 11: // JUMP, JN && N=1, JZ && Z=1: LPC; M0(0); LREM; R/W(0); LRDM; LPC;
    std::cout << "### ESTADO 11 ###" << std::endl;
    PO.M.loadREM( PO.PC.leituraAtual );
    PO.M.loadRDM();
    PO.PC.loadPC( PO.M.rdm ); // Go to endereço contido no RDM

    break;

  case 12: // INSTRUÇÕES LA: M2(r); SULA(op); (atualiza N e Z no caso AND/OR e C no caso ADD/SUB); Lr;
   // DIRETO
   if( PO.RI.registrador == A ){
      PO.BR.RA.loadRA( PO.ULA.executarOperacao( PO.BR.RA.A, PO.M.rdm, PO.RI.opcode ) );
    } else if( PO.RI.registrador == B ){
      PO.BR.RB.loadRB( PO.ULA.executarOperacao( PO.BR.RB.B, PO.M.rdm, PO.RI.opcode ) );
    } else if ( PO.RI.registrador == X ){
      PO.BR.RX.loadRX( PO.ULA.executarOperacao( PO.BR.RX.X, PO.M.rdm, PO.RI.opcode ) );
    }     

    break;

    case 14: // INSTRUÇÕES DESVIO: M0(0); LREM; R/W(0); LRDM; M1(0); LPC;  // DIRETO
      PO.M.loadREM( PO.PC.leituraAtual );
      PO.M.loadRDM( PO.M.rem );

    break;

    case 999999914: // INSTRUÇÕES DESVIO: M0(0); LREM; R/W(0); LRDM; M1(0); LPC;  // DIRETO
      PO.M.loadREM( PO.PC.leituraAtual );
      PO.M.loadRDM(); // leitura da memoria

    break;

  default: std::cout << "\n### Entrada inválida fs ###" << std::endl;

  }

  imprimeEstado();

  std::cout << std::endl;

}

