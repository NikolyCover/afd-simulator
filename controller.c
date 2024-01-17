//
// Created by nikoly on 14/01/24.
//
#include "service.h"
#include "model.h"
#include <stdio.h>
#include <stdlib.h>

void start() {
    char * alphabet[MAX_LENGTH];
    char * states[MAX_LENGTH];
    char * final_states[MAX_LENGTH];
    Transition * transitions = NULL;//malloc(sizeof(Transition) * MAX_LENGTH);
    int alphabet_size = 0, states_size = 0, final_states_size = 0, transitions_size = 0;

    read_afd("afd.txt", alphabet, states, final_states, &transitions, &alphabet_size, &states_size, &final_states_size, &transitions_size);

    printf("\nAlfabeto: ");
    for (int i = 0; i < alphabet_size; i++) {
        printf("%s ", alphabet[i]);
    }

    printf("\nEstados: ");
    for (int i = 0; i < states_size; i++) {
        printf("%s ", states[i]);
    }

    printf("\nFinais: ");
    for (int i = 0; i < final_states_size; i++) {
        printf("%s ", final_states[i]);
    }

    printf("\nTransições: %d\n", transitions_size);
    for (int i = 0; i < transitions_size; i++) {
        printf("(%s, %c) = %s\n", transitions[i].current_state, transitions[i].symbol, transitions[i].next_state);
    }

    for (int i = 0; i < transitions_size; i++) {
        free(transitions[i].current_state);
        free(transitions[i].next_state);
    }

    free(transitions);
}
