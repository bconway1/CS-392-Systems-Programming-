//
// Created by bconway on 4/1/19.
// “I pledge my honor that I have abided by the Stevens Honor System.” - Brereton Conway

#include "cs392_log.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

static FILE* log_file;
//opens log file
void log_init(void){
    log_file = fopen("/home/student/share/Assignment_3/cs392_shell.log", "a");
    if(log_file == NULL){
        printf("cannot open log file\n");
    }
}

//appends command to log file
void log_command(char * command){
    fwrite(command, 1, strlen(command), log_file);
    fflush(log_file);
    if (ferror(log_file)) {
        printf("Cannot write to output file due to error %d\n", errno);
        exit(1);
    }

}
//closes file
void close_log(void){
    fclose(log_file);
}
