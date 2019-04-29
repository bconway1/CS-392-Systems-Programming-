//
// Created by bconway on 4/1/19.
// “I pledge my honor that I have abided by the Stevens Honor System.” - Brereton Conway

#include "cs392_exec.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/wait.h>

#define NUMBER_OF_ARGV_WORDS 10
#define LENGTH_OF_ARGV_WORDS 20

//argv is pasted to execvp
static char** argv;

//allocate memory for argv
void cs392_exec_init(void){
    argv = malloc(NUMBER_OF_ARGV_WORDS * sizeof(char*));
    if(argv == NULL){
        perror("failed to allocate space for argv");
        exit(1);
    }
    for(int i = 0; i < NUMBER_OF_ARGV_WORDS; i++){
        argv[i] = malloc(LENGTH_OF_ARGV_WORDS * sizeof(char));
        if(argv[i] == NULL){
            perror("failed to allocate spac for argv");
        }
    }
    return;
}


//free argv memory
void free_memory_in_cs392_exec(void){
    for(int i = 0; i < NUMBER_OF_ARGV_WORDS; i++){
        free(argv[i]);
    }
    free(argv);
}


//strip input_line of newline character
void switch_newline_with_nullterm(char* str) {
    if((str == NULL) || (str[0] == '\0')) return;

    int i = 0;
    while (str[i] != '\n') {
        i++;
    }
    str[i] = '\0';
}

//parse input_line into argv
void parse_commands(char* input, char* argv[]){
    char* word;
    char* space = " ";
    int i = 0;
    switch_newline_with_nullterm(input);

    word = strtok(input, space);
    while(word != NULL){

        strcpy(argv[i],word);
        i++;
        word = strtok(NULL, space);
    }

    argv[i] = NULL;


}

//forks child that parses commands and executes them via execvp. If parent, then it waits for child to return
void fork_and_execute_command(char* input){


    pid_t process_id = fork();

    if(process_id == 0) {


        parse_commands(input, argv);
        int exec_error_flag = execvp(argv[0], argv);

        if (exec_error_flag == -1) {
            perror("execvp error");
        }
    }
    else if(process_id < 0){
        perror("fork did not work");
        exit(1);
    }
    else{
        wait(NULL);


    }

}
