//
// Created by bconway on 4/1/19.
// “I pledge my honor that I have abided by the Stevens Honor System.” - Brereton Conway

#include "cs392_signal.h"
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

static struct sigaction sigint_action;
static struct sigaction sigtstp_action;


//handler function for SIGINT(ctrl + c)
static void sigint_handler(int sig, siginfo_t *siginfo, void *context){
    printf("\nSIGINT Received \n");

}
//handler funtion for sigtstp (ctrl + z)
static void sigtstp_handler(int sig, siginfo_t *siginfo, void *context){
    printf("\nSIGTSTP Received \n");

}

//registers our signal handles for the two signals
void signal_handler_init(void){
    memset(&sigint_action, '\0', sizeof(sigint_action));
    memset(&sigtstp_action, '\0', sizeof(sigint_action));

    sigint_action.sa_sigaction = &sigint_handler;
    sigtstp_action.sa_sigaction = &sigtstp_handler;

    sigint_action.sa_flags = SA_SIGINFO;
    sigtstp_action.sa_flags = SA_SIGINFO;

    if(sigaction(SIGINT,&sigint_action, NULL) < 0){
        perror("sigaction: SIGNIT");
        exit(1);
    }
    if(sigaction(SIGTSTP,&sigtstp_action, NULL) < 0){
        perror("sigaction: SIGTSTP");
        exit(1);
    }

}
