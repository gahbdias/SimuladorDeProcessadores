/**
 * @file ParteControle.h
 * @authors Karine Piacentini Coelho, Gabriela Carvalho Dias.
 * @brief  Simulador de modelos Parte de Controle (PC) - Parte Operativa (PO)
 * @version 1.00
 * @date 06-04-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _ParteControle_H_
#define _ParteControle_H_
#include <iostream>
#include "ParteOperativa.h"


class ParteControle {

    public:
        int atual; // estado atual
        int proximo; // proximo estado
        int clock_; // representa uma abstração de clock; é do tipo clock?????????????
        ParteOperativa PO;
	bool fim; // fim da execução


    public:
        ParteControle ( );
        ~ParteControle(void) = default;

        int fte( int atual ); // função de transição de estados
        void fs ( int atual ); // função de saída

};


#endif
