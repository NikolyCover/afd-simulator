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

typedef  struct  {
    char **alphabet;
    int alphabet_size;
    char **states;
    int states_size;
    char **final_states;
    int final_states_size;
    Transition *transitions;
    int transitions_size;
} AFD;

#endif //AFD_SIMULATOR_MODEL_H
