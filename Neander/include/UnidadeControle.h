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
#include "ParteOperativa.h"


class UnidadeControle {

    public:
        int atual; // estado atual
        int proximo; // proximo estado
        int clock_; // representa uma abstração de clock; é do tipo clock?????????????
        ParteOperativa PO;
	bool fim; // fim da execução


    public:
        UnidadeControle ( );
        ~UnidadeControle(void) = default;

        int fte( int atual ); // função de transição de estados
        void fs ( int atual ); // função de saída

};


#endif
