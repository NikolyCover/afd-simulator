//
// Created by nikoly on 17/01/24.
//
#include "view.h"

void show_afd(AFD afd) {
    printf("\nAlfabeto: ");
    for (int i = 0; i < afd.alphabet_size; i++) {
        printf("%s ", afd.alphabet[i]);
    }

    printf("\nEstados: ");
    for (int i = 0; i < afd.states_size; i++) {
        printf("%s ", afd.states[i]);
    }

    printf("\nFinais: ");
    for (int i = 0; i < afd.final_states_size; i++) {
        printf("%s ", afd.final_states[i]);
    }

    printf("\nTransições:\n");
    for (int i = 0; i < afd.transitions_size; i++) {
        printf("(%s, %c) = %s\n", afd.transitions[i].current_state, afd.transitions[i].symbol, afd.transitions[i].next_state);
    }
}