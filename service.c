//
// Created by nikoly on 14/01/24.
//

#include "model.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

// Pega os dados (estados/alfabeto) de uma cadeia de caracteres (linha)
// Pré-condição: linha, array a ser preenchido com os dados e tamanho do array a ser preenchido
// Pós-condição: dados extraídos da linha no array e tamanho do array preenchido
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

// Lê AFD de um arquivo
// Pré-condição: nome do arquivo e afd vazio
// Pós-condição: afd preenchido
void read_afd(const char * filename, AFD * afd) {
    FILE * file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LENGTH];

    while (fgets(line, MAX_LENGTH, file) != NULL) {
        if (strstr(line, "alfabeto") != NULL) {
            getData(line, afd->alphabet, &(afd->alphabet_size));
        } else if (strstr(line, "estados") != NULL) {
            getData(line, afd->states, &(afd->states_size));
        } else if (strstr(line, "finais") != NULL) {
            getData(line, afd->final_states, &(afd->final_states_size));
        }
        else {
            // Linha de transição
            if (afd->transitions_size == 0) {
                afd->transitions = malloc(sizeof(Transition));
            } else {
                afd->transitions = realloc(afd->transitions, (afd->transitions_size + 1) * sizeof(Transition));
            }

            char current_state[MAX_STRING_LENGTH], next_state[MAX_STRING_LENGTH];
            char symbol;
            sscanf(line, "(%[^,],%c)= %s", current_state, &symbol, next_state);

            afd->transitions[afd->transitions_size].current_state = strdup(current_state);
            afd->transitions[afd->transitions_size].symbol = symbol;
            afd->transitions[afd->transitions_size].next_state = strdup(next_state);
            afd->transitions_size++;
        }
    }

    fclose(file);
}