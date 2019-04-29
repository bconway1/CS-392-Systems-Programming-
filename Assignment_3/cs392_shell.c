//“I pledge my honor that I have abided by the Stevens Honor System.” - Brereton Conway

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "cs392_log.h"
#include "cs392_signal.h"
#include "cs392_exec.h"

#define INPUT_LINE_BUFFER 256

int main() {
    /*init functions*/
    log_init();
    signal_handler_init();
    cs392_exec_init();

    //input string for commandline
    char * input_line = malloc(INPUT_LINE_BUFFER * sizeof(*input_line));
    //exit string
    char exit[] = "exit\n";

    while(1) {

        printf("cs392_shell $: ");
          //get input_line
         if (fgets(input_line, INPUT_LINE_BUFFER, stdin) != NULL) {
            //log command
             log_command(input_line);
             //if input_line == exit then terminate
             if(strcmp(input_line, exit) == 0) {
                // first close files and free memory
                 free(input_line);
                 close_log();
                 free_memory_in_cs392_exec();
                 return 1;
             }
             else{
               //fork a child to execute command
                 fork_and_execute_command(input_line);
             }




         }




     }

}
