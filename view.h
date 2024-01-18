//
// Created by nikoly on 17/01/24.
//

#ifndef AFD_SIMULATOR_VIEW_H
#define AFD_SIMULATOR_VIEW_H

#include "model.h"
#include <stdio.h>

void show_afd(AFD afd);
void input_word(char * word);
void print_divider();
void show_result(int result);
void show_green_message(char * message);
void show_red_message(char * message);
void show_processing_step(char *curr_state, char * word);
void break_line();
void show_processing_header(char * word);

#endif //AFD_SIMULATOR_VIEW_H
