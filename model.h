//
// Created by nikoly on 14/01/24.
//

#ifndef AFD_SIMULATOR_MODEL_H
#define AFD_SIMULATOR_MODEL_H

#define MAX_LENGTH 1000
#define MAX_STRING_LENGTH 10

typedef struct {
    char * current_state;
    char symbol;
    char * next_state;
} Transition;

#endif //AFD_SIMULATOR_MODEL_H
