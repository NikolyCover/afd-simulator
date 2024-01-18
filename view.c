//
// Created by nikoly on 17/01/24.
//
#include "view.h"

void print_divider() {
    printf("\n--------------------------------------------------\n\n");
}

void show_afd(AFD afd) {
    printf("------------------ AFD SIMULATOR ------------------\n");
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

    print_divider();
}

void input_word(char * word) {
    printf("Digite uma palavra para ser testada (ou 'sair' para sair do sistema): ");
    scanf("%s", word);
}

void show_green_message(char * message) {
    printf("\033[1;32m");

    printf(message);

    printf("\033[0m");
}

void show_red_message(char * message) {
    printf("\033[1;31m");

    printf(message);

    printf("\033[0m");
}


void show_result(int result) {
    if(result) {
        show_green_message("ACEITA\n");
    } else {
        show_red_message("REJEITA\n");
    }
}

void show_processing_step(char *curr_state, char * word) {
    printf("[%s]%s\n", curr_state, word);
}

void break_line() {
    printf("\n");
}

void show_processing_header(char * word) {
    printf("\nProcessamento de '%s':\n", word);
}