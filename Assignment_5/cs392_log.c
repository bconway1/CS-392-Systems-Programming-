//“I pledge my honor that I have abided by the Stevens Honor System.” -Brereton Conway

// Created by bconway on 5/5/19.
//

#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// opens or creates log file for appending and then logs the ip and port addresses
//addr and port must have their endianess changed
void cs392_socket_log(struct in_addr addr, unsigned short port){
    FILE* log_file = fopen("/home/student/share/Assignment_5/cs392_socket.log", "a");
    if(log_file == NULL){
        perror("error opening log file");
        exit(0);
    }
    if(fprintf(log_file, "%s %hu\n", inet_ntoa(addr), (unsigned short)ntohs(port)) < 0){
        perror("error appending file");
        exit(0);
    }
    fclose(log_file);
}
