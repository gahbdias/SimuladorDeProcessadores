/**
 * @file UnidadeControle.h
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador do Neander
 * @version 1.00
 * @date Jun-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _UnidadeControle_H_
#define _UnidadeControle_H_
#include <iostream>
#include <thread>
#include <chrono>

#include "ParteOperativa.h"
#include "Relogio.h"

class UnidadeControle {

    public:
       int atual; // estado atual
       int proximo; // proximo estado
       Relogio relogio; // clock da unidade de controle
       ParteOperativa PO;
       bool fim; // fim da execução


    public:
        UnidadeControle ();
        ~UnidadeControle( void ) = default;

        int fte( int atual ); // função de transição de estados
        void fs ( int atual ); // função de saída
        void imprimeEstado( void );

};


#endif
