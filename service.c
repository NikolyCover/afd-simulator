//
// Created by nikoly on 14/01/24.
//

#include "model.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

void getData(char *line, char **array, int *size) {
    char *start = strchr(line, '{');
    char *end = strchr(line, '}');

    if (start != NULL && end != NULL) {
        start++;  // Pular o '{'
        *end = '\0';  // Substituir '}' por '\0' para terminar a string no local certo

        char *token = strtok(start, ",");
        while (token != NULL) {
            if (strcmp(token, "")) {
                array[*size] = strdup(token); // strdup cria uma cópia independente da string line
                (*size)++;
            }
            token = strtok(NULL, ",");
        }
    }
}

void read_afd(const char * filename, char ** alphabet, char ** states, char ** final_states, Transition ** transitions, int * alphabet_size, int * states_size, int * final_states_size, int * transitions_size) {
    FILE * file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }
    char line[MAX_LENGTH];

    while (fgets(line, MAX_LENGTH, file) != NULL) {
        if (strstr(line, "alfabeto") != NULL) {
            getData(line, alphabet, alphabet_size);
        } else if (strstr(line, "estados") != NULL) {
            getData(line, states, states_size);
        } else if (strstr(line, "finais") != NULL) {
            getData(line, final_states, final_states_size);
        }
        else {
            // Linha de transição
            if (*transitions_size == 0) {
                *transitions = malloc(sizeof(Transition));
            } else {
                *transitions = realloc(*transitions, (*transitions_size + 1) * sizeof(Transition));
            }

            char current_state[MAX_STRING_LENGTH], next_state[MAX_STRING_LENGTH];
            char symbol;
            sscanf(line, "(%[^,],%c)= %s", current_state, &symbol, next_state);

            (*transitions)[*transitions_size].current_state = strdup(current_state);
            (*transitions)[*transitions_size].symbol = symbol;
            (*transitions)[*transitions_size].next_state = strdup(next_state);
            (*transitions_size)++;
        }
    }

    fclose(file);
}