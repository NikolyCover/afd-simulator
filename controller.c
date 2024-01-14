//
// Created by nikoly on 14/01/24.
//
#include "service.h"
#include "model.h"
#include <stdio.h>
#include <stdlib.h>

void start() {
    char alphabet[MAX_LENGTH];
    char states[MAX_LENGTH][MAX_STRING_LENGTH];
    char final_states[MAX_LENGTH][MAX_STRING_LENGTH];
    Transition * transitions = NULL;//malloc(sizeof(Transition) * MAX_LENGTH);
    int qtd_states;

    read_afd("afd.txt", alphabet, states, final_states, transitions, &qtd_states);
    printf(alphabet);
    printf("\nqtd: %d", qtd_states);
    //printf("%s", states);

    free(transitions);
}
