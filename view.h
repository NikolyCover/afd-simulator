//
// Created by nikoly on 17/01/24.
//

#ifndef AFD_SIMULATOR_VIEW_H
#define AFD_SIMULATOR_VIEW_H

#include "model.h"
#include <stdio.h>

// Mostra todas as informações de um AFD
// Pré-condição: estrutura do tipo AFD preenchida
// Pós-condição: informações mostradas no terminal
void show_afd(AFD afd);

// Pega uma palavra digitada pelo usuário
// Pré-condição: ponteiro de char
// Pós-condição: ponteiro de char preenchido com o que o usuário digitou
void input_word(char * word);

// Mostra um divisor
// Pré-condição: nenhuma
// Pós-condição: um divisor é mostrado no terminal
void print_divider();

// Mostra REJEITA caso result seja 0 e ACEITA caso seja 1
// Pré-condição: número de resultado (1 ou 0)
// Pós-condição: resultado é mostrado
void show_result(int result);

// Mostra uma mensagem em verde
// Pré-condição: mensagem
// Pós-condição: mensagem é mostrada
void show_green_message(char * message);

// Mostra uma mensagem em vermelho
// Pré-condição: mensagem
// Pós-condição: mensagem é mostrada
void show_red_message(char * message);

// Mostra um passo do processamento da mensagem
// Pré-condição: estado inicial e palavra ainda não processada
// Pós-condição: passo mostrado
void show_processing_step(char *curr_state, char * word);

// Mostra cabeçalho do processamento
// Pré-condição: palavra
// Pós-condição: cabeçalho é mostrado
void show_processing_header(char * word);

#endif //AFD_SIMULATOR_VIEW_H
