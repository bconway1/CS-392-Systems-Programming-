//
// Created by bconway on 4/1/19.
// “I pledge my honor that I have abided by the Stevens Honor System.” - Brereton Conway

#ifndef ASSIGNMENT_3_CS392_EXEC_H
#define ASSIGNMENT_3_CS392_EXEC_H

#include <unistd.h>

void cs392_exec_init(void);
void free_memory_in_cs392_exec(void);
void fork_and_execute_command(char* input);
#endif //ASSIGNMENT_3_CS392_EXEC_H
