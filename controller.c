//
// Created by nikoly on 14/01/24.
//
#include "service.h"
#include "model.h"
#include "view.h"
#include <stdio.h>
#include <stdlib.h>

void init_afd(AFD * afd) {
    afd->alphabet_size = 0;
    afd->states_size = 0;
    afd->final_states_size = 0;
    afd->transitions_size = 0;
    afd->alphabet = malloc(sizeof(char *) * MAX_LENGTH);
    afd->states = malloc(sizeof(char *) * MAX_LENGTH);
    afd->final_states = malloc(sizeof(char *) * MAX_LENGTH);
    afd->transitions = NULL;
}

void free_afd(AFD afd) {
    for (int i = 0; i < afd.alphabet_size; i++) {
        free(afd.alphabet[i]);
    }

    for (int i = 0; i < afd.states_size; i++) {
        free(afd.states[i]);
    }

    for (int i = 0; i < afd.final_states_size; i++) {
        free(afd.final_states[i]);
    }

    for (int i = 0; i < afd.transitions_size; i++) {
        free(afd.transitions[i].current_state);
        free(afd.transitions[i].next_state);
    }

    free(afd.alphabet);
    free(afd.states);
    free(afd.final_states);
    free(afd.transitions);
}

void start() {
    AFD afd;
    init_afd(&afd);

    read_afd("afd.txt", &afd);
    show_afd(afd);
    free_afd(afd);
}
