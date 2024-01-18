//
// Created by nikoly on 14/01/24.
//

#ifndef AFD_SIMULATOR_CONTROLLER_H
#define AFD_SIMULATOR_CONTROLLER_H

#include "service.h"
#include "model.h"
#include "view.h"
#include <stdlib.h>
#include <string.h>

// Inicia aplicação
// Pré-condição: nenhuma
// Pós-condição: aplicação finalizada
void start();

// Inicia simulador
// Pré-condição: afd preenchido
// Pós-condição: aplicação finalizada
void run_simulator(AFD afd);

// Valida uma palavra com um AFD
// Pré-condição: palavra e afd
// Pós-condição: palavra validada
int validate_word(char * word, AFD afd);

// Libera espaçp alocado em um AFD
// Pré-condição: afd
// Pós-condição: espaço liberado
void free_afd(AFD afd);

// Diz se um estado é final
// Pré-condição: estado e afd
// Pós-condição: diz se é estado final
int is_final_state(char * state, AFD afd);

// Inicia AFD
// Pré-condição: afd alocado
// Pós-condição: afd preenchido
void init_afd(AFD * afd);

#endif //AFD_SIMULATOR_CONTROLLER_H
