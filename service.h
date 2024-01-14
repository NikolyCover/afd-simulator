//
// Created by nikoly on 14/01/24.
//

#ifndef AFD_SIMULATOR_SERVICE_H
#define AFD_SIMULATOR_SERVICE_H
#include "model.h"

void read_afd(const char * filename, char * alphabet, char ** states, char *** final_states, Transition ** transitions, int * qtd_states);

#endif //AFD_SIMULATOR_SERVICE_H
