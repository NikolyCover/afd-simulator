//
// Created by nikoly on 14/01/24.
//

#ifndef AFD_SIMULATOR_SERVICE_H
#define AFD_SIMULATOR_SERVICE_H
#include "model.h"

// Pega os dados (estados/alfabeto) de uma cadeia de caracteres (linha)
// Pré-condição: linha, array a ser preenchido com os dados e tamanho do array a ser preenchido
// Pós-condição: dados extraídos da linha no array e tamanho do array preenchido
void getData(char *line, char **array, int *size);

// Lê AFD de um arquivo
// Pré-condição: nome do arquivo e afd vazio
// Pós-condição: afd preenchido
void read_afd(const char * filename, AFD * afd);

#endif //AFD_SIMULATOR_SERVICE_H
