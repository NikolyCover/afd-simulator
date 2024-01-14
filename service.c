//
// Created by nikoly on 14/01/24.
//

#include "model.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

void removeCommas(char *str) {
    int i, j = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ',') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

void read_afd(const char * filename, char * alphabet, char ** states, char *** final_states, Transition ** transitions, int * qtd_states) {
    FILE * file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    //lendo alfabeto
    fscanf(file, "alfabeto={%[^}]}", alphabet);
    removeCommas(alphabet);
    printf("aux: %s\n", alphabet);

    // Leitura dos estados
    fscanf(file, "estados={");
    *states = 0;
    while (fscanf(file, "%s", states[*qtd_states]) == 1) {
        removeCommas(states[*qtd_states]);
        printf("oi: %s", states[*qtd_states]);
        (*qtd_states)++;
    }

/*
    // Leitura dos estados
    fscanf(arq, "estados={");
    int i = 0;
    char estado[20];  // Ajuste o tamanho conforme necessário
    while (fscanf(arq, "%[^,}]%*[,}] ", estado) == 1) {
        *estados = realloc(*estados, (i + 1) * sizeof(char *));
        (*estados)[i] = strdup(estado);
        i++;
    }

    // Leitura dos estados finais
    fscanf(arq, "finais={");
    i = 0;
    while (fscanf(arq, "%[^,}]%*[,}] ", estado) == 1) {
        *estados_finais = realloc(*estados_finais, (i + 1) * sizeof(char *));
        (*estados_finais)[i] = strdup(estado);
        i++;
    }

    // Leitura das transições
    i = 0;
    *transicoes = malloc(sizeof(Transition));
    while (fscanf(arq, "(%[^,],%c)= %s ", estado, &(*transicoes)[i].symbol, estado) == 3) {
        (*transicoes)[i].current_state = strdup(estado);
        (*transicoes)[i].next_state = strdup(estado);
        i++;
        *transicoes = realloc(*transicoes, (i + 1) * sizeof(Transition));
    }

    *num_transicoes = i;*/

    fclose(file);
}