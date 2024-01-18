//
// Created by nikoly on 17/01/24.
//
#include "view.h"

// Mostra um divisor
// Pré-condição: nenhuma
// Pós-condição: um divisor é mostrado no terminal
void print_divider() {
    printf("\n--------------------------------------------------\n\n");
}

// Mostra todas as informações de um AFD
// Pré-condição: estrutura do tipo AFD preenchida
// Pós-condição: informações mostradas no terminal
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

// Pega uma palavra digitada pelo usuário
// Pré-condição: ponteiro de char
// Pós-condição: ponteiro de char preenchido com o que o usuário digitou
void input_word(char * word) {
    printf("Digite uma palavra para ser testada (ou 'sair' para sair do sistema): ");
    scanf("%s", word);
}

// Mostra uma mensagem em verde
// Pré-condição: mensagem
// Pós-condição: mensagem é mostrada
void show_green_message(char * message) {
    printf("\033[1;32m");

    printf(message);

    printf("\033[0m");
}

// Mostra uma mensagem em vermelho
// Pré-condição: mensagem
// Pós-condição: mensagem é mostrada
void show_red_message(char * message) {
    printf("\033[1;31m");

    printf(message);

    printf("\033[0m");
}

// Mostra REJEITA caso result seja 0 e ACEITA caso seja 1
// Pré-condição: número de resultado (1 ou 0)
// Pós-condição: resultado é mostrado
void show_result(int result) {
    if(result) {
        show_green_message("ACEITA\n");
    } else {
        show_red_message("REJEITA\n");
    }
}

// Mostra um passo do processamento da mensagem
// Pré-condição: estado inicial e palavra ainda não processada
// Pós-condição: passo mostrado
void show_processing_step(char *curr_state, char * word) {
    printf("[%s]%s\n", curr_state, word);
}

// Mostra cabeçalho do processamento
// Pré-condição: palavra
// Pós-condição: cabeçalho é mostrado
void show_processing_header(char * word) {
    printf("\nProcessamento de '%s':\n", word);
}